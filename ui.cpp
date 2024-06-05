#include "ui.h"

void drawMain()
{
    initgraph(1400, 720);
    /*MOUSEMSG m;		// 定义鼠标消息
    
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
        //m.message = WM_LBUTTONUP;
        if (m.message == WM_LBUTTONUP)
        {
            //m.x = 450;
            if (m.x <= 100)
                fileDraw();
            else if (m.x <= 200 && m.x > 100)
                deviceDraw();
            else if (m.x <= 300 && m.x > 200)
                memoryDraw();
            else if (m.x <= 400 && m.x > 300)
                pcbDrawPro();
            else if (m.x <= 500 && m.x > 400)
                return;

        }

    }*/
    clearrectangle(0, 0, 1289, 599);//显示区
    //clearrectangle(0, 641, 1289, 641);//输出区
    clearrectangle(1291, 0, 1400, 720);//输出区

    changeOutput();
    line(1290, 0, 1290, 720);
    outtextxy(1298 , 600, "按钮区");
    line(0, 640, 1290, 640);
    outtextxy(100, 680, "输出区");
    outtextxy(100, 100, "界面显示区");

    outtextxy(300, 200, "欢迎使用模拟操作系统");
    int button_x = 1298, button_y = 0;
    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "文件");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "设备");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "内存");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "进程");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "退出");
    button_y += 80;

    while (true)
    {

        ExMessage me;//定义一个消息变量
        me = getmessage(EM_MOUSE);//获取鼠标消息
        if (me.message == WM_LBUTTONUP)
        {

            button_x = 1298, button_y = 0;
            if (me.x >= button_x && me.y >= button_y  && me.x <= button_x + 100 && me.y <= button_y + 80)
            {
                fileDraw();
                return;

            }
            else if (me.x >= button_x  && me.y >= button_y + 80 && me.x <= button_x + 100 && me.y <= button_y + 80 + 80)
            {
                deviceDraw();
                return;
            }
            else if (me.x >= button_x  && me.y >= button_y + 160 && me.x <= button_x + 100 && me.y <= button_y + 80 + 160)
            {
                memoryDraw();
                return;
            }
            else if (me.x >= button_x  && me.y >= button_y + 240 && me.x <= button_x + 100 && me.y<= button_y + 80 + 240)
            {
                pcbDrawPro();
                return;
            }
            else if (me.x >= button_x  && me.y >= button_y + 320 && me.x <= button_x + 100 && me.y <= button_y + 80 + 320)
            {
                return;
            }




        }


    }










    return;
}



string getInput(string line)
{
    char s[2000] = "";
    string w = (string)s;
    LPCTSTR lpctstr = line.c_str();
    InputBox(s, 100, lpctstr);
    string lineback = s;
    return lineback;
}


/*
clearrectangle(100, 600, 1400, 720);
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
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.y <= button_y + 60)
            {
                string s = getInput("创建文件");
                int flag = CreateTheFile(s);//创建文件
                if (flag == 1)
                {
                    outtextxy(0, 700, "创建成功");
                }
                else
                {
                    outtextxy(0, 700, "创建失败");
                }
                return;

            }
            else if (me.x >= button_x + 120 && me.y >= button_y && me.x <= button_x + 100 + 120 && me.y <= button_y + 60)
            {
                string s = getInput("删除文件");
                int flag = DeleteTheFile(s);//删除文件
                if(flag==1)
                {
                    outtextxy(0, 700, "删除成功");
                }
                else
                {
                    outtextxy(0, 700, "删除失败");
                }
                me = getmessage(EM_MOUSE);//获取鼠标消息
                if (me.message == WM_LBUTTONUP)
                    return;
            }
            else if (me.x >= button_x + 240 && me.y >= button_y && me.x <= button_x + 100 + 240 && me.y <= button_y + 60)
            {
                string s = getInput("读文件");
                int flag = ReadFile(s);
                if (flag == 1)
                {
                    outtextxy(0, 700, "读文件成功");
                }
                else
                {
                    outtextxy(0, 700, "读文件失败");
                }
                //读文件
                return;
            }
            else if (me.x >= button_x + 360 && me.y >= button_y && me.x <= button_x + 100 + 360 && me.y <= button_y + 60)
            {
                string s = getInput("写文件");
                string word = getInput("内容");
                int flag = WriteFile(s,word);//写文件
                if (flag == 1)
                {
                    outtextxy(0, 700, "写文件成功");
                }
                else
                {
                    outtextxy(0, 700, "写文件失败");
                }
                return;
            }
            else if (me.x >= button_x + 480 && me.y >= button_y && me.x <= button_x + 100 + 480 && me.y <= button_y + 60)
            {
                //申请设备
                //return;
            }
            else if (me.x >= button_x + 600 && me.y >= button_y && me.x <= button_x + 100 + 600 && me.y <= button_y + 60)
            {
                //释放设备
                //return;
            }



        }


    }
*/

void changeOutput()
{
    clearrectangle(0, 641, 1289, 720);//输出区、
    outtextxy(0, 700, output);
}

void drawCreatePCB()
{
    
    clearrectangle(0, 0, 1289, 599);//显示区
    //clearrectangle(0, 641, 1289, 641);//输出区
    clearrectangle(1291, 0, 1400, 720);//输出区
    line(1290, 0, 1290, 720);
    line(0, 640, 1290, 640);
    outtextxy(300, 200, "创建进程中");
    int button_x = 1298, button_y = 0;
    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "创建文件");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "删除文件");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "读取文件");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "修改文件");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "申请设备");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "释放设备");
    button_y += 80;

    while (true)
    {

        ExMessage me;//定义一个消息变量
        me = getmessage(EM_MOUSE);//获取鼠标消息
        if (me.message == WM_LBUTTONUP)
        {

            button_x = 1298, button_y = 0;
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.y <= button_y + 80)
            {
                string s = getInput("创建文件");
                int flag = CreateTheFile(s);//创建文件
                if (flag == 1)
                {
                    outtextxy(0, 700, "创建成功");
                }
                else
                {
                    outtextxy(0, 700, "创建失败");
                }
                return;

            }
            else if (me.x >= button_x && me.y >= button_y + 80 && me.x <= button_x + 100 && me.y <= button_y + 80 + 80)
            {
                string s = getInput("删除文件");
                int flag = DeleteTheFile(s);//删除文件
                if (flag == 1)
                {
                    outtextxy(0, 700, "删除成功");
                }
                else
                {
                    outtextxy(0, 700, "删除失败");
                }
                return;
            }
            else if (me.x >= button_x && me.y >= button_y + 160 && me.x <= button_x + 100 && me.y <= button_y + 80 + 160)
            {
                string s = getInput("读取文件");
                int flag = ReadFile(s);
                if (flag == 1)
                {
                    outtextxy(0, 700, "读取文件成功");
                }
                else
                {
                    outtextxy(0, 700, "读取文件失败");
                }
                //读文件
                return;
            }
            else if (me.x >= button_x && me.y >= button_y + 240 && me.x <= button_x + 100 && me.y <= button_y + 80 + 240)
            {
                string s = getInput("修改文件");
                string word = getInput("内容");
                int flag = WriteFile(s, word);//写文件
                if (flag == 1)
                {
                    outtextxy(0, 700, "修改文件成功");
                }
                else
                {
                    outtextxy(0, 700, "写文件失败");
                }
                return;
            }
            else if (me.x >= button_x && me.y >= button_y + 320 && me.x <= button_x + 100 && me.y <= button_y + 80 + 320)
            {
                string s = getInput("调用设备");
                int jh = atoi(s.c_str());
                bool flag = acquire_device(totalP, jh);
                if (flag == 1)
                {
                    outtextxy(0, 700, "申请设备成功");
                }
                else
                {
                    outtextxy(0, 700, "申请设备失败");
                }
                return;
            }
            else if (me.x >= button_x && me.y >= button_y + 400 && me.x <= button_x + 100 && me.y <= button_y + 80 + 400)
            {
                string s = getInput("释放设备");
                int jh = atoi(s.c_str());
                bool flag = release_device(totalP, jh);
                if (flag == 1)
                {
                    outtextxy(0, 700, "释放设备成功");
                }
                else
                {
                    outtextxy(0, 700, "释放设备失败");
                }
                return;
            }




        }


    }
}

void pcbDrawPro()
{
    int truesize = 0;
    for (int i = 0; i < totalP; i++)
    {
        if (process[i].pid >= 0)
            if (process[i].state == 1 || process[i].state == 2 || process[i].state == 3)
                truesize += 1;
        if (truesize >= 10)
            break;

    }

    //clearrectangle(0, 0, 1400, 700);
    //initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口

    char s[2000] = "";

    clearrectangle(0, 0, 1289, 639);//显示区
    //clearrectangle(0, 641, 1289, 720);//输出区
    clearrectangle(1291, 0, 1400, 720);//按钮区
    int x, y, z, m, T = 180;
    COLORREF colorThis = WHITE;

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

    strcpy(s, "功能");
    outtextxy(20, 520, s);

    /*for (int i = 0; i < Ready_Process.size(); i++)
    {
        outtextxy(20 + i * 40, 570, Ready_Process.front());
    }*/
    
    line(1290, 0, 1290, 720);
    line(0, 640, 1290, 640);
    //outtextxy(300, 200, "创建进程中");
    int button_x = 1298, button_y = 0;
    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "创建进程");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "时间前进");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "主界面");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "暂停当前");
    outtextxy(button_x + 30, button_y + 50, "进程");
    button_y += 80;


    int arrivetime; // 进程到达时间
    int needtime; // 进程总共需要运行的时间
    int remaintime; // 进程还需运行的时间
    int finishtime; // 进程运行结束的时间

    int order = 0;
    int t = 0;
    for (int num = 0; num < truesize; num++)
    {

        while (true)
        {
            if (process[order].state == READY || process[order].state == RUNNING || process[order].state == BLOCKED)
            {
                t = order;
                order++;
                break;
            }
            else
                order++;
        }

        switch (process[t].state)
        {
        case READY:colorThis = YELLOW; break;
        case RUNNING:colorThis = GREEN; break;
        case BLOCKED:colorThis = RED; break;
        default:break;
        }



        x = 0 + num * 1200 / truesize, y = 120, z = x + 100, m = y + 60;
        settextcolor(WHITE);
        _itoa(process[t].pid, s, 10);
        outtextxy(x + 120, y - 20, s);

        switch (process[t].state)
        {
        case READY:strcpy(s, "就绪"); break;
        case RUNNING:strcpy(s, "运行"); break;
        case BLOCKED:strcpy(s, "阻塞"); break;
        default:break;
        }
        outtextxy(x + 120, m + 40, s);

        _itoa(process[t].size, s, 10);
        outtextxy(x + 120, m + 40 + 60, s);

        setfillcolor(colorThis);

        // 进程到达时间
        _itoa(process[t].arrivetime, s, 10);
        outtextxy(x + 120, m + 40 + 120, s);
        // 进程总共需要运行的时间
        _itoa(process[t].needtime, s, 10);
        outtextxy(x + 120, m + 40 + 180, s);
        // 进程还需运行的时间
        _itoa(process[t].remaintime, s, 10);
        outtextxy(x + 120, m + 40 + 240, s);
        // 进程运行结束的时间
        switch (process[t].command.commandid)
        {
        case 1:strcpy(s, "创建文件"); break;
        case 2:strcpy(s, "删除文件"); break;
        case 3:strcpy(s, "读取文件"); break;
        case 4:strcpy(s, "修改文件"); break;
        case 5:strcpy(s, "申请设备"); break;
        case 6:strcpy(s, "释放设备"); break;
        default :strcpy(s, "无命令"); break;
        }
            
        outtextxy(x + 120, m + 40 + 300, s);


        fillellipse(x + 120, y, z + 120, m);	// 画圆，圆心(200, 200)，半径 100


    }

    while (true)
    {

        ExMessage me;//定义一个消息变量
        me = getmessage(EM_MOUSE);//获取鼠标消息
        if (me.message == WM_LBUTTONUP)
        {

            button_x = 1298, button_y = 0;
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.y <= button_y + 80)
            {
                drawCreatePCB();
                pcbDrawPro();
                return;

            }
            else if (me.x >= button_x && me.y >= button_y + 80 && me.x <= button_x + 100 && me.y <= button_y + 80 + 80)
            {
                letsgo();
                //init_process2();
                pcbDrawPro();
                return;
            }
            else if (me.x >= button_x && me.y >= button_y + 160 && me.x <= button_x + 100 && me.y <= button_y + 80 + 160)
            {
                //退出
                break;
            }
            else if (me.x >= button_x && me.y >= button_y + 240 && me.x <= button_x + 100 && me.y <= button_y + 80 + 240)
            {
                //暂停当前进程
                user_suspend();
                pcbDrawPro();
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
    string w = (string)s;
    int x = 700, y = 300;

    clearrectangle(50, 50, 1289, 639);//显示区
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
    string w = (string)s;
    int x = 700, y = 300;
    clearrectangle(50, 50, 1289, 639);//显示区

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

    //initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素

    char s[2000] = "";
    clearrectangle(0, 0, 1289, 639);//显示区
    //clearrectangle(0, 641, 1289, 720);//输出区
    clearrectangle(1291, 0, 1400, 720);//按钮区
    line(1290, 0, 1290, 720);
    line(0, 640, 1290, 640);
    //outtextxy(300, 200, "创建进程中");
    int button_x = 1298, button_y = 0;
    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "虚拟内存");
    button_y += 80;
    

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "物理内存");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "时间前进");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "主界面");
    button_y += 80;


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

            button_x = 1298, button_y = 0;
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.y <= button_y + 80)
            {
                drawVirMemory();
                

            }
            else if (me.x >= button_x && me.y >= button_y + 80 && me.x <= button_x + 100 && me.y <= button_y + 80 + 80)
            {
                drawPhyMemory();
            }
            else if (me.x >= button_x && me.y >= button_y + 160 && me.x <= button_x + 100 && me.y <= button_y + 80 + 160)
            {
                letsgo();
                memoryDraw();
                return;
            }
            else if (me.x >= button_x && me.y >= button_y + 240 && me.x <= button_x + 100 && me.y <= button_y + 80 + 240)
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
    char s[2000] = "";

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
        if(temp->type==1)
        {
            setfillcolor(WHITE);
            fillellipse(x, y, x + 60, y + 120);
        }
        else
        {
            setfillcolor(GREEN);
            fillellipse(x, y, x + 60, y + 120);
        }
        
        outtextxy(x - 60, y + 80, temp->name);
        temp = temp->nextFCB;

    }
    if (top->type == 0)
    {
        if (strcmp(top->word, "") == 0)
            outtextxy(130, 280, "空");
        else
            outtextxy(130, 280, top->word);

    
    }

}

void fileDraw()
{

    //initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素

    char s[2000] = "";

    clearrectangle(0, 0, 1289, 639);//显示区
    //clearrectangle(0, 641, 1289, 720);//输出区
    clearrectangle(1291, 0, 1400, 720);//按钮区
    line(1290, 0, 1290, 720);
    line(0, 640, 1290, 640);
    //outtextxy(300, 200, "创建进程中");
    int button_x = 1298, button_y = 0;
    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "根目录");
    button_y += 80;


    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "时间前进");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "主界面");
    button_y += 80;


    int x = 700, y = 300;
    COLORREF colorThis;
    int processptr = 0;
    strcpy(s, "文件");
    outtextxy(20, 40, s);

    drawFileMenu(head);

    outtextxy(100, 0, "点击对应子文件切换目录");
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
            
            button_x = 1298, button_y = 0;
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.y <= button_y + 80)
            {
                fileDraw();
                return;


            }
            else if (me.x >= button_x && me.y >= button_y + 80 && me.x <= button_x + 100 && me.y <= button_y + 80 + 80)
            {
                letsgo();
                fileDraw();
                return;
            }
            else if (me.x >= button_x && me.y >= button_y + 160 && me.x <= button_x + 100 && me.y <= button_y + 80 + 160)
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
    changeOutput();
    //initgraph(1400, 720);
    settextcolor(WHITE);// 创建绘图窗口，大小为 640x480 像素
    char s[2000] = "";

    int x, y, z, m, T = 180;
    COLORREF colorThis;
    int processptr = 0;
    strcpy(s, "设备状态");
    outtextxy(20, 150, s);

    strcpy(s, "设备名称");
    outtextxy(20, 220, s);

    strcpy(s, "设备运行队列");
    outtextxy(20, 280, s);

    strcpy(s, "设备等待队列");
    outtextxy(20, 560, s);


    clearrectangle(0, 0, 1289, 639);//显示区
    //clearrectangle(0, 641, 1289, 720);//输出区
    clearrectangle(1291, 0, 1400, 720);//按钮区
    line(1290, 0, 1290, 720);
    line(0, 640, 1290, 640);
    //outtextxy(300, 200, "创建进程中");
    int button_x = 1298, button_y = 0;



    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "时间前进");
    button_y += 80;

    ellipse(button_x, button_y, button_x + 100, button_y + 80);
    outtextxy(button_x + 30, button_y + 30, "主界面");
    button_y += 80;



    for (int i = 0; i < DeviceNum; i++)
    {
        if (Device_Table[i].size_using < Device_Table[i].num)
            colorThis = GREEN;
        else if (Device_Table[i].size_using == Device_Table[i].num && Device_Table[i].size_waiting == 0)
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



        for (int j = 0; j < Device_Table[i].size_using; j++)
        {
            _itoa(Device_Table[i].data_using[j], s, 10);
            outtextxy(x + 120, m + 40 + 60, s);
            m += 40;
            if (j == 5)
                break;
        }
        m = 460;
        for (int j = 0; j < Device_Table[i].size_waiting; j++)
        {
            _itoa(Device_Table[i].data_waiting[j], s, 10);
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
            
            button_x = 1298, button_y = 0;
            if (me.x >= button_x && me.y >= button_y && me.x <= button_x + 100 && me.y <= button_y + 80)
            {
                letsgo();
                deviceDraw();
                return;

            }
            else if (me.x >= button_x && me.y >= button_y + 80 && me.x <= button_x + 100 && me.y <= button_y + 80 + 80)
            {
                //退出
                break;
            }



        }


        
    }
    drawMain();

    return;
}

int main()
{
    srand(time(NULL));
    init_device();
    init_directory();
    init_process();
    InitializeMemory();
    
    for (int i = 0; i < totalP; i++)
    {
        outPinfo(process[i]);
    }
    drawMain();
    return 0;
}
