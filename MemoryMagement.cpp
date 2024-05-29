#include "MemoryManagement.h"

int FindPhyID(int _virID)
{
	for (int i = 0; i < FRAME_NUMBER; i++)
	{
		if (phyMemory.phyTable[i] == _virID)
		{
			return i;
		}
	}
	return -1;
}
Table InsertPage(int _virID, Table _table)
{
	_table.insert(pair<int, int>(_virID, -1));
	return _table;
}
Table DeletePage(int _virID, Table _table)
{
	_table.erase(_virID);
	return _table;
}
int TransformPage(int _address, Table _table)
{
	int pageNum = _address / PAGE_SIZE; //通过地址 / 页大小，求出地址在进程的第几页
	int pageSum = _table.size();//table的总页数
	//若地址所在页小于总页数，即在页表中
	if (pageNum < pageSum)
	{
		int i = 0;//循环变量
		int tmpTable[PAGE_NUMBER];//创建临时表，存储按顺序排列的页号
		map < int, int > ::iterator it;//创建一个迭代器
		//遍历table，将table中的页号按顺序填入临时表
		for (it = _table.begin(); it != _table.end(); ++it) {
			tmpTable[i] = it->first;
			i++;
		}
		return tmpTable[pageNum]; //返回地址所在页号
	}
	//若地址所在页不在页表中，返回-1
	else
		return -1;
}
Table ModifyPage(int _virID, int _phyID, Table _table, int _flag)
{
	//1为调入
	if (_flag == 1)
	{
		_table[_virID] = _phyID; //将页帧对应表中的页号与帧号关联
	}
	//-1为调出
	else if(_flag == 0)
	{
		_table[_virID] = -1; //将页帧对应表中页表对应帧号置为-1，即没有关联
	}
	return _table;
}
void InitializeMemory()
{
	int i, j;//循环变量
	//初始化虚拟内存
	for (i = 0; i < PAGE_NUMBER; i++) 
	{
		for (j = 0; j < 3; j++) 
		{
			if (j == 0) virMemory.virTable[i][j] = -1;
			if (j == 1) virMemory.virTable[i][j] = 0;
			if (j == 2) virMemory.virTable[i][j] = 0;
		}
		virMemory.virContent[i] = "*"; 
	}
	//初始化物理内存
	for (i = 0; i <FRAME_NUMBER; i++)
	{
		phyMemory.phyTable[i] = -1;
		for (int j = 0; j < 1024; j++)
		{
			phyMemory.phyContent[i] += "*";
		}
	}
}
int FreeMemory(int _pid)
{
	int i, j;//循环变量
	int flag = 0;
	for (i = 0; i < PAGE_NUMBER; i++)//遍历虚拟内存
	{
		//若虚拟内存被进程占用
		if (virMemory.virTable[i][0] == _pid)
		{
			flag = 1;//令flag置为1
			for (j = 0; j < FRAME_NUMBER; j++)//遍历物理内存
			{
				//若物理内存与被进程占用的虚拟内存对应
				if (phyMemory.phyTable[j] == i)
				{
					pageTable[_pid] = DeletePage(i, pageTable[_pid]);//将进程对应的页表删除
					scheQueue.remove(i);// 删除调度队列中的该页号
					//初始化物理内存
					phyMemory.phyTable[j] = -1;
					for (int j = 0; j < 1024; j++)
					{
						phyMemory.phyContent[i] += "*";
					}
				}
			}
			allocVirMemory -= virMemory.virTable[i][1];//已分配虚拟内存减去释放内存
			//初始化虚拟内存
			virMemory.virTable[i][0] = -1;
			virMemory.virTable[i][1] = 0;
			virMemory.virTable[i][2] = 0;
			virMemory.virContent[i] = "*";
		}
	}
	//若遍历虚拟内存后，发现虚拟内存未被进程占用
	if (flag == 0)
	{
		printf("释放内存失败，进程未占用内存\n");
		return -1;//释放内存失败，返回-1
	}
	pageTable.erase(_pid); //删除进程的页表
	printf("释放内存成功 pid:%d\n", _pid);
	return 0;//释放内存成功，返回0
}
int AllocVirMemory(int _pid, int _size)
{
	int i, j;//循环变量
	int tmpSize = _size;//进程还需分配的内存大小
	Table tmpTable;//临时页帧对应表
	for (i = 0; i < PAGE_NUMBER; i++)//遍历虚拟内存
	{
		//若为空
		if (virMemory.virTable[i][0] == -1)
		{
			virMemory.virTable[i][0] = _pid;//改为_pid，即分配给该进程
			//若该进程已经在虚拟内存中有页表了，直接使用该页表
			if (pageTable.count(_pid) > 0) 
			{
				tmpTable = pageTable[_pid]; //令临时页帧对应表为_pid的页帧对应表
			}
			//若该进程在虚拟内存中未有页表，创建新的页表
			else
			{
				pageTable.insert(pair<int, Table>(_pid, tmpTable));//创建新的页表
			}
			tmpTable = InsertPage(i, tmpTable);//在该页帧对应表插入新的关联
			pageTable[_pid] = tmpTable;//令_pid的页帧对应表为tmpTable
			//若进程所需的内存大小大于等于页大小
			if (tmpSize >= PAGE_SIZE)
			{
				virMemory.virTable[i][1] = PAGE_SIZE;//令虚拟内存对应的已用内存为页大小，即占满
				tmpSize -= PAGE_SIZE;//进程还所需内存减去页大小，即减去已分配内存
			}
			//若进程所需的内存大小小于页大小
			else
			{
				virMemory.virTable[i][1] = tmpSize;//令虚拟内存对应的已用内存为tmpSize
				tmpSize = 0;//进程所需内存为0，即分配完成
			}
		}
		//若进程所需内存为0，即分配完成
		if (tmpSize == 0)
		{
			allocVirMemory += _size;//修改已分配虚拟内存
			return 0;//分配内存成功，返回0
		}
	}
	//若遍历虚拟内存后，分配内存失败
	FreeMemory(_pid);//释放进程所占内存
	return -1;//分配内存失败，返回-1
}
int CheckFault(int _pid, int _start, int _end)
{
	Table tmpTable = pageTable[_pid];//临时页帧对应表
	int startVirID = TransformPage(_start, tmpTable);//相对起始地址的页号
	int endVirID = TransformPage(_end, tmpTable);//相对结束地址的页号
	//若相对起始和结束地址的页号都有对应的帧号，即没有缺页中断，返回0
	if (tmpTable[startVirID] != -1 && tmpTable[endVirID] != -1)
	{
		return 0;
	}
	//若不是，即缺页中断，返回-1
	return -1;
}
FileLocation  WriteVirMemory(int _pid, string _context)
{
	int i = 0;//循环变量
	int len = _context.length();//文本长度
	FileLocation tmpFileLocation;//临时文件地址
	Table tmpTable = pageTable[_pid];//临时页帧对应表
	list<int> tmpQueue;//临时队列
	map < int, int > ::iterator it;//迭代器
	//遍历页帧对应表，将页帧对应表中的页号按顺序填入队列
	for (it = tmpTable.begin(); it != tmpTable.end(); ++it)
	{
		tmpQueue.push_back(it->first);
		i++;
	}
	//若队列为空，写入失败，结束
	if (tmpQueue.empty()) 
	{
		printf("pid [%d] 写入内存失败\n", _pid);
		tmpFileLocation.start = -1;//将文件地址的起始地址置为-1，表示不存在
		tmpFileLocation.end = -1;//将文件地址的结束地址置为-1，表示不存在
		return tmpFileLocation;//返回文件地址
	}
	//若队列不为空
	int flag = 0;//是否找到第一页
	int start = 0;//首
	int end = 0;//尾
	int writenLen;//写入长度
	int spareLen;//空闲长度
	//当队列不为空且文本长度大于0
	while (!tmpQueue.empty() && len > 0)
	{
		int virID = tmpQueue.front();//令virID为队列第一个页号
		spareLen = virMemory.virTable[virID][1] - virMemory.virTable[virID][2];//页的空闲长度
		//若还有空余内存
		if (spareLen > 0)
		{
			//若调度队列不为空，查找调度队列中的所需页，初始化对应帧
			if (!scheQueue.empty()) 
			{
				list<int>::iterator it = find(scheQueue.begin(), scheQueue.end(), virID); // 查找调度队列中是否有要写入的页
				// 若调度队列中有要写入的页，将该页调用
				if (it != scheQueue.end())
				{
					int phyID = tmpTable[virID]; //根据页帧对应表找到页对应的帧
					phyMemory.phyTable[phyID] = -1;//将物理内存中的帧对应的页置为-1
					phyMemory.phyContent[phyID] = "*";//将物理内存的内容置为"*"
					tmpTable[virID] = -1;//将页帧对应表中的帧号置为-1
					pageTable[_pid] = tmpTable;//修改进程页帧对应表
					scheQueue.remove(virID);// 删除调度队列中的该页
				}
			}
			//若虚拟内存内容为空，删除默认内容
			if (virMemory.virContent[virID] == "*")
			{
				virMemory.virContent[virID].erase(0, 1);//删除默认内容，即"*"
			}
			//若flag为0，即首在写入之后就不再改变
			if (flag == 0)
			{
				start += virMemory.virTable[virID][2];//首加上已写内存
				flag = 1;//将flag置为1，首在写入后不再改变
			}
			end += virMemory.virTable[virID][2];//尾加上已写内存
			if (spareLen >= len)
			{
				writenLen = len;
				len = 0;
			}
			else
			{
				writenLen = spareLen;
				len -= spareLen;
			}
			virMemory.virContent[virID].append(_context, 0, writenLen);//在虚拟内存的内容中写入文本前长度为写入长度的字符串
			virMemory.virTable[virID][2] += writenLen;//已写内存加上写入长度
			_context.erase(0, writenLen);//删除文本已写入的内容
			end += writenLen;//尾加上写入长度
		}
		tmpQueue.pop_front();//写入的页出队列
		writenLen = 0;//写入长度置为0
	}
	tmpFileLocation.start = start;//文件地址的起始地址为首
	tmpFileLocation.end = end - 1;//文件地址的结束地址为尾
	//若队列为空，但文本长度仍大于0，即内存不够写入全部内容，结束
	if (len > 0) {
		printf("内存不够写入全部内容\n");
		return tmpFileLocation;//返回文件地址
	}
	//写入，结束
	return tmpFileLocation;//返回文件地址
}
string AccessPhyMemory(int _pid, int _start, int _end)
{
	int startInPage = _start % PAGE_SIZE;//相对起始地址的页内位置
	int endInPage = _end % PAGE_SIZE;//相对结束地址的页内位置
	Table tmpTable = pageTable[_pid];//页帧对应表
	int startVirID = TransformPage(_start, tmpTable);//相对起始地址的页号
	int endVirID = TransformPage(_end, tmpTable);//相对结束地址的页号
	//若找不到起始页或虚拟内存已用内存小于相对起始地址的页内位置，即访问内存失败
	if (startVirID == -1 || virMemory.virTable[startVirID][1] < startInPage)
	{
		printf("表示访问内存错误\n");
		return "-1";//返回"-1"
	}
	//若找到起始页且虚拟内存已用内存大于等于相对起始地址的页内位置，即访问内存成功
	else
	{
		tmpTable = LRU(startVirID, tmpTable);//
		//起始页和结束页不相同，即不在同一页
		if (startVirID != endVirID)
		{
			tmpTable = LRU(endVirID, tmpTable);//
		}
	}
	pageTable[_pid] = tmpTable;//修改页表
	int startPhyID = FindPhyID(startVirID);//起始页对应的帧号
	int endPhyID = FindPhyID(endVirID);//结束页对应的帧号
	int tmpPhyD;//临时帧号，循环变量
	string str;//用于存储物理内存的内容
	//若起始页和结束页为同一页
	if (startVirID == endVirID)
	{
		str = phyMemory.phyContent[startPhyID].substr(startInPage,  endInPage - startInPage);//物理内存的内容
	}
	//若起始页和结束页不为同一页
	else 
	{
		string strStart = phyMemory.phyContent[startPhyID].substr(startInPage, PAGE_SIZE - startInPage);//物理内存中起始帧的内容
		//for(tmpPhyD = startPhyID;)
		string strEnd = phyMemory.phyContent[endPhyID].substr(0, endInPage);//物理内存中结束帧的内容
		str = strStart + strEnd;//将两部分内容合并
	}
	return str;//返回物理内存里的内容
}
Table LRU(int _virID, Table _table)
{
	int phyID = FindPhyID(-1); //找到一个空闲帧
	//若页有对应的帧，不需要置换
	if (_table[_virID] != -1)
	{
		scheQueue.remove(_virID);//调度队列删除页
		scheQueue.push_back(_virID);//调度队列末尾添加页
	}
	//若页没有对应的帧，且有空闲帧
	else if (phyID != -1)
	{
		phyMemory.phyTable[phyID] = _virID;//修改物理内存中帧对应的页号
		usedPhyMemory += virMemory.virTable[_virID][1];//修改已使用物理内存
		scheQueue.push_back(_virID);//将页添加到调度队列末尾
		_table = ModifyPage(_virID, phyID, _table, 1);//将页调入物理内存
		phyMemory.phyContent[phyID] = virMemory.virContent[_virID];//将虚拟内存里的内容复制到物理内存
		pageFault++;//增加缺页次数
	}
	//若页没有对应的帧，且没有空闲帧
	else
	{
		int reVirID = scheQueue.front();//置换页
		int rePhyID = FindPhyID(reVirID); //置换帧
		int rePid = virMemory.virTable[reVirID][0];//置换页对应的pid
		Table tmpTable = pageTable[rePid];//置换进程的页帧对应表
		phyMemory.phyTable[rePhyID] = _virID;//修改物理内存中置换帧对应的页号
		usedPhyMemory -= virMemory.virTable[reVirID][1];//已使用物理内存减去置换出的页
		usedPhyMemory += virMemory.virTable[_virID][1];//已使用物理内存加上置换进的页
		pageFault++;//增加缺页次数
		tmpTable = ModifyPage(reVirID, 0, tmpTable, -1);//将置换出的页调出物理内存
		scheQueue.pop_front();//置换出的页出调度队列
		scheQueue.push_back(_virID);	//将置换进的页添加到调度队列末尾
		_table = ModifyPage(_virID, rePhyID, _table, 1);//将置换出的页调入物理内存
		phyMemory.phyContent[rePhyID] = virMemory.virContent[_virID];//将虚拟内存里的内容复制到物理内存
	}
	return _table;
}
void PrintMemory()
{
	cout << "虚拟内存"<< endl;
	for (int i = 0; i < PAGE_NUMBER; i++)
	{
		cout << "页号" << i <<" " << "pid：" << virMemory.virTable[i][0]<<" " << "已用内存：" << virMemory.virTable[i][1] << endl;
	}
	cout << "物理内存" << endl;
	for (int i = 0; i < FRAME_NUMBER; i++)
	{
		cout << "帧号：" << i << " " << "页号：" << phyMemory.phyTable[i] << endl;
	}
}
void PrintTable()
{
	cout << "页表" << endl;
	map < int, Table > ::iterator it;
	for (it = pageTable.begin(); it != pageTable.end(); ++it)
	{
		cout <<"pid :" << it->first << endl;
		Table tmpTable = it->second;
		map < int, int > ::iterator itt;
		for (itt = tmpTable.begin(); itt != tmpTable.end(); ++itt)
		{
			cout << "页号 :" << itt->first << " " << "帧号 :" << itt->second << endl;
		}
	}
}
