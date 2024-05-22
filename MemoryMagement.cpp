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
void InsertPage(int _virID, Table _table)
{
	_table.insert(pair<int, int>(_virID, -1));
}
void DeletePage(int _virID, Table _table)
{
	_table.erase(_virID);
}
int TransformPage(int _address, Table _table)
{
	int pageNum = _address / PAGE_SIZE; //ͨ����ַ / ҳ��С�������ַ�ڽ��̵ĵڼ�ҳ
	int pageSum = _table.size();//table����ҳ��
	//����ַ����ҳС����ҳ��������ҳ����
	if (pageNum < pageSum)
	{
		int i = 0;//ѭ������
		int tmpTable[PAGE_NUMBER];//������ʱ���洢��˳�����е�ҳ��
		map < int, int > ::iterator it;//����һ��������
		//����table����table�е�ҳ�Ű�˳��������ʱ��
		for (it = _table.begin(); it != _table.end(); ++it) {
			tmpTable[i] = it->first;
			i++;
		}
		return tmpTable[pageNum]; //���ص�ַ����ҳ��
	}
	//����ַ����ҳ����ҳ���У�����-1
	else
		return -1;
}
void ModifyPage(int _virID, int _phyID, Table _table, int _flag)
{
	//1Ϊ����
	if (_flag == 1)
	{
		_table[_virID] = _phyID; //��ҳ֡��Ӧ���е�ҳ����֡�Ź���
	}
	//-1Ϊ����
	else if(_flag == 0)
	{
		_table[_virID] = -1; //��ҳ֡��Ӧ����ҳ���Ӧ֡����Ϊ-1����û�й���
	}
}
void InitializeMemory()
{
	int i, j;//ѭ������
	//��ʼ�������ڴ�
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
	//��ʼ�������ڴ�
	for (i = 0; i <FRAME_NUMBER; i++)
	{
		phyMemory.phyTable[i] = -1;
		phyMemory.phyContent[i] = "*";
	}
}
int FreeMemory(int _pid)
{
	int i, j;//ѭ������
	int flag = 0;
	for (i = 0; i < PAGE_NUMBER; i++)//���������ڴ�
	{
		//�������ڴ汻����ռ��
		if (virMemory.virTable[i][0] == _pid)
		{
			flag = 1;//��flag��Ϊ1
			for (j = 0; j < FRAME_NUMBER; j++)//���������ڴ�
			{
				//�������ڴ��뱻����ռ�õ������ڴ��Ӧ
				if (phyMemory.phyTable[j] == i)
				{
					DeletePage(i, pageTable[_pid]);//�����̶�Ӧ��ҳ��ɾ��
					scheQueue.remove(i);// ɾ�����ȶ����еĸ�ҳ��
					//��ʼ�������ڴ�
					phyMemory.phyTable[j] = -1;
					phyMemory.phyContent[j] = "*";
				}
			}
			allocVirMemory -= virMemory.virTable[i][0];//�ѷ��������ڴ��ȥ�ͷ��ڴ�
			//��ʼ�������ڴ�
			virMemory.virTable[i][0] = -1;
			virMemory.virTable[i][1] = 0;
			virMemory.virTable[i][2] = 0;
			virMemory.virContent[i] = "*";
		}
	}
	//�����������ڴ�󣬷��������ڴ�δ������ռ��
	if (flag == 0)
	{
		printf("�ͷ��ڴ�ʧ�ܣ�����δռ���ڴ�\n");
		return -1;//�ͷ��ڴ�ʧ�ܣ�����-1
	}
	pageTable.erase(_pid); //ɾ�����̵�ҳ��
	printf("�ͷ��ڴ�ɹ� pid:%d\n", _pid);
	return 0;//�ͷ��ڴ�ɹ�������0
}
int AllocVirMemory(int _pid, int _size)
{
	int i, j;//ѭ������
	int tmpSize = _size;//���̻��������ڴ��С
	Table tmpTable;//��ʱҳ֡��Ӧ��
	for (i = 0; i < PAGE_NUMBER; i++)//���������ڴ�
	{
		//��Ϊ��
		if (virMemory.virTable[i][0] == -1)
		{
			virMemory.virTable[i][0] = _pid;//��Ϊ_pid����������ý���
			//���ý����Ѿ��������ڴ�����ҳ���ˣ�ֱ��ʹ�ø�ҳ��
			if (pageTable.count(_pid) > 0) 
			{
				tmpTable = pageTable[_pid]; //����ʱҳ֡��Ӧ��Ϊ_pid��ҳ֡��Ӧ��
			}
			//���ý����������ڴ���δ��ҳ�������µ�ҳ��
			else
			{
				pageTable.insert(pair<int, Table>(_pid, tmpTable));//�����µ�ҳ��
			}
			InsertPage(i, tmpTable);//�ڸ�ҳ֡��Ӧ������µĹ���
			pageTable[_pid] = tmpTable;//��_pid��ҳ֡��Ӧ��ΪtmpTable
			//������������ڴ��С���ڵ���ҳ��С
			if (tmpSize >= PAGE_SIZE)
			{
				virMemory.virTable[i][1] = PAGE_SIZE;//�������ڴ��Ӧ�������ڴ�Ϊҳ��С����ռ��
				tmpSize -= PAGE_SIZE;//���̻������ڴ��ȥҳ��С������ȥ�ѷ����ڴ�
			}
			//������������ڴ��СС��ҳ��С
			else
			{
				virMemory.virTable[i][1] = tmpSize;//�������ڴ��Ӧ�������ڴ�ΪtmpSize
				tmpSize = 0;//���������ڴ�Ϊ0�����������
			}
		}
		//�����������ڴ�Ϊ0�����������
		if (tmpSize == 0)
		{
			allocVirMemory += _size;//�޸��ѷ��������ڴ�
			return 0;//�����ڴ�ɹ�������0
		}
	}
	//�����������ڴ�󣬷����ڴ�ʧ��
	FreeMemory(_pid);//�ͷŽ�����ռ�ڴ�
	return -1;//�����ڴ�ʧ�ܣ�����-1
}
int CheckFault(int _pid, int _start, int _end)
{
	Table tmpTable = pageTable[_pid];//��ʱҳ֡��Ӧ��
	int startVirID = TransformPage(_start, tmpTable);//�����ʼ��ַ��ҳ��
	int endVirID = TransformPage(_end, tmpTable);//��Խ�����ַ��ҳ��
	//�������ʼ�ͽ�����ַ��ҳ�Ŷ��ж�Ӧ��֡�ţ���û��ȱҳ�жϣ�����0
	if (tmpTable[startVirID] != -1 && tmpTable[endVirID] != -1)
	{
		return 0;
	}
	//�����ǣ���ȱҳ�жϣ�����-1
	return -1;
}
FileLocation  WriteVirMemory(int _pid, string _context)
{
	int i = 0;//ѭ������
	int len = _context.length();//�ı�����
	FileLocation tmpFileLocation;//��ʱ�ļ���ַ
	Table tmpTable = pageTable[_pid];//��ʱҳ֡��Ӧ��
	list<int> tmpQueue;//��ʱ����
	map < int, int > ::iterator it;//������
	//����ҳ֡��Ӧ����ҳ֡��Ӧ���е�ҳ�Ű�˳���������
	for (it = tmpTable.begin(); it != tmpTable.end(); ++it)
	{
		tmpQueue.push_back(it->first);
		i++;
	}
	//������Ϊ�գ�д��ʧ�ܣ�����
	if (tmpQueue.empty()) 
	{
		printf("pid [%d] д���ڴ�ʧ��\n", _pid);
		tmpFileLocation.start = -1;//���ļ���ַ����ʼ��ַ��Ϊ-1����ʾ������
		tmpFileLocation.end = -1;//���ļ���ַ�Ľ�����ַ��Ϊ-1����ʾ������
		return tmpFileLocation;//�����ļ���ַ
	}
	//�����в�Ϊ��
	int flag = 0;//�Ƿ��ҵ���һҳ
	int start = 0;//��
	int end = 0;//β
	int writenLen;//д�볤��
	int spareLen;//���г���
	//�����в�Ϊ�����ı����ȴ���0
	while (!tmpQueue.empty() && len > 0)
	{
		int virID = tmpQueue.front();//��virIDΪ���е�һ��ҳ��
		spareLen = virMemory.virTable[virID][1] - virMemory.virTable[virID][2];//ҳ�Ŀ��г���
		//�����п����ڴ�
		if (spareLen > 0)
		{
			//�����ȶ��в�Ϊ�գ����ҵ��ȶ����е�����ҳ����ʼ����Ӧ֡
			if (!scheQueue.empty()) 
			{
				list<int>::iterator it = find(scheQueue.begin(), scheQueue.end(), virID); // ���ҵ��ȶ������Ƿ���Ҫд���ҳ
				// �����ȶ�������Ҫд���ҳ������ҳ����
				if (it != scheQueue.end())
				{
					int phyID = tmpTable[virID]; //����ҳ֡��Ӧ���ҵ�ҳ��Ӧ��֡
					phyMemory.phyTable[phyID] = -1;//�������ڴ��е�֡��Ӧ��ҳ��Ϊ-1
					phyMemory.phyContent[phyID] = "*";//�������ڴ��������Ϊ"*"
					tmpTable[virID] = -1;//��ҳ֡��Ӧ���е�֡����Ϊ-1
					pageTable[_pid] = tmpTable;//�޸Ľ���ҳ֡��Ӧ��
					scheQueue.remove(virID);// ɾ�����ȶ����еĸ�ҳ
				}
			}
			//�������ڴ�����Ϊ�գ�ɾ��Ĭ������
			if (virMemory.virContent[virID] == "*")
			{
				virMemory.virContent[virID].erase(0, 1);//ɾ��Ĭ�����ݣ���"*"
			}
			//��flagΪ0��������д��֮��Ͳ��ٸı�
			if (flag == 0)
			{
				start += virMemory.virTable[virID][2];//�׼�����д�ڴ�
				flag = 1;//��flag��Ϊ1������д����ٸı�
			}
			end += virMemory.virTable[virID][2];//β������д�ڴ�
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
			virMemory.virContent[virID].append(_context, 0, writenLen);//�������ڴ��������д���ı�ǰ����Ϊд�볤�ȵ��ַ���
			virMemory.virTable[virID][2] += writenLen;//��д�ڴ����д�볤��
			_context.erase(0, writenLen);//ɾ���ı���д�������
			end += writenLen;//β����д�볤��
		}
		tmpQueue.pop_front();//д���ҳ������
		writenLen = 0;//д�볤����Ϊ0
	}
	tmpFileLocation.start = start;//�ļ���ַ����ʼ��ַΪ��
	tmpFileLocation.end = end - 1;//�ļ���ַ�Ľ�����ַΪβ
	//������Ϊ�գ����ı������Դ���0�����ڴ治��д��ȫ�����ݣ�����
	if (len > 0) {
		printf("�ڴ治��д��ȫ������\n");
		return tmpFileLocation;//�����ļ���ַ
	}
	//д�룬����
	return tmpFileLocation;//�����ļ���ַ
}
string AccessPhyMemory(int _pid, int _start, int _end)
{
	int startInPage = _start % PAGE_SIZE;//�����ʼ��ַ��ҳ��λ��
	int endInPage = _end % PAGE_SIZE;//��Խ�����ַ��ҳ��λ��
	Table tmpTable = pageTable[_pid];//ҳ֡��Ӧ��
	int startVirID = TransformPage(_start, tmpTable);//�����ʼ��ַ��ҳ��
	int endVirID = TransformPage(_end, tmpTable);//��Խ�����ַ��ҳ��
	//���Ҳ�����ʼҳ�������ڴ������ڴ�С�������ʼ��ַ��ҳ��λ�ã��������ڴ�ʧ��
	if (startVirID == -1 || virMemory.virTable[startVirID][1] < startInPage)
	{
		printf("��ʾ�����ڴ����\n");
		return "-1";//����"-1"
	}
	//���ҵ���ʼҳ�������ڴ������ڴ���ڵ��������ʼ��ַ��ҳ��λ�ã��������ڴ�ɹ�
	else
	{
		tmpTable = LRU(startVirID, tmpTable);//
		//��ʼҳ�ͽ���ҳ����ͬ��������ͬһҳ
		if (startVirID != endVirID)
		{
			tmpTable = LRU(endVirID, tmpTable);//
		}
	}
	pageTable[_pid] = tmpTable;//�޸�ҳ��
	int startPhyID = FindPhyID(startVirID);//��ʼҳ��Ӧ��֡��
	int endPhyID = FindPhyID(endVirID);//����ҳ��Ӧ��֡��
	int tmpPhyD;//��ʱ֡�ţ�ѭ������
	string str;//���ڴ洢�����ڴ������
	//����ʼҳ�ͽ���ҳΪͬһҳ
	if (startVirID == endVirID)
	{
		str = phyMemory.phyContent[startPhyID].substr(startInPage,  endInPage - startInPage);//�����ڴ������
	}
	//����ʼҳ�ͽ���ҳ��Ϊͬһҳ
	else 
	{
		string strStart = phyMemory.phyContent[startPhyID].substr(startInPage, PAGE_SIZE - startInPage);//�����ڴ�����ʼ֡������
		//for(tmpPhyD = startPhyID;)
		string strEnd = phyMemory.phyContent[endPhyID].substr(0, endInPage);//�����ڴ��н���֡������
		str = strStart + strEnd;//�����������ݺϲ�
	}
	return str;//���������ڴ��������
}
Table LRU(int _virID, Table _table)
{
	int phyID = FindPhyID(-1); //�ҵ�һ������֡
	//��ҳ�ж�Ӧ��֡������Ҫ�û�
	if (_table[_virID] != -1)
	{
		scheQueue.remove(_virID);//���ȶ���ɾ��ҳ
		scheQueue.push_back(_virID);//���ȶ���ĩβ���ҳ
	}
	//��ҳû�ж�Ӧ��֡�����п���֡
	else if (phyID != -1)
	{
		phyMemory.phyTable[phyID] = _virID;//�޸������ڴ���֡��Ӧ��ҳ��
		usedPhyMemory += virMemory.virTable[_virID][1];//�޸���ʹ�������ڴ�
		scheQueue.push_back(_virID);//��ҳ��ӵ����ȶ���ĩβ
		ModifyPage(_virID, phyID, _table, 1);//��ҳ���������ڴ�
		phyMemory.phyContent[phyID] = virMemory.virContent[_virID];//�������ڴ�������ݸ��Ƶ������ڴ�
		pageFault++;//����ȱҳ����
	}
	//��ҳû�ж�Ӧ��֡����û�п���֡
	else
	{
		int reVirID = scheQueue.front();//�û�ҳ
		int rePhyID = FindPhyID(reVirID); //�û�֡
		int rePid = virMemory.virTable[reVirID][0];//�û�ҳ��Ӧ��pid
		Table tmpTable = pageTable[rePid];//�û����̵�ҳ֡��Ӧ��
		phyMemory.phyTable[rePhyID] = _virID;//�޸������ڴ����û�֡��Ӧ��ҳ��
		usedPhyMemory -= virMemory.virTable[reVirID][1];//��ʹ�������ڴ��ȥ�û�����ҳ
		usedPhyMemory += virMemory.virTable[_virID][1];//��ʹ�������ڴ�����û�����ҳ
		pageFault++;//����ȱҳ����
		ModifyPage(reVirID, 0, tmpTable, -1);//���û�����ҳ���������ڴ�
		scheQueue.pop_front();//�û�����ҳ�����ȶ���
		scheQueue.push_back(_virID);	//���û�����ҳ��ӵ����ȶ���ĩβ
		ModifyPage(_virID, rePhyID, _table, 1);//���û�����ҳ���������ڴ�
		phyMemory.phyContent[rePhyID] = virMemory.virContent[_virID];//�������ڴ�������ݸ��Ƶ������ڴ�
	}
	return _table;
}
