#pragma once
#include<bits/stdc++.h>
using namespace std;

#define NOCMD 0
#define CREATEFILE 1  //创建文件
#define DELETEFILE 2  //删除文件
#define READFILE 3 //读文件
#define WRITEFILE 4 //写文件
#define APPLYDEVICE 5	//申请设备
#define RELEASEDEVICE 6 //释放设备

#define CREATING 0
#define READY 1
#define RUNNING 2
#define BLOCKED 3
#define OVER 4

struct CMD{
    int commandtime;// 执行指令的时间
    int commandid;//指令编号
    int deviceid;//对象编号，如调用的设备，唤醒的进程等
	int devicetime;//使用设备的时间
    string filename;//操作的文件名
	string infile;//文件操作的字符串
};

struct PCB {
	int pid;//进程ID
	int state; //进程状态，阻塞，运行等
	int size;// 进程所需内存
	int arrivetime; // 进程到达时间
	int finishtime; // 进程结束时间
	int needtime; // 进程总共需要运行的时间
	int pasttime;// 进程已经运行过的时间
	int remaintime; // 进程还需运行的时间
	CMD command; // 需要执行的指令
};




const int maxprocess=100;
int timer=0;
int totalP=0;

PCB process[maxprocess];
vector <int> Done_Process;//存储已经结束的PCB信息
queue <int> Ready_Process;//存储就绪态的PCB信息
vector <int> Blocked_Process;//存储阻塞的PCB信息

int createP(int processsize,int processtime,int ct,int cid,int did,
			int dt,string fn,string inf);//创建进程，返回1创建成功，0失败
int blockP(int PID); //进程因为中断等问题阻塞，由运行态（或就绪态）变为阻塞态
int wakeupP(int PID);//由阻塞态变为就绪态
int suspendP(int PID);//使进程由运行态变为就绪态
int runP(int PID);//使进程从就绪态变为运行态
int runcmd(int PID, CMD cmd);//执行某个进程的一个指令
int finishP(int PID);//进程运行结束
int findnextprocess();
int FCFS();//使用FCFS算法进行进程调度
void outPinfo(PCB p);
void initialize_process();
