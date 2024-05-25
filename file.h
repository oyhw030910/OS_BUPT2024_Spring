#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<bits/stdc++.h> 
#pragma once
using namespace std;
typedef struct FCB
{
	char *name;//文件名
	int type;//0普通文件，1目录文件 
	struct FCB *nextFCB;
	struct FCB *sonFCB;
}FCB;


FCB *head ;
char lastname[80];
void init_directory();//初始化存储结构 
int FindFile(FCB father,char * name);//找到对应文件 
int _FindFile(string name);
void CreateFile(string name); 
char* get_file_name(string name);
