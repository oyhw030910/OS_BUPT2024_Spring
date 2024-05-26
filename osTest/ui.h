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



void drawMain();//绘制主界面

string getInput(string line);//ui界面提示用户输入，返回值为string

void changepcb(PCB process[]);//测试函数

void drawCreatePCB();//用户新增进程的交互

void pcbDrawPro(PCB process[]);//绘制进程界面

void InitializeMemory();//测试

void drawVirMemory();//绘制虚拟内存
void drawPhyMemory();//绘制物理内存
void memoryDraw();//绘制内存界面


void init_directory();//测试

int size1(FCB* a);//获取a的子文件数量
void drawFileMenu(FCB* head);//绘制以head为父文件夹的子文件
void fileDraw();//绘制文件界面


bool acquire_request(int pid, int device);//test
void init_device();//test

void deviceDraw();//绘制设备界面

