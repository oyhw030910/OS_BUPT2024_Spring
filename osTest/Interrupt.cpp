#include<queue>
#include<iostream>
#include<vector>
using namespace std;

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
		bool compare(InterruptVector a,InterruptVector b) {
			return a.getPriority() < b.getPriority();
		}//�Ƚ����ȼ�
	};
	InterruptVector(InterruptType type,int priority) {
		this->type = type;
		this->priority = priority;
	}
	void handler() {
		InterruptVectorTable[type]();
	};//��Ӧ�������
	int getPriority() {
		return priority;
	}
	InterruptType getType() {
		return type;
	}
};

int DefaultPriority[tableSize];
vector<void(*)()> InterruptVectorTable;
priority_queue<InterruptVector, vector<InterruptVector>,InterruptVector::comparator> InterruptQueue;//�������ж϶���

void initTable() {
	//TODO ��ʼ���жϴ�������ַ

	DefaultPriority[0] = 1;
	DefaultPriority[1] = 2;
	DefaultPriority[2] = 3;
	DefaultPriority[3] = 4;
}//��ʼ���ж�������

void handler() {
	for (int i = 0; i < InterruptQueue.size(); i++) {
		InterruptVector v = InterruptQueue.top();
		InterruptQueue.pop();
		v.handler();
	}

}//���崦�����������жϣ�ִ����Ӧ�Ĵ���

//�����жϣ�ѹ���ж϶�����
void raiseInterrupt(InterruptType type) {
	raiseInterrupt(type, DefaultPriority[type]);
}

void raiseInterrupt(InterruptType type, int priority) {
	InterruptVector  v = InterruptVector(type, priority);
	InterruptQueue.push(v);
	isOff = true;
	handler();
	isOff = true;
}