#pragma once
#include<bits/stdc++.h>
using namespace std;

#include"process.h"
int timer=0;
int totalP=0;
extern int createfile(string str);
extern int deletefile(string str);
extern int acquiredevice(int pid, int device);
extern int releasedevice(int pid, int device);
extern void raiseInterrupt(int PID,int type,int priority);
int getrand(int l,int r)
{
    return rand() /(r-l+1) +l;
}
int createP(string path)
{
    if(totalP==maxprocess)
    {
        return 0;
    }
    int id = totalP++;
    process[id].pid=id;
    process[id].size=getrand(1,MAXSPACE);
    process[id].arrivetime=timer;
    process[id].needtime=process[id].remaintime=getrand(1,10);
    //分配内存
    return 1;
}
int createP(int sz,int tm,int cmdnum,CMD cmd)
{
    if(totalP==maxprocess)
    {
        return 0;
    }
    if(cmd.time>tm)
    {
        return 0;
    }
    int id = totalP++;
    process[id].size=sz;
    process[id].needtime=process[id].remaintime=tm;
    process[id].command=cmd;
    return 1;
}
int finishP(int PID)
{
    process[PID].state=OVER;
    releasedevice(PID,-1);
    Done_Process.push_back(PID);
}
int wakeupP(int PID)//由阻塞态变为就绪态
{
    if(PID >= totalP || process[PID].state!=BLOCKED)
    {
        return 0;
    }
    //要添加检测内存够不够的功能
    process[PID].state=READY;
    for(vector<int> :: iterator it = Blocked_Process.begin(); it!=Blocked_Process.end();it++)
    {
        if(*it==PID)
        {
            Blocked_Process.erase(it);
            break;
        }
    }
    return 1;
}
int suspendP(int PID, int address)//使进程由运行态变为就绪态
{
    if(PID >= totalP || process[PID].state!=RUNNING)
    {
        return 0;
    }
    process[PID].state=READY;
    Ready_Process.push(PID);
}
int runP(int PID)//使进程从就绪态变为运行态
{
    if(PID >= totalP || process[PID].state!=READY)
    {
        return 0;
    }
    
    process[PID].state==RUNNING;
}
int runcmd(int PID, CMD cmd)
{
    switch(cmd.cid)
    {
        case CREATEFILE:
            int s=createfile(cmd.filename);
            if(!s)
            {
                //cout << "创建文件失败" << endl;
            }
            else
            {
                //cout << "创建文件成功" << endl;
            }
            break;
        case DELETEFILE:
            int s= deletefile(cmd.filename);
            if(!s)
            {
                
                //cout << "删除文件失败" << endl;
                
            }
            else
            {
                //cout << "删除文件成功" << endl;
            }
            break;
        case APPLYDEVICE:
            int s = acquiredevice(PID,cmd.object);
            if(!s)
            {
                raiseInterrupt(PID,1,0);
            }
            break;
        case RELEASEDEVICE:
            int s = releasedevice(PID,cmd.object);
            break;

    }

}
int finishP(int PID)
{
    process[PID].state=OVER;
    Done_Process.push_back(PID);
}
int findnextprocess()
{
    int res=FCFS();
    return res;
}
int FCFS()//使用FCFS算法进行进程调度
{
    if(Ready_Process.empty())
        return 0;
    return Ready_Process.front();
}
int blockP(int PID) //进程因为中断等问题阻塞，由运行态变为阻塞态
{
    if(PID < totalP || process[PID].state!=RUNNING)
    {
        return 0;
    }
    process[PID].state=BLOCKED;
    Blocked_Process.push_back(PID);
    return 1;
}
void outPinfo(PCB p)
{
    printf("ID: %d \n\
        needtime: %d\
        state:%d size:%d\n\
        \n\n\
        ",p.pid,p.state,p.size);
}
void presetprocess()
{
    int ps;
    ifstream filein;
    filein.open("setting.txt");
    filein >> ps;
    int sz,tm,cmds;
    int cmdc,tmc,objc;
    string infc;
    while(ps--)
    {
        filein >> sz >> tm >> cmds;
    }

}


void CPU()
{
    int runningpid=-1;
    while(1)
    {
        //进行插入进程，手动阻塞等操作
        
        if(runningpid == -1)
        {
            runningpid=findnextprocess();
            if(runningpid == -1)
            {
                cout << "没有需要运行的进程" << endl;
                timer++;
                continue;
            }
            runP(runningpid);
        }

        if(process[runningpid].cmdtime == process[runningpid].pasttime)
        {
            if(!runcmd(runningpid,process[runningpid].command))
            {
                //中断阻塞
                timer++;
                continue;
            }
            
        }
        process[runningpid].pasttime++;
        process[runningpid].remaintime--;
        if(process[runningpid].pasttime==process[runningpid].needtime)
        {
            finishP(runningpid);
            process[runningpid].finishtime=timer;
            runningpid=-1;
        }
    }
}