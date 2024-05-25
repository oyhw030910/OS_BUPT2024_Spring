
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
    int *data;//等待队列
    int size;//等待队列大小，为0说明设备空闲
    int num;//设备可用数量
} ;

Device Device_Table[DeviceNum];//设备表
string deviceName[] = { "mouse", "screen",  "keyboard" ,"printer","test1","test2"};
int deviceNum[] ={1,2,1,2,3,4};

void init_device();

// int device_findNum(string device);//从设备名称获得设备号

void show_Device();

bool acquire_request(int pid, int device);//device：请求设备号

bool release_device(int pid, int device);//device：释放设备号 -1代表释放进程占用的全部设备

void init_device(){
    for(int i = 0; i < DeviceNum; i++){
        Device_Table[i].name=deviceName[i];
        Device_Table[i].data=nullptr;
        Device_Table[i].size=0;
        Device_Table[i].num=deviceNum[i];
    }
}

// int device_findNum(string device){//从设备名称获得设备号
//     for(int i=0;i<DeviceNum; i++){
//         if(strcmp(device,Device_Table[i].name)==0)
//         return i;
//     }
//     return -1;
// }

void show_Device() {
    printf("------------------------------------------------------------------------------\n");
    printf("设备表状态如下：\n");
    for (int i = 0; i < DeviceNum; i++) {
        printf("设备名称: %s\n", Device_Table[i].name.c_str());
        int length = Device_Table[i].size;
        int num =Device_Table[i].num;
        if (length == 0) {
            printf("设备状态：空闲    剩余数量：%d\n",num);
        } else if(length <= num){
            printf("设备状态：正在使用    剩余数量：%d\n", num-length);
            for(int j =0;j<length;j++){
                printf("正在使用它的进程为：%d\n", Device_Table[i].data[0]);
            }
        }else{
            printf("设备状态：正在使用    剩余数量：0\n");
            for(int j =0;j<num;j++){
                printf("正在使用它的进程为：%d\n", Device_Table[i].data[0]);
            }
            printf("设备等待队列:");
            for (int j = num; j < length; j++) {
                printf(" %d\n", Device_Table[i].data[j]);
            }
        }
    }
    printf("------------------------------------------------------------------------------");
}

bool acquire_request(int pid, int device) {//device：请求设备号
    for (int i = 0; i < Device_Table[device].size; i++) {
        if (Device_Table[device].data[i] == pid) {
            return false;//重复请求
        }
    }
    Device_Table[device].data = (int *)realloc(Device_Table[device].data, (Device_Table[device].size + 1) * sizeof(int));
    Device_Table[device].data[Device_Table[device].size] = pid;
    Device_Table[device].size++;
    if (Device_Table[device].size > Device_Table[device].num) {
        return false; // 进程加入等待队列
    } else {
        return true; //进程使用设备
    }
}

bool release_device(int pid, int device) {//device：释放设备号 -1代表释放进程占用的全部设备
    if (device == -1) { // 释放该进程申请的全部设备
        for (int index = 0; index < DeviceNum; index++) {
            for (int i = 0; i < Device_Table[index].size; i++) {
                if (Device_Table[index].data[i] == pid) {
                    for (int j = i; j < Device_Table[index].size - 1; j++) {
                        Device_Table[index].data[j] = Device_Table[index].data[j + 1];
                    }
                    Device_Table[index].size--;
                    Device_Table[index].data = (int*)realloc(Device_Table[index].data, Device_Table[device].size * sizeof(int));
                }
            }
        }
        return true;
    } else {//释放所指定设备
        for (int i = 0; i < Device_Table[device].size; i++) {
            if (Device_Table[device].data[i] == pid) {
                for (int j = i; j < Device_Table[device].size - 1; j++) {
                    Device_Table[device].data[j] = Device_Table[device].data[j + 1];
                }
                Device_Table[device].size--;
                Device_Table[device].data = (int*)realloc(Device_Table[device].data, Device_Table[device].size * sizeof(int));
                if (Device_Table[device].size != 0) { // 调用进程管理接口，激活等待队列中的第一个进程
                    printf("在此处调用进程接口");
                    // wakeup(Device_Table[device].data[0]);
                }
                return true;
            }
        }
    }
    return false;
}



int main(){
    init_device();
    acquire_request(0,0);
    acquire_request(1,0);
    acquire_request(2,1);
    acquire_request(2,2);
    show_Device();
    release_device(0,0);
    release_device(2,-1);
    show_Device();
    return 0;
}