#pragma once
#include<bits/stdc++.h>
using namespace std;

#include"process.h"
#include"MemoryManagement.h"


int getrand(int l,int r)
{
    return rand() /(r-l+1) +l;
}

int createP(int processsize,int processtime,int ct,int cid,int did,int dt,string fn,string inf)
{
    if(ct >= processtime || totalP >=maxprocess)
        return 0;
    CMD cmd={ct,cid,did,dt,fn,inf};
    process[totalP]={totalP,0,processsize,timer,0,processtime,0,processtime,cmd};
    totalP++;
    return 1;
}
int finishP(int PID)
{
    process[PID].state=OVER;
    //releasedevice(PID,-1);
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
    if(!AllocMemory(PID,process[PID].size))
        return 0;
    process[PID].state==RUNNING;
    return 1;
}
int runcmd(int PID, CMD cmd)
{
    int s=0;
    switch(cmd.cid)
    {
        case CREATEFILE:
            //int s=createfile(cmd.filename);
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
            //int s= deletefile(cmd.filename);
            if(!s)
            {
                
                //cout << "删除文件失败" << endl;
                
            }
            else
            {
                //cout << "删除文件成功" << endl;
            }
            break;
        case READFILE:
            break;
        case WRITEFILE:
            break;
        case APPLYDEVICE:
            //int s = acquiredevice(PID,cmd.object);
            if(!s)
            {
            //    raiseInterrupt(PID,1,0);
                return 0;
            }
            break;
        case RELEASEDEVICE:
            //int s = releasedevice(PID,cmd.object);
            break;

    }
    return 1;
}
int finishP(int PID)
{
    process[PID].state=OVER;
    Done_Process.push_back(PID);
    return 1;
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
    int res=Ready_Process.front();
    Ready_Process.pop();
    return res;
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
            if(!runP(runningpid))
            {
                //
            }
        }

        if(process[runningpid].command.time == process[runningpid].pasttime)
        {
            if(!runcmd(runningpid,process[runningpid].command))
            {
                blockP(runningpid);
                timer++;
                continue;
            }
            if(process[runningpid].command.cid==APPLYDEVICE)
            {
                process[runningpid].command.cid=RELEASEDEVICE;
                process[runningpid].command.time=process[runningpid].command.time+process[runningpid].command.devicetime;
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
