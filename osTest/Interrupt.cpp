#include<queue>
#include<iostream>
#include<vector>
using namespace std;


struct C {
	void timerFun() {
		cout << "ʱ��Ƭ�жϴ���" << endl;
	}
	void IOFun() {
		cout << "IO�жϴ���" << endl;
	}
	void pagingFun() {
		cout << "ȱҳ�жϴ���" << endl;
	}
	void UIFun() {
		cout << "UI�жϴ���" << endl;
	}
};


typedef void (C::* pFunc)();
const int tableSize = 4;
bool isOff = false;//�Ƿ���ж�
pFunc InterruptVectorTable[tableSize];
int DefaultPriority[tableSize];

//vector<void(*)()> InterruptVectorTable;



enum InterruptType {
	timer,
	IO,
	paging,
	UI
};

class InterruptVector {
public:
	InterruptType type;
	int priority;//���ȼ�
public:
	
	InterruptVector(InterruptType type,int priority) {
		this->type = type;
		this->priority = priority;
	}
	void handler() {
		C c;
		(c.*InterruptVectorTable[type])();
		//cout << "���ڴ����ж�" << endl;
	};//��Ӧ�������
	int getPriority() {
		return priority;
	}
	InterruptType getType() {
		return type;
	}
};
struct comparator {
	bool operator()(const InterruptVector& a, const InterruptVector& b) {
		return a.priority < b.priority;
	}//�Ƚ����ȼ�
};
priority_queue<InterruptVector, vector<InterruptVector>, comparator> InterruptQueue;//�������ж϶���




void initTable() {
	//TODO ��ʼ���жϴ�������ַ
	InterruptVectorTable[0] = &C::timerFun;
	InterruptVectorTable[1] = &C::IOFun;
	InterruptVectorTable[2] = &C::pagingFun;
	InterruptVectorTable[3] = &C::UIFun;



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
void raiseInterrupt(InterruptType type, int priority) {
	InterruptVector  v = InterruptVector(type, priority);
	InterruptQueue.push(v);
	isOff = true;
	handler();
	isOff = true;
}
void raiseInterrupt(InterruptType type) {
	raiseInterrupt(type, DefaultPriority[type]);
}


