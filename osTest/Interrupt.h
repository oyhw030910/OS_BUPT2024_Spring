#pragma once
enum InterruptType {
	timer,
	IO,
	paging,
	UI
};//中断类型，调用raiseInterrupt时，传入的第一个参数，依据自己中断的类型选择
void raiseInterrupt(InterruptType type, int priority);//引起中断，可指定中断优先级的版本
void raiseInterrupt(InterruptType type);//引起中断，不指定优先级(将使用默认优先级)
void initTable();//初始化，在主函数启动时调用，其它模块不许使用