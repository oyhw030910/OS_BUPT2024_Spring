#include<queue>
#include<iostream>
#include<vector>

const int tableSize = 4;
bool isOff = false;//�Ƿ���ж�

enum InterruptType {
	timer,
	IO,
	paging,
	UI
};

class InterruptVector {
private:
	InterruptType type;
	int priority;//���ȼ�
public:
	struct comparator {
		bool compare(InterruptVector b);//�Ƚ����ȼ�
	};
	void handler();//��Ӧ�������
};

InterruptVector InterruptVectorTable[tableSize];
std::priority_queue<InterruptVector, vector<InterruptVector>,InterruptVector::comparator> queue;//�������ж϶���

void initTable();//��ʼ���ж�������

void handler(InterruptType type);//���崦�����������жϣ�ִ����Ӧ�Ĵ���

void raiseInterrupt(InterruptType type)//�����жϣ�ѹ���ж϶�����