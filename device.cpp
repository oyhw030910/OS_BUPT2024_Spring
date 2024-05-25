#include<device.h>

void init_device(){
    for(int i = 0; i < DeviceNum; i++){
        Device_Table[i].name=deviceName[i];
        Device_Table[i].data=nullptr;
        Device_Table[i].size=0;
        Device_Table[i].num=deviceNum[i];
        Device_Table[i].isonly =ison[i];
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
            printf("设备状态：空闲\n");
        } else if(Device_Table[i].isonly==1){
            printf("设备状态：正在使用\n");
            printf("正在使用它的进程为：");
            for(int j =0;j<length;j++){
                printf("%d  ", Device_Table[i].data[j]);
            }
            printf("\n");
        }else{
          if(length <= num){
            printf("设备状态：正在使用    剩余数量：%d\n", num-length);
            printf("正在使用它的进程为：");
            for(int j =0;j<length;j++){
                printf("%d  ", Device_Table[i].data[j]);
            }
            printf("\n");
          }else{
            printf("设备状态：正在使用    剩余数量：0\n");
            printf("正在使用它的进程为：");
            for(int j =0;j<length;j++){
                printf("%d  ", Device_Table[i].data[j]);
            }
            printf("\n");
            printf("设备等待队列:");
            for (int j = num; j < length; j++) {
                printf(" %d  ", Device_Table[i].data[j]);
            }
            printf("\n");
          }
        }
        
        
         
    }
    printf("------------------------------------------------------------------------------");
}

bool acquire_device(int pid, int device) {//device：请求设备号
    for (int i = 0; i < Device_Table[device].size; i++) {
        if (Device_Table[device].data[i] == pid) {
            return false;//重复请求
        }
    }
    Device_Table[device].data = (int *)realloc(Device_Table[device].data, (Device_Table[device].size + 1) * sizeof(int));
    Device_Table[device].data[Device_Table[device].size] = pid;
    Device_Table[device].size++;
    if ((Device_Table[device].isonly==0)&&(Device_Table[device].size > Device_Table[device].num)) {
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
