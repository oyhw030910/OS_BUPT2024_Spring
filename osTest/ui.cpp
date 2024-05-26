#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>//引用图形库头文件
#include <conio.h>
#include <string.h>
#include <time.h>
#include <easyx.h>
#include <tchar.h>
#include <iostream>
#include "process.h"
#include "file.h"
#include "device.h"
#include "MemoryManagement.h"
#pragma once
#include<bits/stdc++.h>
using namespace std;

#undef UNICODE
#undef _UNICODE
/*struct MOUSEMSG
{
    UINT uMsg;				 //当前鼠标消息
        bool mkCtrl;			 //Ctrl 键是否按下
        bool mkShift;			 //Shift 键是否按下
        bool mkLButton;			 //鼠标左键是否按下
        bool mkMButton;			 //鼠标中键是否按下
        bool mkRButton;			 //鼠标右键是否按下
        short x;				 //当前鼠标 x 坐标
        short y;				 //当前鼠标 y 坐标
        short wheel;			 //鼠标滚轮滚动值(120 的倍数)
};

//bool MouseHit();			 //检查是否存在鼠标消息
//MOUSEMSG GetMouseMsg();		 //获取一个鼠标消息。如果没有，就等待
//void FlushMouseMsgBuffer();	 //清空鼠标消息缓冲区

struct Button
{
    int a;
};




typedef struct menu_start
{
    //起始界面
    //创建按钮的位置
    Button* file;//文件按钮 
    Button* Process;//进程按钮 
    Button* Device;//设备按钮
    Button* Page;//内存按钮
    Button* Begin;//开始按钮
    Button* Stop;//暂停按钮
    Button* Load;//输入确认按钮
    char * UserInput;

};
void button(int x, int y, int w, int h, TCHAR* text)
{
    setbkmode(TRANSPARENT);
    setfillcolor(GREEN);
    fillroundrect(x, y, x + w, y + h, 10, 10);
    // 输出字符串（MBCS 字符集）
    TCHAR s1[] = L"黑体";
    settextstyle(30, 0, s1);
    TCHAR s[50] = L"hello";

    int tx = x + (w - textwidth(text)) / 2;
    int ty = y + (h - textheight(text)) / 2;

    outtextxy(tx, ty, text);

}


void drawMenu()
{
    initgraph(640, 480, EW_SHOWCONSOLE);
    settextstyle(16, 8, _T("Courier"));	// 设置字体

    // 设置颜色
    settextcolor(GREEN);
    setlinecolor(WHITE);
    outtextxy(300, 200, _T("t1"));
}

void draw1()
{
    srand((unsigned)time(NULL));
    drawMenu();
    setbkcolor(BLUE);
    cleardevice();
    TCHAR s[50] = L"1";
    TCHAR s1[50] = L"2";
    TCHAR s2[50] = L"3";
    TCHAR s3[50] = L"4";
    button(220, 50, 170, 50, s);
    button(220, 150, 170, 50, s1);
    button(220, 250, 170, 50, s2);
    button(220, 350, 170, 50, s3);
    ExMessage msg;
    while (true) {
        if (peekmessage(&msg, EM_MOUSE)) {

            switch (msg.message)
            {
            case WM_LBUTTONDOWN:
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 50 && msg.y <= 50 + 50)
                {

                    outtextxy(200, 200, s);	//写了一个展示文字的效果，相当于是测试,实际使用时可以删除
                    //在此处写下按钮点击时要执行的函数，实现相应的功能
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 150 && msg.y <= 150 + 50)
                {

                    outtextxy(200, 200, s1);
                    //在此处写下按钮点击时要执行的函数，实现相应的功能  
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 250 && msg.y <= 250 + 50)
                {

                    outtextxy(200, 200, s2);
                    //在此处写下按钮点击时要执行的函数，实现相应的功能
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 350 && msg.y <= 350 + 50)
                {

                    outtextxy(200, 200, s3);
                    //在此处写下按钮点击时要执行的函数，实现相应的功能
                }
                break;
            default:
                break;
            }
        }

    }
}

void mouseFollow()
{
    MOUSEMSG m;		// 定义鼠标消息
    _getch();
    while (true) {
        ExMessage m;//定义一个消息变量
        m = getmessage(EM_MOUSE);//获取鼠标消息
        switch (m.message)
        {
        case WM_MOUSEMOVE:
            // 鼠标移动的时候画红色的小点
            putpixel(m.x, m.y, RED);
            break;

        case WM_LBUTTONDOWN:
            // 画一个小方块
            rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
            break;

        case WM_RBUTTONUP:
            return ;	// 按鼠标右键退出程序
        }
    }

    circle(200, 200, 100);    //画圆，圆心(200,200),半径100
    arc(100, 300, 500, 100, 60.0, 80.0);
    outtextxy(170, 200, _T("t"));
    _getch();      //按任意键继续,防止闪退
    closegraph();   //关闭绘图窗口
}





*/






















string getInput(string line)
{
    char s[2000] = "";
    string w = (string)s;
    LPCTSTR lpctstr = line.c_str();
    InputBox(s, 10, lpctstr);
    string lineback = s;
    return lineback;
}

void changepcb(PCB process[])
{
    
    for (int i = 0; i < maxprocess; i++)
    {
        process[i].pid = -1;
    }

    for (int i = 0; i < 3; i++)
    {
        process[i].pid = i;
        process[i].state = READY;
        process[i].size = 128;
    }

    for (int i = 3; i < 6; i++)
    {
        process[i].pid = i;
        process[i].state = 2;
        process[i].size = 128;
    }

    for (int i = 6; i < 10; i++)
    {
        process[i].pid = i;
        process[i].state = 3;
        process[i].size = 128;

        process[i].arrivetime=0; // 进程到达时间
        process[i].needtime=1; // 进程总共需要运行的时间
        process[i].remaintime=2; // 进程还需运行的时间
        process[i].finishtime=3; // 进程运行结束的时间
    }

    
}



void pcbDrawPro(PCB process[])
{
    changepcb(process);
    int truesize = 0;
    for (size_t i = 0; i < maxprocess; i++)
    {
        if (process[i].pid >= 0)
            if(process[i].state != 4)
                truesize += 1;
        if (truesize >= 10)
            break;

    }


    initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素


    

    char s[2000] = "Hello World";
    string w = (string)s;

    //InputBox(s, 10, "请输入半径");
    

    printf("%s", s);

    int x , y , z , m , T=180;
    COLORREF colorThis;
    int processptr = 0;
    strcpy(s, "进程");
    outtextxy( 20, 150, s);

    strcpy(s, "状态");
    outtextxy(20, 220, s);

    strcpy(s, "进程所需内存");
    outtextxy(20, 280, s);

    strcpy(s, "进程到达时间");
    outtextxy(20, 340, s);
    
    strcpy(s, "总计运行时间");
    outtextxy(20, 400, s);

    strcpy(s, "还需运行时间");
    outtextxy(20, 460, s);
    
    strcpy(s, "进程所需内存");
    outtextxy(20, 520, s);

    strcpy(s, "进程队列");
    outtextxy(20, 600, s);

    for (int i = 0; i < Ready_Process.size(); i++)
    {
        outtextxy(20, 650+i*40, Ready_Process.front());
    }

    
    int arrivetime; // 进程到达时间
    int needtime; // 进程总共需要运行的时间
    int remaintime; // 进程还需运行的时间
    int finishtime; // 进程运行结束的时间



    for (int i = 0; i < truesize; i++)
    {
        while (true)
        {
            if(process[processptr].state != 4)
            {
                
                break;

            }
        }

        switch (process[processptr].state)
        {
        case 1:colorThis = YELLOW; break;
        case 2:colorThis = GREEN; break;
        case 3:colorThis = RED; break;
        default:break;
        }


        
        x = 0 + i * 1200 / truesize, y = 120, z = x + 100 , m = y+60;
        settextcolor(WHITE);
        _itoa(process[processptr].pid, s, 10);
        outtextxy(x + 120, y - 20, s);
        
        switch (process[processptr].state)
        {
            case 1:strcpy(s, "就绪"); break;
            case 2:strcpy(s, "运行"); break;
            case 3:strcpy(s, "阻塞"); break;
            default:break;
        }
        outtextxy(x + 120, m + 40, s);

        _itoa(process[processptr].size, s, 10);
        outtextxy(x + 120, m + 40 +60, s);

        setfillcolor(colorThis);
        
        // 进程到达时间
        _itoa(process[processptr].arrivetime, s, 10);
        outtextxy(x + 120, m + 40 + 120, s);
        // 进程总共需要运行的时间
        _itoa(process[processptr].needtime, s, 10);
        outtextxy(x + 120, m + 40 + 180, s);
        // 进程还需运行的时间
        _itoa(process[processptr].remaintime, s, 10);
        outtextxy(x + 120, m + 40 + 240, s);
        // 进程运行结束的时间
        _itoa(process[processptr].finishtime, s, 10);
        outtextxy(x + 120, m + 40 + 300, s);

        
        fillellipse(x + 120, y, z + 120, m);	// 画圆，圆心(200, 200)，半径 100


        processptr++;
    }

    int button_x = 50, button_y = 20;
    ellipse(button_x, button_y, button_x+100, button_y+50);
    outtextxy(button_x+20, button_y+20, "创建进程");
    button_x += 1000;
    ellipse(button_x, button_y, button_x + 100, button_y + 50);
    outtextxy(button_x + 20, button_y + 20, "时间增加");



    while (true)
    {

        ExMessage me;//定义一个消息变量
        me = getmessage(EM_MOUSE);//获取鼠标消息
        if (me.message == WM_LBUTTONUP)
        {
            if (me.x <= 230 && me.x > 130)
            {
                clearcircle;
                setfillcolor(YELLOW);
                fillcircle(100, 300, 50);
            }
            else if (me.x <= 330 && me.x > 230)
            {
                clearcircle;
                setfillcolor(GREEN);
                fillcircle(100, 300, 50);
            }
            else if (me.x <= 430 && me.x > 330)
            {
                clearcircle;
                setfillcolor(RED);
                fillcircle(100, 300, 50);
            }
            else
                break;
            if (me.x >= 100 && me.y >= 600 && me.x <= 200 && me.x <= 660)
            {
                
                return;

            }
        }
    }

    TCHAR v[] = _T("按任意键退出");
    outtextxy(400, 400, v);

    _getch();				// 按任意键继续
    cleardevice();			// 关闭绘图窗口

    x = 0, y = 400, z = 100, T = 480;
    TCHAR q1[] = _T("文件");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q1);
    x += 100, z += 100;
    TCHAR q2[] = _T("设备");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q2);
    x += 100, z += 100;
    TCHAR q3[] = _T("内存");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q3);
    x += 100, z += 100;
    TCHAR q4[] = _T("进程");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q4);
    x += 100, z = 640;
    TCHAR q5[] = _T("退出");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q5);

    return;

}

void InitializeMemory()
{
    int i, j;//循环变量
    //初始化虚拟内存

    for (i = 0; i < PAGE_NUMBER; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j == 0) virMemory.virTable[i][j] = -1;
            if (j == 1) virMemory.virTable[i][j] = 0;
            if (j == 2) virMemory.virTable[i][j] = 0;
        }
        virMemory.virContent[i] = "*";
    }
    //初始化物理内存
    for (i = 0; i < FRAME_NUMBER; i++)
    {
        phyMemory.phyTable[i] = -1;
        phyMemory.phyContent[i] = "*";
    }
}

void drawVirMemory()
{
    char s[2000] = "Hello World";
    string w = (string)s;
    int x = 700, y = 300;
    /*
    typedef struct VirMemoty {
        int virTable[PAGE_NUMBER][3];//虚拟内存分配情况（PID，默认-1；已用内存，默认0；已写内存，默认0）
        string virContent[PAGE_NUMBER];//虚拟内存存储内容（默认"*"）
    }VirMemoty;
    typedef struct PhyMemory {
        int phyTable[FRAME_NUMBER]; //物理内存分配情况（页号，默认-1）
        string phyContent[FRAME_NUMBER]; //物理内存里存储内容（默认"*"）
    }PhyMemory;
    PageTable pageTable;//页表
    VirMemoty virMemory;//虚拟内存使用情况
    PhyMemory phyMemory;//物理内存使用情况

    */
    clearrectangle(100, 100, 900, 500);
    rectangle(100, 90, 200, 190);
    outtextxy(100 + 20, 100 + 20, "页号");
    for (int i = 0; i < PAGE_NUMBER; i++)
    {
        rectangle( 200 + i * 100, 90,  300 + i * 100,190 );
        _itoa(i, s, 10);
        outtextxy(200 + i * 100 + 20, 100  + 20, s);
        for (int j = 0; j < 3; j++)
        {
            int table_x = 200 + i*100, table_y = 200 + j * 100;
            rectangle(table_x, table_y, table_x + 100, table_y + 100);
            _itoa(virMemory.virTable[i][j], s, 10);
            outtextxy(table_x+20, table_y+20, s);
        }

    }
}

void drawPhyMemory()
{
    char s[2000] = "Hello World";
    string w = (string)s;
    int x = 700, y = 300;
    /*
    typedef struct VirMemoty {
        int virTable[PAGE_NUMBER][3];//虚拟内存分配情况（PID，默认-1；已用内存，默认0；已写内存，默认0）
        string virContent[PAGE_NUMBER];//虚拟内存存储内容（默认"*"）
    }VirMemoty;
    typedef struct PhyMemory {
        int phyTable[FRAME_NUMBER]; //物理内存分配情况（页号，默认-1）
        string phyContent[FRAME_NUMBER]; //物理内存里存储内容（默认"*"）
    }PhyMemory;
    PageTable pageTable;//页表
    VirMemoty virMemory;//虚拟内存使用情况
    PhyMemory phyMemory;//物理内存使用情况

    */
    clearrectangle(100, 100, 900, 500);
    rectangle(100, 90, 200, 190);
    outtextxy(100 + 20, 100 + 20, "帧号");
    for (int i = 0; i < FRAME_NUMBER; i++)
    {
        rectangle(200 + i * 100, 90, 300 + i * 100, 190);
        _itoa(i, s, 10);
        outtextxy(200 + i * 100 + 20, 100 + 20, s);
        int table_x = 200 + i * 100, table_y = 200 ;
        rectangle(table_x, table_y, table_x + 100, table_y + 100);
        _itoa(phyMemory.phyTable[i], s, 10);
        outtextxy(table_x + 20, table_y + 20, s);
        

    }
}

void memoryDraw()
{
    init_directory();



    initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素

    InitializeMemory();

    char s[2000] = "Hello World";
    string w = (string)s;
    outtextxy(10, 20, s);
    int button_x = 100, button_y = 600;
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "虚拟内存");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "物理内存");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "查找");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "插入");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "删除");
    button_x += 120;

    int x = 700, y = 300;
    COLORREF colorThis;
    int processptr = 0;
    strcpy(s, "内存");
    outtextxy(20, 40, s);

    while (true)
    {

        ExMessage me;//定义一个消息变量
        me = getmessage(EM_MOUSE);//获取鼠标消息
        if (me.message == WM_LBUTTONUP)
        {
            
            button_x = 100, button_y = 600;
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.x <= button_y + 60)
            {
                drawVirMemory();
                return;

            }
            else if (me.x >= button_x + 120 && me.y >= button_y && me.x <= button_x + 100 + 120 && me.x <= button_y + 60)
            {
                drawPhyMemory();
                return;
                //return;
            }
            else if (me.x >= button_x + 240 && me.y >= button_y && me.x <= button_x + 100 + 240 && me.x <= button_y + 60)
            {
                
                //return;
            }
            else if (me.x >= button_x + 360 && me.y >= button_y && me.x <= button_x + 100 + 360 && me.x <= button_y + 60)
            {
                //outtextxy(button_x + 30, button_y + 20, "写文件");
                //fileDraw();
                //return;
            }




        }


    }

    TCHAR v[] = _T("按任意键退出");
    outtextxy(400, 400, v);

    _getch();				// 按任意键继续
    cleardevice();			// 关闭绘图窗口
    int z = 100, T = 480;
    x = 0, y = 400;
    TCHAR q1[] = _T("文件");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q1);
    x += 100, z += 100;
    TCHAR q2[] = _T("设备");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q2);
    x += 100, z += 100;
    TCHAR q3[] = _T("内存");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q3);
    x += 100, z += 100;
    TCHAR q4[] = _T("进程");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q4);
    x += 100, z = 640;
    TCHAR q5[] = _T("退出");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q5);

    return;


}




void init_directory()
{
    head = (FCB*)malloc(sizeof(FCB));
    FCB* father1 = (FCB*)malloc(sizeof(FCB));
    FCB* father2 = (FCB*)malloc(sizeof(FCB));
    FCB* father3 = (FCB*)malloc(sizeof(FCB));
    FCB* f1 = (FCB*)malloc(sizeof(FCB));
    FCB* f2 = (FCB*)malloc(sizeof(FCB));
    FCB* f3 = (FCB*)malloc(sizeof(FCB));
    FCB* f4 = (FCB*)malloc(sizeof(FCB));
    FCB* f5 = (FCB*)malloc(sizeof(FCB));
    //初始化目录文件 

    head->sonFCB = father1;
    head->color = 1;
    head->type = 1;
    head->name = (char*)malloc(sizeof(char) * 20); // 分配内存
    strcpy(head->name, "head");


    father1->name = (char*)malloc(sizeof(char) * 20); // 分配内存
    father1->color = 1;
    strcpy(father1->name, "father1");
    father1->type = 1;

    father2->name = (char*)malloc(sizeof(char) * 20); // 分配内存
    strcpy(father2->name, "father2");
    father2->type = 1;

    father3->name = (char*)malloc(sizeof(char) * 20); // 分配内存
    strcpy(father3->name, "father3");
    father3->type = 1;

    f1->name = (char*)malloc(sizeof(char) * 20); // 分配内存
    strcpy(f1->name, "f1");
    f1->type = 0;

    f2->name = (char*)malloc(sizeof(char) * 20); // 分配内存
    strcpy(f2->name, "f2");
    f2->type = 0;

    f3->name = (char*)malloc(sizeof(char) * 20); // 分配内存
    strcpy(f3->name, "f3");
    f3->type = 0;

    f4->name = (char*)malloc(sizeof(char) * 20); // 分配内存
    strcpy(f4->name, "f4");
    f4->type = 0;

    f5->name = (char*)malloc(sizeof(char) * 20); // 分配内存
    strcpy(f5->name, "f5");
    f5->type = 0;


    father1->nextFCB = father2;
    father1->sonFCB = f1;
    f1->color = 1;
    f1->nextFCB = f2;
    f2->nextFCB = f3;
    father2->sonFCB = f4;
    f4->nextFCB = father3;
    father3->sonFCB = f5;

    head->nextFCB = NULL;
    f1->sonFCB = NULL;
    f2->sonFCB = NULL;
    f3->sonFCB = NULL;
    f4->sonFCB = NULL;
    f5->sonFCB = NULL;
    father2->nextFCB = NULL;
    father3->nextFCB = NULL;
    f3->nextFCB = NULL;
    f5->nextFCB = NULL;

}

int size1(FCB* a)
{
    FCB* b=a;
    int num = 0;
    while(b != NULL)
    {
        b = b->nextFCB;
        num++;
    }

    printf("num:%d", num);
    cout << num << endl;
    return num;
}

void drawFileMenu(FCB* head)
{
    char s[2000] = "Hello World";
    string w = (string)s;
    int x = 700, y = 300;
    int size = size1(head->sonFCB);
    if (head->color == 1)
        setfillcolor(RED);
    else
        setfillcolor(WHITE);
    fillellipse(660, 100, 760, 160);
    strcpy(s, head->name);
    outtextxy(700, 180, s);
    FCB* temp = head->sonFCB;
    for (int t = 0; t < size; t++)
    {

        x = 100 + 1200 / size * t, y = 200;
        if (temp->color == 1)
            setfillcolor(RED);
        else
            setfillcolor(WHITE);
        fillellipse(x, y , x + 60, y + 120);
        outtextxy(x - 60, y + 80, temp->name);
        temp = temp->nextFCB;

    }
}

void fileDraw()
{
    init_directory();



    initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素



    char s[2000] = "Hello World";
    string w = (string)s;
    outtextxy(10, 20, s);
    int button_x = 100, button_y = 600;
    ellipse(button_x, button_y, button_x+100, button_y+60);
    outtextxy(button_x+30, button_y+20 , "根目录");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "创建文件");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "查询文件");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "写文件");
    button_x += 120;



    int x=700, y=300 ;
    COLORREF colorThis;
    int processptr = 0;
    strcpy(s, "文件");
    outtextxy(20, 40, s);

    drawFileMenu(head);

    outtextxy(100, 180, "点击对应子文件切换目录");
    
    FCB* temp = head;
    while (true)
    {

        ExMessage me;//定义一个消息变量
        me = getmessage(EM_MOUSE);//获取鼠标消息
        if (me.message == WM_LBUTTONUP)
        {
            for (int i = 0; i < size1(temp); i++)
            {
                if(me.x>=100+ 1200 / size1(temp) * i && me.x< 100 + 1200 / size1(temp) * i+60 
                    && me.y<=320 &&me.y>=200)
                {
                    clearrectangle(0, 180, 1200, 320);
                    temp = temp->sonFCB;
                    for (int j = 1; j < i; j++)
                    {
                        temp = temp->nextFCB;
                    }
                    drawFileMenu(temp);
                }
            }
            button_x = 100, button_y = 600;
            if(me.x>= button_x &&me.y>= button_y &&me.x<= button_x +100&&me.x<= button_y+60)
            {
                fileDraw();
                return;

            }
            else if (me.x >= button_x+120 && me.y >= button_y && me.x <= button_x + 100 + 120 && me.x <= button_y + 60)
            {
                //outtextxy(button_x + 30, button_y + 20, "创建文件");
                fileDraw();
                return;
            }
            else if (me.x >= button_x + 240 && me.y >= button_y && me.x <= button_x + 100 + 240 && me.x <= button_y + 60)
            {
                //outtextxy(button_x + 30, button_y + 20, "查询文件");
                fileDraw();
                return;
            }
            else if (me.x >= button_x + 360 && me.y >= button_y && me.x <= button_x + 100 + 360 && me.x <= button_y + 60)
            {
                //outtextxy(button_x + 30, button_y + 20, "写文件");
                fileDraw();
                return;
            }
                
            


        }


    }

    TCHAR v[] = _T("按任意键退出");
    outtextxy(400, 400, v);

    _getch();				// 按任意键继续
    cleardevice();			// 关闭绘图窗口
    int z = 100, T = 480;
    x = 0, y = 400;
    TCHAR q1[] = _T("文件");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q1);
    x += 100, z += 100;
    TCHAR q2[] = _T("设备");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q2);
    x += 100, z += 100;
    TCHAR q3[] = _T("内存");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q3);
    x += 100, z += 100;
    TCHAR q4[] = _T("进程");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q4);
    x += 100, z = 640;
    TCHAR q5[] = _T("退出");
    fillrectangle(x, y, z, T);
    outtextxy(x, y - 20, q5);

    return;

}

bool acquire_request(int pid, int device) {//device：请求设备号
    for (int i = 0; i < Device_Table[device].size; i++) {
        if (Device_Table[device].data[i] == pid) {
            return false;//重复请求
        }
    }
    Device_Table[device].data = (int*)realloc(Device_Table[device].data, (Device_Table[device].size + 1) * sizeof(int));
    Device_Table[device].data[Device_Table[device].size] = pid;
    Device_Table[device].size++;
    if (Device_Table[device].size > Device_Table[device].num) {
        return false; // 进程加入等待队列
    }
    else {
        return true; //进程使用设备
    }
}

void init_device() {
    for (int i = 0; i < DeviceNum; i++) {
        Device_Table[i].name = deviceName[i];
        acquire_request(0, i);
        acquire_request(1, i);
        Device_Table[i].size = 2;
        Device_Table[i].num = deviceNum[i];
    }
}


void changedevice(PCB process[])
{

    init_device();


}

void deviceDraw()
{
    init_device();


    initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素




    char s[2000] = "Hello World";
    string w = (string)s;

    outtextxy(10, 20, s);
    int x, y, z, m, T = 180;
    COLORREF colorThis;
    int processptr = 0;
    strcpy(s, "设备状态");
    outtextxy(20, 150, s);

    strcpy(s, "设备名称");
    outtextxy(20, 220, s);

    strcpy(s, "设备等待队列");
    outtextxy(20, 280, s);


    for (int i = 0; i < DeviceNum; i++)
    {
        if(Device_Table[i].size==0)
            colorThis = GREEN;
        else if (Device_Table[i].size > 0 && Device_Table[i].size <= Device_Table[i].num)
            colorThis = YELLOW;
        else
            colorThis = RED;

        x = 0 + i * 1200 / DeviceNum, y = 120, z = x + 100, m = y + 60;
        settextcolor(WHITE);

        strcpy(s, Device_Table[i].name.c_str());
        //outtextxy(x + 120, y - 20, s);

        setfillcolor(colorThis);
        fillellipse(x + 120, y, z + 120, m);	// 画圆，圆心(200, 200)，半径 100

        outtextxy(x + 120, m + 40, s);



        for (int j = 0; j < Device_Table[i].size; j++)
        {
            _itoa(Device_Table[i].data[j], s, 10);
            outtextxy(x + 120, m + 40 + 60, s);
            m += 40;
        }
        
        processptr++;
    }

    /*
    initgraph(640, 480);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素
    setlinecolor(BLUE);
    TCHAR s[] = _T("设备");
    outtextxy(10, 20, s);
    TCHAR v[] = _T("按任意键退出");
    outtextxy(400, 400, v);
    int x = 60, y = 100, z = 100, m = 200,o;

    TCHAR s1[] = _T("键盘");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s1);
    x += 60, z += 60;
    TCHAR s2[] = _T("鼠标");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s2);
    x += 60, z += 60;
    TCHAR s3[] = _T("屏幕");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s3);
    x += 60, z += 60;
    TCHAR s4[] = _T("打印机");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s4);
    x += 60, z += 60;
    TCHAR s5[] = _T("磁盘");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s5);


    TCHAR D[] = _T("等待队列");
    outtextxy(10, 350, D);*/
 



    _getch();				// 按任意键继续
    cleardevice();			// 关闭绘图窗口
 
    int o = 480;
    x = 0, y = 400, z = 100;
    setlinecolor(BLUE);
    TCHAR q1[] = _T("文件");
    fillrectangle(x, y, z, o);
    outtextxy(x, y - 20, q1);
    x += 100, z += 100;
    TCHAR q2[] = _T("设备");
    fillrectangle(x, y, z, o);
    outtextxy(x, y - 20, q2);
    x += 100, z += 100;
    TCHAR q3[] = _T("内存");
    fillrectangle(x, y, z, o);
    outtextxy(x, y - 20, q3);
    x += 100, z += 100;
    TCHAR q4[] = _T("进程");
    fillrectangle(x, y, z, o);
    outtextxy(x, y - 20, q4);
    x += 100, z = 640;
    TCHAR q5[] = _T("退出");
    fillrectangle(x, y, z, o);
    outtextxy(x, y - 20, q5);

    return;
}
int main()
{
    MOUSEMSG m;		// 定义鼠标消息
    initgraph(1280, 800);
    int x = 0, y = 400, z = 100, o = 480;
    setlinecolor(BLUE);
    TCHAR q1[] = _T("文件");
    fillrectangle(x, y, z, o);
    outtextxy(x, y - 20, q1);
    x += 100, z += 100;
    TCHAR q2[] = _T("设备");
    fillrectangle(x, y, z, o);
    outtextxy(x, y - 20, q2);
    x += 100, z += 100;
    TCHAR q3[] = _T("内存");
    fillrectangle(x, y, z,o);
    outtextxy(x, y - 20, q3);
    x += 100, z += 100;
    TCHAR q4[] = _T("进程");
    fillrectangle(x, y, z, o);
    outtextxy(x, y - 20, q4);
    x += 100, z = 640;
    TCHAR q5[] = _T("退出");
    fillrectangle(x, y, z, o);
    outtextxy(x, y - 20, q5);
    while (true) 
    {
        ExMessage m;//定义一个消息变量
        m = getmessage(EM_MOUSE);//获取鼠标消息
        if(m.message== WM_LBUTTONUP)
        {
            if (m.x <= 100)
                fileDraw();
            else if (m.x <= 200 && m.x > 100)
                deviceDraw();
            else if (m.x <= 300 && m.x > 200)
                memoryDraw();
            else if (m.x <= 400 && m.x > 300)
                pcbDrawPro(process);
            else
                break;

        }
        
    }
    
    return 0;
}
