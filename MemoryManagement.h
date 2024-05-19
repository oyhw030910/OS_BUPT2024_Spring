#pragma once

#include<iostream>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<list>

# define PAGE_NUMBER 8 //ҳ��Ϊ8
# define FRAME_NUMBER 3 //֡��Ϊ3
# define PAGE_SIZE 1024 //ҳ��СΪ1024

using namespace std;

typedef map<int, int>Table;//<virID,phyID>ҳ֡��Ӧ��
typedef map<int, Table>PageTable;//<PID,TABLE>һ�����̶�Ӧһ��ҳ֡��Ӧ��
typedef struct VirMemoty {
	int virTable[PAGE_NUMBER][3];//�����ڴ���������PID��Ĭ��-1�������ڴ棬Ĭ��0����д�ڴ棬Ĭ��0��
	string virContent[PAGE_NUMBER];//�����ڴ�洢���ݣ�Ĭ��"*"��
};
typedef struct PhyMemory {
	int phyTable[FRAME_NUMBER]; //�����ڴ���������ҳ�ţ�Ĭ��-1��
	string phyContent[FRAME_NUMBER]; //�����ڴ���洢���ݣ�Ĭ��"*"��
};
typedef struct FileLocation {
	string fileName;//�ļ���
	int start;//��ʼ��ַ
	int end;//������ַ
};
PageTable pageTable;//ҳ��
VirMemoty virMemory;//�����ڴ�ʹ�����
PhyMemory phyMemory;//�����ڴ�ʹ�����
list<int> scheQueue; //���ȶ���

int FindPhyID(int _virID);//����ҳ�ţ����Ҷ�Ӧ��֡�ţ�����֡�Ż�-1
void InsertPage(int _virID,Table _table);//����ҳ�ţ���ҳ֡��Ӧ������µĹ���
void DeletePage(int _virID, Table _table);//����ҳ�ţ�ɾ��ҳ֡��Ӧ��Ĺ���
int TransformPage(int _address,Table _table);//���ݽ�����Ե�ַ��ת��Ϊ�ý�����Ե�ַ���ڵ�ҳ�ţ�����ҳ�Ż�-1��PageTable[pid]��
void ModifyPage(int _virID, int _phyID, Table _table, int _flag);//����ҳ�š�֡�ţ���ҳ�������������ڴ棻����_flagΪ1������_flagΪ0��_phyIDΪ-1
void InitializeMemory();//��ʼ�������ڴ�������ڴ�
int AllocMemory(int pid, int size);//��ҳ�洢�����ڴ棬����0��-1
int FreeMemory(int _pid);//���ݽ��̣��ͷŽ�����ռ�ڴ棬����0��-1
FileLocation WriteMemory(int _pid, string _context);//���ݽ��̺�д���ı���д���ڴ�
int CheckFault(int _pid, int _start, int _end);//����Ƿ�ȱҳ�жϣ�����0��-1

