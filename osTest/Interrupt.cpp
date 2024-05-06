#include<queue>
#include<iostream>
#include<vector>

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
		bool compare(InterruptVector b);//比较优先级
	};
	void handler();//相应处理程序
};

InterruptVector InterruptVectorTable[tableSize];
std::priority_queue<InterruptVector, vector<InterruptVector>,InterruptVector::comparator> queue;//待处理中断队列

void initTable();//初始化中断向量表

void handler(InterruptType type);//具体处理函数，接收中断，执行相应的处理

void raiseInterrupt(InterruptType type)//接收中断，压入中断队列中