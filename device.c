#include<device.h>

void device_init(){
    for(int i = 0; i < deviceNum; i++){
        Device_Table[i].name=deviceName[i];
        Device_Table[i].data=null;
        Device_Table[i].size=0;
    }
}

int device_findNum(string device){//从设备名称获得设备号
    for(int i=0;i<deviceNum; i++){
        if(strcmp(device,Device_Table[i].name)==0)
        return i;
    }
    return -1;
}

void device_showDevice() {
    printf("------------------------------------------------------------------------------");
    printf("设备表状态如下：");
    for (int i = 0; i < deviceNum; i++) {
        printf("设备名称: %s", Device_Table[i].name);
        int length = Device_Table[i].size;
        if (length == 0) {
            printf("设备状态：空闲");
        } else {
            printf("设备状态:忙  正在使用它的进程为：%ld", Device_Table[i].data[0]);
            if (length > 1) {
                printf("设备等待队列:");
                for (int j = 1; j < length; j++) {
                    printf(" %ld", Device_Table[i].data[j]);
                }
                printf("");
            }
        }
    }
    printf("------------------------------------------------------------------------------");
}

bool device_acquire(int pid, int device) {//device：请求设备号
    for (int i = 0; i < Device_Table[device].size; i++) {
        if (Device_Table[device].data[i] == pid) {
            return false;//重复请求
        }
    }
    Device_Table[device].data = realloc(Device_Table[device].data, (Device_Table[device].size + 1) * sizeof(int));
    Device_Table[device].data[Device_Table[device].size] = pid;
    Device_Table[device].size++;
    if (Device_Table[device].size > 1) {
        return false; // 进程加入等待队列
    } else {
        return true; //进程使用设备
    }
}

bool device_release(int pid, int device) {//device：释放设备号，-1代表释放进程占用的全部设备
    if (device == -1) { // 释放该进程申请的全部设备
        for (int device = 0; device < deviceNum; device++) {
            for (int i = 0; i < Device_Table[device].size; i++) {
                if (Device_Table[device].data[i] == pid) {
                    for (int j = i; j < Device_Table[device].size - 1; j++) {
                        Device_Table[device].data[j] = Device_Table[device].data[j + 1];
                    }
                    Device_Table[device].size--;
                    Device_Table[device].data = realloc(Device_Table[device].data, Device_Table[device].size * sizeof(int));
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
                Device_Table[device].data = realloc(Device_Table[device].data, Device_Table[device].size * sizeof(int));
                if (Device_Table[device].size != 0) { // 调用进程管理接口，激活等待队列中的第一个进程
                    wakeup(Device_Table[device].data[0]);
                }
                return true;
            }
        }
    }
    return false;
}
