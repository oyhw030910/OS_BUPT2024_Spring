#pragma once
enum InterruptType {
	timer,
	IO,
	paging,
	UI
};//�ж����ͣ�����raiseInterruptʱ������ĵ�һ�������������Լ��жϵ�����ѡ��
void raiseInterrupt(InterruptType type, int priority);//�����жϣ���ָ���ж����ȼ��İ汾
void raiseInterrupt(InterruptType type);//�����жϣ���ָ�����ȼ�(��ʹ��Ĭ�����ȼ�)
void initTable();//��ʼ����������������ʱ���ã�����ģ�鲻��ʹ��