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
#include "device.h"
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

    InputBox(s, 10, "请输入半径");
    

    printf("%s", s);
    outtextxy(10, 20, s);
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

        }
    }

    TCHAR v[] = _T("按任意键退出");
    outtextxy(400, 400, v);

    _getch();				// 按任意键继续
    cleardevice();			// 关闭绘图窗口
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




void pcbDraw()
{
    
    initgraph(640, 480);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素
    TCHAR s[] = _T("进程");
    outtextxy(10, 20, s);

    int x = 130, y = 120, z = 230,m = 180,T;
    //setlinecolor(GREEN);
    settextcolor(GREEN);
    TCHAR s1[] = _T("运行");
    outtextxy(x + 120, y - 20, s1);
    setfillcolor(GREEN);
    fillellipse(x+120, y, z+120,m);	// 画圆，圆心(200, 200)，半径 100
    //setlinecolor(RED);
    settextcolor(RED);
    TCHAR s2[] = _T("阻塞");
    outtextxy(x+240, y - 20, s2);
    setfillcolor(RED);
    fillellipse(x+240, y, z+240,m);	// 画圆，圆心(200, 200)，半径 100
    settextcolor(YELLOW);
    setfillcolor(YELLOW);
    TCHAR s3[] = _T("就绪");
    outtextxy(x, y-20, s3);
    fillellipse(x, y, z,m);	// 画圆，圆心(200, 200)，半径 100
    x = 0, y = 400, z = 100, T = 480;
    setlinecolor(BLUE);


    TCHAR s4[] = _T("示例进程");
    outtextxy(75, 220, s4);
    setfillcolor(WHITE);
    fillcircle(100, 300, 50);


    

    while(true)
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

        }
    }

    TCHAR v[] = _T("按任意键退出");
    outtextxy(400, 400, v);

    _getch();				// 按任意键继续
    cleardevice();			// 关闭绘图窗口
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


void memoryDraw()
{
    initgraph(640, 480);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素
    setlinecolor(BLUE);
    TCHAR s[] = _T("内存");
    outtextxy(10, 20, s);
    TCHAR v[] = _T("按任意键退出");
    outtextxy(400, 400, v);
    TCHAR T[] = _T("页表");
    outtextxy(10, 100, T);
    int x = 60, y = 100, z = 100, m = 200,o;

    TCHAR s1[] = _T("一");
    fillrectangle(x, y, z , m);
    outtextxy(x , y-20 , s1);	
    x += 40, z += 40;
    TCHAR s2[] = _T("二");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s2);
    x += 40, z += 40;
    TCHAR s3[] = _T("三");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s3);
    x += 40, z += 40;
    TCHAR s4[] = _T("四");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s4);
    x += 40, z += 40;
    TCHAR s5[] = _T("五");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s5);
    x += 40, z += 40;
    TCHAR s6[] = _T("六");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s6);
    x += 40, z += 40;
    TCHAR s7[] = _T("七");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s7);
    x += 40, z += 40;
    TCHAR s8[] = _T("八");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s8);
    x += 40, z += 40;
    TCHAR s9[] = _T("九");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s9);
    x += 40, z += 40;
    
    TCHAR D[] = _T("调度队列");
    outtextxy(10, 350, D);

 


    _getch();				// 按任意键继续
    cleardevice();			// 关闭绘图窗口
 

    x = 0, y = 400, z = 100, o = 480;
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

void fileDraw()
{
    initgraph(640, 480);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素
    setlinecolor(BLUE);
    TCHAR s[] = _T("文件");
    outtextxy(10, 20, s);
    TCHAR v[] = _T("按任意键退出");
    outtextxy(400, 400, v);
    TCHAR T1[] = _T("一级目录");
    outtextxy(10, 100, T1);
    TCHAR T2[]  = _T("二级目录");
    outtextxy(10, 180, T2);
    TCHAR T3[] = _T("三级目录");
    outtextxy(10, 260, T3);
    TCHAR T4[] = _T("四级目录");
    outtextxy(10,340, T4);


    int x = 100, y = 100, z = 140, m = 150,o;

    TCHAR s1[] = _T("一");
    fillrectangle(x, y, z, m);
    outtextxy(x, y -20, s1);
    y += 80;
    m += 80;
    x = 100, z = 140;
    setlinecolor(GREEN);
    line(x / 2 + z / 2, m-80, x / 2 + z / 2,m);
    setlinecolor(WHITE);


    TCHAR s2[] = _T("二");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s2);
    
    x += 60, z += 60;

    
    TCHAR s3[] = _T("三");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s3);
    setlinecolor(GREEN);
    line(x / 2 + z / 2-60, m - 80, x / 2 + z / 2, y);
    setlinecolor(WHITE);
    x = 100, z = 140,y += 80, m += 80;
    TCHAR s4[] = _T("四");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s4);
    setlinecolor(GREEN);
    line(100 / 2 +140 / 2 , m - 80, x / 2 + z / 2, y);
    setlinecolor(WHITE);

    x += 60, z += 60;
    TCHAR s5[] = _T("五");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s5);
    setlinecolor(GREEN);
    line(100 / 2 + 140 / 2, m - 80, x / 2 + z / 2, y);
    setlinecolor(WHITE);
    x += 60, z += 60;
    TCHAR s6[] = _T("六");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s6);
    setlinecolor(GREEN);
    line(160 / 2 + 200 / 2, m - 80, x / 2 + z / 2, y);
    setlinecolor(WHITE);
    x += 60, z += 60;
    setlinecolor(GREEN);
    line(160 / 2 + 200 / 2, m - 80, x / 2 + z / 2, y);
    setlinecolor(WHITE);
    TCHAR s7[] = _T("七");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s7);
    setlinecolor(GREEN);
    line(160 / 2 + 200 / 2, m - 80, x / 2 + z / 2, y);
    setlinecolor(WHITE);
    x = 100, z = 140, y += 80, m += 80;
    TCHAR s8[] = _T("八");
    fillrectangle(x, y, z, m);
    outtextxy(x, y - 20, s8);
    setlinecolor(GREEN);
    line(100 / 2 + 140 / 2, m - 80, x / 2 + z / 2, y);
    setlinecolor(WHITE);






    _getch();				// 按任意键继续
    cleardevice();			// 关闭绘图窗口
    x = 0, y = 400, z = 100, o = 480;
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

        /*// 进程到达时间
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

        */
        


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
    outtextxy(10, 350, D);
 



    _getch();				// 按任意键继续
    cleardevice();			// 关闭绘图窗口
 

    x = 0, y = 400, z = 100, o = 480;
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

    return;*/
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
