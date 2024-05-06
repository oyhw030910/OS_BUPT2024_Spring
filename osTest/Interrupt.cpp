#include<queue>
#include<iostream>
#include<vector>
using namespace std;

const int tableSize = 4;
bool isOff = false;//是否关中断

enum InterruptType {
	timer,
	IO,
	paging,
	UI
};

class InterruptVector {
private:
	InterruptType type;
	int priority;//优先级
public:
	struct comparator {
		bool compare(InterruptVector a,InterruptVector b) {
			return a.getPriority() < b.getPriority();
		}//比较优先级
	};
	InterruptVector(InterruptType type,int priority) {
		this->type = type;
		this->priority = priority;
	}
	void handler() {
		InterruptVectorTable[type]();
	};//相应处理程序
	int getPriority() {
		return priority;
	}
	InterruptType getType() {
		return type;
	}
};

int DefaultPriority[tableSize];
vector<void(*)()> InterruptVectorTable;
priority_queue<InterruptVector, vector<InterruptVector>,InterruptVector::comparator> InterruptQueue;//待处理中断队列

void initTable() {
	//TODO 初始化中断处理函数地址

	DefaultPriority[0] = 1;
	DefaultPriority[1] = 2;
	DefaultPriority[2] = 3;
	DefaultPriority[3] = 4;
}//初始化中断向量表

void handler() {
	for (int i = 0; i < InterruptQueue.size(); i++) {
		InterruptVector v = InterruptQueue.top();
		InterruptQueue.pop();
		v.handler();
	}

}//具体处理函数，接收中断，执行相应的处理

//接收中断，压入中断队列中
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