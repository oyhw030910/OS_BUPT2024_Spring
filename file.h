#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#include<string>
#include<iostream>
#pragma warning(distable:4996) 
#pragma once
#define str_lenth 500
using namespace std;
typedef struct FCB
{
	char name[str_lenth];//文件名
	int type;//0普通文件，1目录文件 
	char word[str_lenth];

	struct FCB* nextFCB;
	struct FCB* sonFCB;
}FCB;

FCB* head;
FCB* target;
FCB* last_father;//上一级目录
char lastname[80];

FCB* ReturnFather(string name);//返回父目录
char* get_type(string name);//获取文件类型
void init_directory();//初始化存储结构 
int FindFile(FCB father, char* name);//找到对应文件 
int deleFindFile(FCB& father, char* name);//用于dele定位到对应位置
int dele2FindFile(FCB& father, char* name);//dele定位到目录位置
char* get_file_name(string name);
char* get_second_name(string name);
int _Find2File(string name);
int wiFindFile(FCB& father, char* name, const char* s);
char* get_type(string name);
int creaFindFile(FCB father, char* name, char* dir, FCB* new_f);
//以下三个是给外部用的，create中0是普通文件，1是目录文件 
//其中在create路径前输入dir为目录文件，其他为创建普通文件 
int ReadFile(string name);
int DeleteTheFile(string name);
int CreateTheFile(string name);
int _FindFile(string name);
int WriteFile(string name, string word);
