#include "ui.h"

void drawMain()
{
    initgraph(1400, 720);
    int x = 0, y = 400, z = 100, o = 480;
    setfillcolor(WHITE);
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
    while (true)
    {
        ExMessage m;//定义一个消息变量
        m = getmessage(EM_MOUSE);//获取鼠标消息
        if (m.message == WM_LBUTTONUP)
        {
            if (m.x <= 100 && m.x > 0)
                fileDraw();
            else if (m.x <= 200 && m.x > 100)
                deviceDraw();
            else if (m.x <= 300 && m.x > 200)
                memoryDraw();
            else if (m.x <= 400 && m.x > 300)
                pcbDrawPro();
            else if (m.x <= 500 && m.x > 400)
                break;

        }

    }
    
    //return;
}



string getInput(string line)
{
    char s[2000] = "";
    string w = (string)s;
    LPCTSTR lpctstr = line.c_str();
    InputBox(s, 10, lpctstr);
    string lineback = s;
    return lineback;



}

void drawCreatePCB()
{
    int button_x = 100, button_y = 600;
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "创建文件");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "删除文件");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "读文件");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "写文件");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "申请设备");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "释放设备");
    button_x += 120;

    while (true)
    {

        ExMessage me;//定义一个消息变量
        me = getmessage(EM_MOUSE);//获取鼠标消息
        if (me.message == WM_LBUTTONUP)
        {

            button_x = 100, button_y = 600;
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.x <= button_y + 60)
            {
                //创建文件
                return;

            }
            else if (me.x >= button_x + 120 && me.y >= button_y && me.x <= button_x + 100 + 120 && me.x <= button_y + 60)
            {
                //删除文件
                return;
            }
            else if (me.x >= button_x + 240 && me.y >= button_y && me.x <= button_x + 100 + 240 && me.x <= button_y + 60)
            {
                //读文件
                //return;
            }
            else if (me.x >= button_x + 360 && me.y >= button_y && me.x <= button_x + 100 + 360 && me.x <= button_y + 60)
            {
                //写文件
                //return;
            }
            else if (me.x >= button_x + 480 && me.y >= button_y && me.x <= button_x + 100 + 480 && me.x <= button_y + 60)
            {
                //申请设备
                //return;
            }
            else if (me.x >= button_x + 600 && me.y >= button_y && me.x <= button_x + 100 + 600 && me.x <= button_y + 60)
            {
                //释放设备
                //return;
            }



        }


    }

}
/*void init_process()
{
    for (int i = 0; i < 3; i++)
    {
        process[i].pid = i;
        process[i].state = 1;
    }
}*/
void pcbDrawPro()
{
    int truesize = 0;
    for (int i = 0; i < maxprocess; i++)
    {
        if (process[i].pid >= 0)
            if (process[i].state == 1|| process[i].state == 2 || process[i].state == 3)
                truesize += 1;
        if (truesize >= 10)
            break;

    }


    initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口




    char s[2000] = "";


    //InputBox(s, 10, "请输入半径");


    printf("%s", s);

    int x, y, z, m, T = 180;
    COLORREF colorThis = WHITE;
    int processptr = 0;
    strcpy(s, "进程");
    outtextxy(20, 150, s);

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

    strcpy(s, "进程队列");
    outtextxy(20, 520, s);

    for (int i = 0; i < Ready_Process.size(); i++)
    {
        outtextxy(20 + i * 40, 570, Ready_Process.front());
    }


    int arrivetime; // 进程到达时间
    int needtime; // 进程总共需要运行的时间
    int remaintime; // 进程还需运行的时间
    int finishtime; // 进程运行结束的时间



    for (int i = 0; i < truesize; i++)
    {
        while (true)
        {
            if (process[i].state == 1 || process[i].state == 2 || process[i].state == 3)
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



        x = 0 + i * 1200 / truesize, y = 120, z = x + 100, m = y + 60;
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
        outtextxy(x + 120, m + 40 + 60, s);

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
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 20, button_y + 20, "创建进程");

    button_x = 1050;
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 20, button_y + 20, "时间前进");

    button_x -= 200;
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 20, button_y + 20, "主界面");

    while (true)
    {

        ExMessage me;//定义一个消息变量
        me = getmessage(EM_MOUSE);//获取鼠标消息
        if (me.message == WM_LBUTTONUP)
        {
            button_x = 50, button_y = 20;

            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.y <= button_y + 60)
            {
                drawCreatePCB();
                pcbDrawPro();
                return;

            }
            else if (me.x >= button_x + 1000 && me.y >= button_y && me.x <= button_x + 1000 + 100 && me.y <= button_y + 60)
            {
                //时间前进
                pcbDrawPro();
                return;

            }
            else if (me.x >= button_x + 800 && me.y >= button_y && me.x <= button_x + 800 + 100 && me.y <= button_y + 60)
            {
                //退出
                break;

            }
        }
    }

    drawMain();

    return;

}

void drawVirMemory()
{
    char s[2000] = "Hello World";

    int x = 700, y = 300;

    clearrectangle(100, 90, 1200, 800);
    rectangle(100, 90, 200, 190);
    outtextxy(100 + 20, 100 + 20, "页号");
    for (int i = 0; i < PAGE_NUMBER; i++)
    {
        rectangle(200 + i * 100, 90, 300 + i * 100, 190);
        _itoa(i, s, 10);
        outtextxy(200 + i * 100 + 20, 100 + 20, s);
        for (int j = 0; j < 3; j++)
        {
            int table_x = 200 + i * 100, table_y = 200 + j * 100;
            rectangle(table_x, table_y, table_x + 100, table_y + 100);
            _itoa(virMemory.virTable[i][j], s, 10);
            outtextxy(table_x + 20, table_y + 20, s);
        }

    }
}

void drawPhyMemory()
{
    char s[2000] = "Hello World";

    int x = 700, y = 300;

    clearrectangle(100, 90, 1200, 800);
    rectangle(100, 90, 200, 190);
    outtextxy(100 + 20, 100 + 20, "帧号");
    for (int i = 0; i < FRAME_NUMBER; i++)
    {
        rectangle(200 + i * 100, 90, 300 + i * 100, 190);
        _itoa(i, s, 10);
        outtextxy(200 + i * 100 + 20, 100 + 20, s);
        int table_x = 200 + i * 100, table_y = 200;
        rectangle(table_x, table_y, table_x + 100, table_y + 100);
        _itoa(phyMemory.phyTable[i], s, 10);
        outtextxy(table_x + 20, table_y + 20, s);


    }
}

void memoryDraw()
{

    initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素

    char s[2000] = "";

    outtextxy(10, 20, s);
    int button_x = 50, button_y = 20;
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 20, button_y + 20, "虚拟内存");
    button_x += 120;

    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 20, button_y + 20, "物理内存");
    button_x += 120;

    button_x = 1050;
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 20, button_y + 20, "时间前进");

    button_x -= 200;
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 20, button_y + 20, "主界面");

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

            button_x = 50, button_y = 20;
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.y <= button_y + 60)
            {
                drawVirMemory();

            }
            else if (me.x >= button_x + 120 && me.y >= button_y && me.x <= button_x + 100 + 120 && me.y <= button_y + 60)
            {
                drawPhyMemory();
            }
            else if (me.x >= button_x + 1000 && me.y >= button_y && me.x <= button_x + 1000 + 100 && me.y <= button_y + 60)
            {
                //时间前进
                memoryDraw();
                return;
            }
            else if (me.x >= button_x + 800 && me.y >= button_y && me.x <= button_x + 800 + 100 && me.y <= button_y + 60)
            {
                break;
            }



        }


    }

    drawMain();

    return;


}


int size1(FCB* a)
{
    FCB* b = a;
    int num = 0;
    while (b != NULL)
    {
        b = b->nextFCB;
        num++;
    }
    return num;
}

void drawFileMenu(FCB* top)
{
    char s[2000] = "Hello World";

    int x = 700, y = 300;
    int size = size1(top->sonFCB);
    setfillcolor(WHITE);
    fillellipse(660, 100, 760, 160);
    strcpy(s, top->name);
    outtextxy(700, 180, s);
    FCB* temp = top->sonFCB;
    for (int t = 0; t < size; t++)
    {

        x = 100 + 1200 / size * t, y = 200;
        setfillcolor(WHITE);
        fillellipse(x, y, x + 60, y + 120);
        outtextxy(x - 60, y + 80, temp->name);
        temp = temp->nextFCB;

    }
}

void fileDraw()
{

    initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素

    char s[2000] = "Hello World";

    outtextxy(10, 20, s);
    int button_x = 20, button_y = 50;
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 30, button_y + 20, "根目录");
    button_x += 120;

    button_x = 50, button_y = 20;
    button_x = 1050;
    ellipse(button_x, button_y, button_x + 100, button_y + 50);
    outtextxy(button_x + 20, button_y + 20, "时间前进");

    button_x -= 200;
    ellipse(button_x, button_y, button_x + 100, button_y + 50);
    outtextxy(button_x + 20, button_y + 20, "主界面");


    int x = 700, y = 300;

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
            for (int i = 0; i < size1(temp->sonFCB); i++)
            {
                
                if (me.x >= 100 + 1200 / size1(temp->sonFCB) * i && me.x < 100 + 1200 / size1(temp->sonFCB) * i + 60
                    && me.y <= 320 && me.y >= 200)
                {
                    clearrectangle(0, 180, 1200, 320);
                    temp = temp->sonFCB;
                    for (int j = 0; j < i; j++)
                    {
                        temp = temp->nextFCB;
                    }
                    drawFileMenu(temp);
                }
            }
            button_x = 20, button_y = 50;
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.y <= button_y + 60)
            {
                fileDraw();
                return;

            }
            else if (me.x >= button_x + 1030 && me.y >= button_y && me.x <= button_x + 1030 + 100 && me.y <= button_y + 60)
            {
                //时间前进
                fileDraw();
                return;

            }
            else if (me.x >= button_x + 800 && me.y >= button_y && me.x <= button_x + 800 + 100 && me.y <= button_y + 60)
            {
                //退出
                break;

            }




        }


    }


    drawMain();

    return;

}


void deviceDraw()
{

    initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素
    char s[2000] = "Hello World";


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

    int button_x = 50, button_y = 20;
    button_x = 1050;
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 20, button_y + 20, "时间前进");

    button_x -= 200;
    ellipse(button_x, button_y, button_x + 100, button_y + 60);
    outtextxy(button_x + 20, button_y + 20, "主界面");

    for (int i = 0; i < DeviceNum; i++)
    {
        if (Device_Table[i].size == 0)
            colorThis = GREEN;
        else if (Device_Table[i].size > 0 && Device_Table[i].size <= Device_Table[i].num)
            colorThis = YELLOW;
        else
            colorThis = RED;

        x = 0 + i * 1200 / DeviceNum, y = 120, z = x + 100, m = y + 60;
        settextcolor(WHITE); 
        //strcpy(s, Device_Table[i].name);
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

    while (true)
    {

        ExMessage me;//定义一个消息变量
        me = getmessage(EM_MOUSE);//获取鼠标消息
        if (me.message == WM_LBUTTONUP)
        {
            button_x = 50, button_y = 20;
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.y <= button_y + 60)
            {
                deviceDraw();
                return;

            }
            else if (me.x >= button_x + 1000 && me.y >= button_y && me.x <= button_x + 1000 + 100 && me.y <= button_y + 60)
            {
                //时间前进
                deviceDraw();
                return;

            }
            else if (me.x >= button_x + 800 && me.y >= button_y && me.x <= button_x + 800 + 100 && me.y <= button_y + 60)
            {
                //退出
                break;

            }




        }
    }
    drawMain();

    return;
}

void main()
{
    init_device();
    init_directory();
    init_process();
    InitializeMemory();
    drawMain();
    closegraph();
    return ;
}
