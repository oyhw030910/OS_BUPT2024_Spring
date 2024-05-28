#include<queue>
#include<iostream>
#include<vector>
using namespace std;


struct C {
	void timerFun() {
		cout << "时间片中断处理" << endl;
	}
	void IOFun() {
		cout << "IO中断处理" << endl;
	}
	void pagingFun() {
		cout << "缺页中断处理" << endl;
	}
	void UIFun() {
		cout << "UI中断处理" << endl;
	}
};


typedef void (C::* pFunc)();
const int tableSize = 4;
bool isOff = false;//是否关中断
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
	int priority;//优先级
public:
	
	InterruptVector(InterruptType type,int priority) {
		this->type = type;
		this->priority = priority;
	}
	void handler() {
		C c;
		(c.*InterruptVectorTable[type])();
		//cout << "正在处理中断" << endl;
	};//相应处理程序
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
	}//比较优先级
};
priority_queue<InterruptVector, vector<InterruptVector>, comparator> InterruptQueue;//待处理中断队列




void initTable() {
	//TODO 初始化中断处理函数地址
	InterruptVectorTable[0] = &C::timerFun;
	InterruptVectorTable[1] = &C::IOFun;
	InterruptVectorTable[2] = &C::pagingFun;
	InterruptVectorTable[3] = &C::UIFun;



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


