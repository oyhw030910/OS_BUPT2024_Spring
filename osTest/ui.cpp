#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>//引用图形库头文件
#include <conio.h>
#include <string>
#include <time.h>
#include <easyx.h>


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
};*/

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
    TCHAR s[50] = L"1.读取点云";
    TCHAR s1[50] = L"2.分割点云";
    TCHAR s2[50] = L"3.单个树木";
    TCHAR s3[50] = L"4.树木重建";
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








































void pcbDraw()
{
    
    initgraph(640, 480);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素
    TCHAR s[] = _T("进程");
    outtextxy(10, 20, s);
    TCHAR v[] = _T("按任意键退出");
    outtextxy(400, 400, v);
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

void deviceDraw()
{
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

    return;
}
int main()

{
   
    MOUSEMSG m;		// 定义鼠标消息
    initgraph(640, 480);
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
    while (true) {
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
                pcbDraw();
            else
                break;

        }
        
    }
    
    return 0;
}