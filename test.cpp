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

void init_device(){
    for(int i = 0; i < DeviceNum; i++){
        Device_Table[i].name=deviceName[i];
        Device_Table[i].data_using=0;
        Device_Table[i].data_waiting=0; 
        Device_Table[i].size_using=0;
        Device_Table[i].size_waiting=0;
        Device_Table[i].num=deviceNum[i];
        Device_Table[i].isonly =ison[i];
    }
}



void show_Device() {
    printf("------------------------------------------------------------------------------\n");
    printf("设备表状态如下：\n");
    for (int i = 0; i < DeviceNum; i++) {
    	printf("-----------------------------------\n");
        printf("设备名称: %s\n", Device_Table[i].name.c_str());
        int length1 = Device_Table[i].size_using;
        int length2 = Device_Table[i].size_waiting;
        int num =Device_Table[i].num;
        if (length1 == 0) {
            printf("设备状态：空闲\n");
        } else if(Device_Table[i].isonly==0){
            printf("设备状态：正在使用\n");
            printf("正在使用它的进程为：");
            for(int j =0;j<length1;j++){
                printf("%d  ", Device_Table[i].data_using[j]);
            }
            printf("\n");
        }else{
            printf("设备状态：正在使用    剩余数量：%d\n",num-length1);
            printf("正在使用它的进程为：");
            for(int j =0;j<length1;j++){
                printf("%d  ", Device_Table[i].data_using[j]);
            }
            printf("\n");
            if(length2!=0){
               printf("设备等待队列:");
               for (int j = 0; j < length2; j++) {
                   printf(" %d  ", Device_Table[i].data_waiting[j]);
               }
               printf("\n");
            }
          }
          
    }
    printf("------------------------------------------------------------------------------\n");
}

bool acquire_device(int pid, int device) {//device：请求设备号
    //若为独占且运行队列已满 ，进程加入等待队列中 
    if ((Device_Table[device].isonly==1)&&(Device_Table[device].size_using == Device_Table[device].num)) {
    	Device_Table[device].data_waiting = (int *)realloc(Device_Table[device].data_waiting, (Device_Table[device].size_waiting + 1) * sizeof(int));
        Device_Table[device].data_waiting[Device_Table[device].size_waiting] = pid;
        Device_Table[device].size_waiting++;
    	printf("进程 %d 申请设备 %d 失败\n",pid,device);
        return false; // 进程不能使用设备，被阻塞 
    } else {
    	//否则加入运行队列中 
    	Device_Table[device].data_using = (int *)realloc(Device_Table[device].data_using, (Device_Table[device].size_using + 1) * sizeof(int));
        Device_Table[device].data_using[Device_Table[device].size_using] = pid;
        Device_Table[device].size_using++;
    	printf("进程 %d 申请设备 %d 成功\n",pid,device);
        return true; //进程使用设备
    }
}

bool release_device(int pid, int device) {//device：释放设备号 -1代表释放进程占用的全部设备
    if (device == -1) { // 释放该进程申请的全部设备
        for (int index = 0; index < DeviceNum; index++) {//index代表设备号，遍历所有设备寻找 
            for (int i = 0; i < Device_Table[index].size_using; i++) {//对每一个设备，遍历它的运行队列进行寻找 
                if (Device_Table[index].data_using[i] == pid) {//找到对应进程，通过前移覆盖删除 
                    printf("进程 %d 释放设备 %d\n",pid,index);
                    for (int j = i; j < Device_Table[index].size_using - 1; j++) {
                        Device_Table[index].data_using[j] = Device_Table[index].data_using[j + 1];
                    }
                    Device_Table[index].size_using--;
                    Device_Table[index].data_using = (int*)realloc(Device_Table[index].data_using, Device_Table[index].size_using * sizeof(int));
                    //是否唤醒的判断条件：设备为独占且此时等待队列不为空 
					if ((Device_Table[index].size_waiting!=0)&&Device_Table[index].isonly==1) { // 调用进程管理接口，激活等待队列中的第一个进程
                      //唤醒等待队列中第一个进程，将其从队列中删除 
                      int temp= Device_Table[index].data_waiting[0];
                      for (int j = 0; j < Device_Table[index].size_waiting - 1; j++) {
                        Device_Table[index].data_waiting[j] = Device_Table[index].data_waiting[j + 1];
                        }
                      Device_Table[index].size_waiting--;
                      Device_Table[index].data_waiting = (int*)realloc(Device_Table[index].data_waiting, Device_Table[device].size_waiting * sizeof(int));
					  printf("唤醒进程 %d\n",temp);
                    //wakeupP(temp);
                   }
                }
            }
        }
        return true;
    } else {//释放所指定设备
        for (int i = 0; i < Device_Table[device].size_using; i++) {
            if (Device_Table[device].data_using[i] == pid) {//找到对应进程，通过前移覆盖删除 
                    printf("进程 %d 释放设备 %d\n",pid,device);
                    for (int j = i; j < Device_Table[device].size_using - 1; j++) {
                        Device_Table[device].data_using[j] = Device_Table[device].data_using[j + 1];
                    }
                    Device_Table[device].size_using--;
                    Device_Table[device].data_using = (int*)realloc(Device_Table[device].data_using, Device_Table[device].size_using * sizeof(int));
                    //是否唤醒的判断条件：设备为独占且此时等待队列不为空 
					if ((Device_Table[device].size_waiting!=0)&&Device_Table[device].isonly==1) { // 调用进程管理接口，激活等待队列中的第一个进程
                      //唤醒等待队列中第一个进程，将其从队列中删除 
                      int temp= Device_Table[device].data_waiting[0];
                      for (int j = 0; j < Device_Table[device].size_waiting - 1; j++) {
                        Device_Table[device].data_waiting[j] = Device_Table[device].data_waiting[j + 1];
                        }
                      Device_Table[device].size_waiting--;
                      Device_Table[device].data_waiting = (int*)realloc(Device_Table[device].data_waiting, Device_Table[device].size_waiting * sizeof(int));
					  printf("唤醒进程 %d\n",temp);
                    //wakeupP(temp);
                }
                return true;
            }
        }
    }
    return false;
}


int main(){
    init_device();
    acquire_device(0,0);
    acquire_device(1,0);
    acquire_device(2,1);
    acquire_device(3,1);
    acquire_device(4,1);
    acquire_device(2,2);
    acquire_device(3,2);
    acquire_device(4,3);
    acquire_device(5,3);
    acquire_device(6,3);
    acquire_device(7,3);

    show_Device();
    //release_device(1,0);
    release_device(0,0);
    
    release_device(2,1);
    release_device(3,2);
    release_device(4,3);
    
    acquire_device(9,3);
    release_device(5,3);
    acquire_device(6,3);
    
    show_Device();
    return 0;
}