#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#pragma once
#include<bits/stdc++.h>
using namespace std;
#define deviceNum 3

typedef struct {
    string name;//设备名称
    int *data;//等待队列
    int size;//等待队列大小，为0说明设备空闲
} table;

table Device_Table[deviceNum];//设备表
string deviceName[] = { "mouse", "screen",  "keyboard" };

void device_init();

int device_findNum(string device);//从设备名称获得设备号

void device_showDevice();

bool device_acquire(int pid, int device);//device：请求设备号

bool device_release(int pid, int device);//device：释放设备号，-1代表释放进程占用的全部设备