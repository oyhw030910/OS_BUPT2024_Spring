#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<bits/stdc++.h> 
#define str_lenth 500
using namespace std;
typedef struct FCB
{
	char name[str_lenth];//文件名
	int type;//0普通文件，1目录文件 
	char word[str_lenth];
	struct FCB *nextFCB;
	struct FCB *sonFCB;
}FCB;

FCB *head ;
FCB *target ;
char lastname[80];
char* get_type(string name);//
void init_directory();//初始化存储结构 
int FindFile(FCB father,char * name);//找到对应文件 
int deleFindFile(FCB &father,char * name);
int dele2FindFile(FCB &father,char * name);
char* get_file_name(string name);
char* get_second_name(string name);
int _Find2File(string name);
int wiFindFile(FCB &father,char * name);
char* get_type(string name);
int creaFindFile(FCB father,char * name,char * dir,FCB * new_f);
//以下三个是给外部用的，create中0是普通文件，1是目录文件 
//其中在create路径前输入dir为目录文件，其他为创建普通文件 
int DeleteFile(string name);
int CreateFile(string name); 
int _FindFile(string name);
int WriteFile(string name);
