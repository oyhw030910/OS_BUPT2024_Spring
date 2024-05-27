#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<bits/stdc++.h> 
using namespace std;
typedef struct FCB
{
	char *name;//文件名
	int type;//0普通文件，1目录文件 
	struct FCB *nextFCB;
	struct FCB *sonFCB;
}FCB;

FCB *head ;
FCB *target ;
char dir[80];
char lastname[80];
void init_directory();//初始化存储结构 
int FindFile(FCB father,char * name);//找到对应文件 
int deleFindFile(FCB &father,char * name);
char* get_file_name(string name);
char* get_second_name(string name);
int _Find2File(string name);
//以下三个是给外部用的，create中0是普通文件，1是目录文件 
int DeleteFile(string name);
int CreateFile(string name,int ftype); 
int _FindFile(string name);
