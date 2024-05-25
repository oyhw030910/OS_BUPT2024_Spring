#pragma once

#include<iostream>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<list>

# define PAGE_NUMBER 8 //页数为8
# define FRAME_NUMBER 3 //帧数为3
# define PAGE_SIZE 1024 //页大小为1024

using namespace std;

PageTable pageTable;//页表
VirMemoty virMemory;//虚拟内存使用情况
PhyMemory phyMemory;//物理内存使用情况
list<int> scheQueue; //调度队列
int allocVirMemory = 0; //已分配虚拟内存
int usedPhyMemory = 0; //已使用物理内存
int pageFault = 0; //缺页次数

typedef map<int, int>Table;//<virID,phyID>页帧对应表
typedef map<int, Table>PageTable;//<PID,TABLE>一个进程对应一个页帧对应表
typedef struct VirMemoty {
	int virTable[PAGE_NUMBER][3];//虚拟内存分配情况（PID，默认-1；已用内存，默认0；已写内存，默认0）
	string virContent[PAGE_NUMBER];//虚拟内存存储内容（默认"*"）
}VirMemoty;
typedef struct PhyMemory {
	int phyTable[FRAME_NUMBER]; //物理内存分配情况（页号，默认-1）
	string phyContent[FRAME_NUMBER]; //物理内存里存储内容（默认"*"）
}PhyMemory;
typedef struct FileLocation {
	string fileName;//文件名
	int start;//起始地址
	int end;//结束地址
}FileLocation;

int FindPhyID(int _virID);//根据页号，查找对应的帧号，返回帧号或-1
Table InsertPage(int _virID,Table _table);//根据页号，给页帧对应表插入新的关联
Table DeletePage(int _virID, Table _table);//根据页号，删除页帧对应表的关联
int TransformPage(int _address,Table _table);//根据进程相对地址，转换为该进程相对地址所在的页号，返回页号或-1
Table ModifyPage(int _virID, int _phyID, Table _table, int _flag);//根据页号、帧号，将页调入或调出物理内存；调入_flag为1；调出_flag为0，_phyID为-1
void InitializeMemory();//初始化虚拟内存和物理内存
int FreeMemory(int _pid);//根据进程，释放进程所占虚拟内存和物理内存，返回0或-1
int AllocVirMemory(int _pid, int _size);//根据进程大小，分页存储分配虚拟内存，返回0或-1
int CheckFault(int _pid, int _start, int _end);//根据起始和结束地址，检查是否缺页中断，即是否有对应帧，返回0或-1
FileLocation WriteVirMemory(int _pid, string _context);//根据进程和写入文本，写入虚拟内存，返回文件地址
string AccessPhyMemory(int _pid, int _start, int _end);//根据起始和结束地址，访问物理内存，返回内容或"-1"
Table LRU(int _virID, Table _table);//根据页号，执行LRU算法，返回修改后的页帧对应表
void PrintMemory();//打印虚拟内存和物理内存
void PrintTable();//打印页表
