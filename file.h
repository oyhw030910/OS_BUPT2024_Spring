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
	struct FCB *nextFCB;
	struct FCB *sonFCB;
}FCB;

typedef struct stack
{
	FCB * a;
	int top;
	int capacity;
}ST;

FCB *head ;
void STInit(ST* pst);//初始化栈 
void init_directory();//初始化存储结构 
void STPush(ST* pst,FCB x);//入栈 
void STPop(ST* pst);//出栈 
bool STEmpty(ST* pst);//检测是否空，栈为空返回true,不为空返回false
int FindFile(FCB father,char * name,ST *FCBst);//找到对应文件 
