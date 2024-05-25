
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
    string name;//�豸����
    int *data;//�ȴ�����
    int size;//�ȴ����д�С��Ϊ0˵���豸����
    int num;//�豸��������
} ;

Device Device_Table[DeviceNum];//�豸��
string deviceName[] = { "mouse", "screen",  "keyboard" ,"printer","test1","test2"};
int deviceNum[] ={1,2,1,2,3,4};

void init_device();

// int device_findNum(string device);//���豸���ƻ���豸��

void show_Device();

bool acquire_request(int pid, int device);//device�������豸��

bool release_device(int pid, int device);//device���ͷ��豸�� -1�����ͷŽ���ռ�õ�ȫ���豸

void init_device(){
    for(int i = 0; i < DeviceNum; i++){
        Device_Table[i].name=deviceName[i];
        Device_Table[i].data=nullptr;
        Device_Table[i].size=0;
        Device_Table[i].num=deviceNum[i];
    }
}

// int device_findNum(string device){//���豸���ƻ���豸��
//     for(int i=0;i<DeviceNum; i++){
//         if(strcmp(device,Device_Table[i].name)==0)
//         return i;
//     }
//     return -1;
// }

void show_Device() {
    printf("------------------------------------------------------------------------------\n");
    printf("�豸��״̬���£�\n");
    for (int i = 0; i < DeviceNum; i++) {
        printf("�豸����: %s\n", Device_Table[i].name.c_str());
        int length = Device_Table[i].size;
        int num =Device_Table[i].num;
        if (length == 0) {
            printf("�豸״̬������    ʣ��������%d\n",num);
        } else if(length <= num){
            printf("�豸״̬������ʹ��    ʣ��������%d\n", num-length);
            for(int j =0;j<length;j++){
                printf("����ʹ�����Ľ���Ϊ��%d\n", Device_Table[i].data[0]);
            }
        }else{
            printf("�豸״̬������ʹ��    ʣ��������0\n");
            for(int j =0;j<num;j++){
                printf("����ʹ�����Ľ���Ϊ��%d\n", Device_Table[i].data[0]);
            }
            printf("�豸�ȴ�����:");
            for (int j = num; j < length; j++) {
                printf(" %d\n", Device_Table[i].data[j]);
            }
        }
    }
    printf("------------------------------------------------------------------------------");
}

bool acquire_request(int pid, int device) {//device�������豸��
    for (int i = 0; i < Device_Table[device].size; i++) {
        if (Device_Table[device].data[i] == pid) {
            return false;//�ظ�����
        }
    }
    Device_Table[device].data = (int *)realloc(Device_Table[device].data, (Device_Table[device].size + 1) * sizeof(int));
    Device_Table[device].data[Device_Table[device].size] = pid;
    Device_Table[device].size++;
    if (Device_Table[device].size > Device_Table[device].num) {
        return false; // ���̼���ȴ�����
    } else {
        return true; //����ʹ���豸
    }
}

bool release_device(int pid, int device) {//device���ͷ��豸�� -1�����ͷŽ���ռ�õ�ȫ���豸
    if (device == -1) { // �ͷŸý��������ȫ���豸
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
    } else {//�ͷ���ָ���豸
        for (int i = 0; i < Device_Table[device].size; i++) {
            if (Device_Table[device].data[i] == pid) {
                for (int j = i; j < Device_Table[device].size - 1; j++) {
                    Device_Table[device].data[j] = Device_Table[device].data[j + 1];
                }
                Device_Table[device].size--;
                Device_Table[device].data = (int*)realloc(Device_Table[device].data, Device_Table[device].size * sizeof(int));
                if (Device_Table[device].size != 0) { // ���ý��̹���ӿڣ�����ȴ������еĵ�һ������
                    printf("�ڴ˴����ý��̽ӿ�");
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