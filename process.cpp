#include<bits/stdc++.h>
using namespace std;
#include"process.h"

int createP(int processsize,int processtime,int ct,int cid,int did,int dt,string fn,string inf)
{
    if(ct >= processtime || totalP >=maxprocess)
        return 0;
    CMD cmd={ct,cid,did,dt,fn,inf};
    process[totalP]={totalP,CREATING,processsize,timer,0,processtime,0,processtime,cmd};
    process[totalP].state=READY;
    Ready_Process.push(totalP);
    totalP++;
    return 1;
}
int finishP(int PID)
{
    process[PID].state=OVER;
    //FreeMemory(PID);
    //releasedevice(PID,-1);
    Done_Process.push_back(PID);
    return 1;
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
int suspendP(int PID)//使进程由运行态变为就绪态
{
    if(PID >= totalP || process[PID].state!=RUNNING || PID <0)
    {
        cout << "Errorsuspend\n" << endl;
        return 0;
    }
    process[PID].state=READY;
    Ready_Process.push(PID);
    return 1;
}
int runP(int PID)//使进程从就绪态变为运行态
{
    if(PID >= totalP || process[PID].state!=READY)
    {
        return 0;
    }
    //if(!AllocMemory(PID,process[PID].size))
    //    return 0;
    process[PID].state=RUNNING;
    return 1;
}

int runcmd(int PID, CMD cmd)
{
    int s=0;
    switch(cmd.commandid)
    {
        case CREATEFILE:
            cout << "createfile\n";
            break;
        case DELETEFILE:
            cout << "deletefile\n";
            break;
        case READFILE:
            cout << "readfile\n";
            break;
        case WRITEFILE:
            cout << "writefile\n";
            break;
        case APPLYDEVICE:
            cout << "applydevice\n";
            // int res = applydevice(PID,cmd.deviceid);
            // if(!res)
            // return 0;
            break;
        case RELEASEDEVICE:
            cout << "releasedevice\n";
            //int s = releasedevice(PID,cmd.object);
            break;

    }
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
        return -1;
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
    printf("ID: %d state:%d\n\
        needtime: %d pasttime:%d size:%d\n\
        commandid: %d\n",p.pid,p.state,p.needtime,p.pasttime,p.size,
        p.command.commandid);
    if(p.command.commandid == 5)
    {
        cout << p.command.deviceid << endl << endl;
    }
    else if(p.command.commandid <=4)
    {
        cout << p.command.filename << endl << endl;
    }
    return;
}
void initialize_process()
{
    int ps;
    ifstream filein;
    filein.open("presetprocess.txt",ios::in);
    if(!filein)
    {
        cout << "open_P_file_error\n";
        return;
    }
    filein >> ps;
    int psz,pt,ct,cid=0;
    int did,dt;
    string fname,fin;
    while(ps--)
    {
        filein >> psz >> pt >> ct >> cid;
        if (cid >=1 && cid <=3)
        {
            filein >> fname;
        }
        if(cid ==4)
        {
            filein >> fname >> fin;
        }
        else if(cid ==5)
        {
            
            filein >> did >> dt;
        }
        createP(psz,pt,ct,cid,did,dt,fname,fin);
    }
    filein.close();
}




void CPU()
{
    int runningpid=-1;
    char ch='q';
    while(1)
    {
        cout << "beginning" << endl;
        cin >> ch;
        if(ch=='q')
        {
            break;
        }
        else if(ch=='b')
        {
            suspendP(runningpid);
            runningpid=-1;
        }
        else if(ch=='c')
        {
            cout << "continue" << endl;
        } 
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
        cout << "Time: "  << timer << " PID: " <<runningpid << endl << endl;
        if(process[runningpid].command.commandtime == process[runningpid].pasttime)
        {
            cout << "command of PID " << runningpid<< endl;
            if(!runcmd(runningpid,process[runningpid].command))
            {
                blockP(runningpid);
                timer++;
                continue;
            }
            if(process[runningpid].command.commandid==APPLYDEVICE)
            {
                process[runningpid].command.commandid=RELEASEDEVICE;
                process[runningpid].command.commandtime+=+process[runningpid].command.devicetime;
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
        timer++;
    }
}
