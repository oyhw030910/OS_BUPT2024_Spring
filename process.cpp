#pragma once
using namespace std;
#include"process.h"
#include"memory.h"
#include"device.h"
#include"file.h"
#include"ui.h"
int min3(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= c)
        return b;
    return c;
}
int getrand(int left, int right)
{
    int s = rand();
    printf("%d %d\n", left, right);
    s = s % (right - left+1) + left;
    return s;
}
int createP(int processsize, int processtime, int ct, int cid, int did, int dt, string fn, string inf)
{
    if (ct >= processtime || totalP >= maxprocess)
        return 0;
    CMD cmd = { ct,cid,did,dt,fn,inf };
    process[totalP] = { totalP,CREATING,processsize,timer,0,processtime,0,processtime,cmd };
    process[totalP].state = READY;
    Ready_Process.push(totalP);
    totalP++;
    return 1;
}
int finishP(int PID)
{
    process[PID].state = OVER;
    FreeMemory(PID);
    release_device(PID, -1);
    memset(output, 0, sizeof(output));
    strcpy(output, "进程结束，释放内存和所有设备");
    changeOutput();
    Done_Process.push_back(PID);
    return 1;
}
int wakeupP(int PID)//由阻塞态变为就绪态
{
    process[PID].state = READY;
    for (vector<int> ::iterator it = Blocked_Process.begin(); it != Blocked_Process.end(); it++)
    {
        if (*it == PID)
        {
            Blocked_Process.erase(it);
            break;
        }
    }
    Ready_Process.push(PID);
    return 1;
}
int suspendP(int PID)//使进程由运行态变为就绪态
{
    if (PID >= totalP || process[PID].state != RUNNING || PID < 0)
    {
        cout << "Errorsuspend\n" << endl;
        return 0;
    }
    process[PID].state = READY;
    Ready_Process.push(PID);
    return 1;
}
int runP(int PID)//使进程从就绪态变为运行态
{
    if (PID >= totalP || process[PID].state != READY)
    {
        return 0;
    }
    if (AllocVirMemory(PID, process[PID].size) == -1)
        return 0;
    process[PID].state = RUNNING;
    return 1;
}

int runcmd(int PID, CMD cmd)
{
    int s = 1;
    switch (cmd.commandid)
    {
    case CREATEFILE:
        cout << "createfile\n";
        s = CreateTheFile(cmd.filename);
        memset(output, 0, sizeof(output));
        if (s)
            strcpy(output, "创建文件成功");
        else
            strcpy(output, "创建文件失败");
        break;
    case DELETEFILE:
        cout << "deletefile\n";
        s = DeleteTheFile(cmd.filename);
        memset(output, 0, sizeof(output));
        if (s)
            strcpy(output, "删除文件成功");
        else
            strcpy(output, "删除文件失败");
        break;
    case READFILE:
        cout << "readfile\n";
        memset(output, 0, sizeof(output));
        s = ReadFile(cmd.filename);

        break;
    case WRITEFILE:
        cout << "writefile\n";
        s = WriteFile(cmd.filename, cmd.infile);
        memset(output, 0, sizeof(output));
        if (s)
            strcpy(output, "写文件成功");
        else
            strcpy(output, "写文件失败");
        break;
    case APPLYDEVICE:
        cout << "applydevice\n";
        s = acquire_device(PID, cmd.deviceid);
        memset(output, 0, sizeof(output));
        if (s)
            strcpy(output, "申请设备成功");
        else
            strcpy(output, "申请设备失败");
        break;
    case RELEASEDEVICE:
        cout << "releasedevice\n";
        s = release_device(PID, cmd.deviceid);
        memset(output, 0, sizeof(output));
        if (s)
            strcpy(output, " 释放设备成功");
        else
            strcpy(output, " 释放设备失败");
        break;

    }
    printf("%s\n", output);
    changeOutput();
    return s;
}

int find_next_process()
{
    int res = FCFS();
    return res;
}
int FCFS()//使用FCFS算法进行进程调度
{
    if (Ready_Process.empty())
        return -1;
    int res = Ready_Process.front();
    Ready_Process.pop();
    return res;
}
int blockP(int PID) //进程因为中断等问题阻塞，由运行态变为阻塞态
{
    if (PID >= totalP || process[PID].state != RUNNING)
    {
        return 0;
    }
    process[PID].state = BLOCKED;
    Blocked_Process.push_back(PID);
    return 1;
}
void outPinfo(PCB p)
{
    printf("ID: %d state:%d\n\
needtime: %d pasttime:%d size:%d\n\
commandid: %d\n"
, p.pid, p.state, p.needtime, p.pasttime, p.size, p.command.commandid);
    if (p.command.commandid == 5)
    {
        cout << p.command.deviceid << endl << endl;
    }
    else if (p.command.commandid <= 4)
    {
        cout << p.command.filename << endl << endl;
    }
    return;
}
void init_process()
{
    int ps;
    ifstream filein;
    filein.open("presetprocess.txt", ios::in);
    if (!filein)
    {
        cout << "open_P_file_error\n";
        return;
    }
    filein >> ps;
    int psz, pt, ct, cid = 0;
    int did = 0, dt = 0;
    string fname = "", fin = "";
    while (ps--)
    {
        filein >> psz >> pt >> ct >> cid;
        did = dt = 0;
        fname = fin = "";
        if (cid == CREATEFILE || cid == DELETEFILE || cid == READFILE)
        {
            filein >> fname;
        }
        else if (cid == WRITEFILE)
        {
            filein >> fname >> fin;
        }
        else if (cid == APPLYDEVICE)
        {

            filein >> did >> dt;
        }
        createP(psz, pt, ct, cid, did, dt, fname, fin);
    }
    filein.close();
}

void letsgo()
{
    if (runningpid == -1)
    {
        runningpid = find_next_process();
        if (runningpid == -1)
        {
            printf("NO PROCESS TO RUN\n");
            timer++;
            return;
        }
        runP(runningpid);
    }
    printf("timer : %d PID %d\n", timer, runningpid);
    int start = getrand(0, process[runningpid].size - 1);
    int end = min3(process[runningpid].size - 1, ((start) / PAGE_SIZE + FRAME_NUMBER) * PAGE_SIZE-1, getrand(start, process[runningpid].size - 1));

    AccessPhyMemory(runningpid, start, end);
    if (process[runningpid].command.commandtime == process[runningpid].pasttime && process[runningpid].command.commandid != NOCMD)
    {
        printf("incmd\n");
        int s = runcmd(runningpid, process[runningpid].command);
        if (s) printf("success\n");
        else printf("fail\n");
        if (!s && process[runningpid].command.commandid == APPLYDEVICE)
        {
            blockP(runningpid);
            runningpid = -1;
            timer++;
            return;
        }
        if (process[runningpid].command.commandid == APPLYDEVICE)
        {
            process[runningpid].command.commandid = RELEASEDEVICE;
            process[runningpid].command.commandtime += +process[runningpid].command.devicetime;
        }
    }


    process[runningpid].pasttime++;
    process[runningpid].remaintime--;
    if (process[runningpid].pasttime == process[runningpid].needtime)
    {
        finishP(runningpid);
        process[runningpid].finishtime = timer;
        runningpid = -1;
    }
    timer++;
    return;
}

void user_suspend()
{
    suspendP(runningpid);
    runningpid = -1;
}
