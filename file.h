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
	char *name;//�ļ���
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
void STInit(ST* pst);//��ʼ��ջ 
void init_directory();//��ʼ���洢�ṹ 
void STPush(ST* pst,FCB x);//��ջ 
void STPop(ST* pst);//��ջ 
bool STEmpty(ST* pst);//����Ƿ�գ�ջΪ�շ���true,��Ϊ�շ���false
int FindFile(FCB father,char * name,ST *FCBst);//�ҵ���Ӧ�ļ� 
