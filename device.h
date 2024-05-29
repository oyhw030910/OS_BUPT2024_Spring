#pragma once
#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#define DeviceNum 6
#define MOUSE 0
#define SCREEN 1
#define KEYBOARD 2
#define PRINTER 3
#define TESTDEVICE1 4
#define TESTDEVICE2 5

struct Device{
    string name;//设备名称
    int *data_using;//运行队列 （包含正在使用的进程） 
    int size_using;//运行队列大小 
    int *data_waiting;//等待队列（包含不能使用被阻塞掉的进程） 
    int size_waiting;//等待队列大小
    int num;//设备最大可用数量
    bool isonly;//设备是否独占，独占为1，非独占为0
} ;

Device Device_Table[DeviceNum];//设备表
string deviceName[] = { "mouse", "screen",  "keyboard" ,"printer","test1","test2"};
int deviceNum[] ={1,2,1,2,3,4};
bool ison[] ={0,1,0,1,1,1} ;

void init_device();

// int device_findNum(string device);//从设备名称获得设备号

void show_Device();

bool acquire_device(int pid, int device);//device：请求设备号

bool release_device(int pid, int device);//device：释放设备号 -1代表释放进程占用的全部设备
