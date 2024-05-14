#pragma once
#include<bits/stdc++.h>
using namespace std;
#define CREATEFILE 0  //创建文件
#define DELETEFILE 1  //删除文件
#define APPLYDEVICE 2	//申请设备
#define RELEASEDEVICE 3 //释放设备
//map中int表示的是进程的pid，便于查找
vector<int> Done_Process;//存储已经结束的PCB信息
queue <int> Ready_Process;//存储就绪态的PCB信息
vector <int> Blocked_Process;//存储阻塞的PCB信息
#define READY 1
#define RUNNING 2
#define BLOCKED 3
#define OVER 4

#define MAXSPACE 100 
const int maxprocess=100;
struct PCB {
	int pid;//进程ID
	int state; //进程状态，阻塞，运行等
	int size;//进程所需内存
	string path;//进程文件路径
	int arrivetime; // 进程到达时间
	int needtime; // 进程总共需要运行的时间
	int remaintime; // 进程还需运行的时间
	int finishtime; // 进程运行结束的时间
	stack<command> cmdstack; // 需要执行的指令
};

struct command{
    int time;// 执行指令的时间
    int cmdnum;//指令编号
    int objectnum;//对象编号，如调用的设备，唤醒的进程等
    string info;//一些别的字符串
};

void running(int PID);//一个一直在循环的函数，模拟正在执行进程的CPU
int createP(string path);//创建进程，返回1创建成功，0失败
int create(int sz,int tm,int cmdnum,command * cmdpt);
int blockP(int PID); //进程因为中断等问题阻塞，由运行态（或就绪态）变为阻塞态
int wakeupP(int PID);//由阻塞态变为就绪态
int suspendP(int PID, int address);//使进程由运行态变为就绪态
int runP(int PID);//使进程从就绪态变为运行态
int runcmd(int PID, command cmd);//执行某个进程的一个指令
int finishP(int PID);//进程运行结束
int FCFS();//使用FCFS算法进行进程调度
void outPinfo(PCB p);

PCB process[maxprocess];