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
int main()
{	
	int flag=0;
	char * name;
	ST *FCBst;
	STInit(FCBst); 
	name = "father1";
	init_directory();
	flag = FindFile(*head->sonFCB,name,FCBst);
	printf("%d",flag);
	return 0;
} 

int FindFile(FCB father,char * name,ST *FCBst)
{
	int flag = 0;
//	printf("111");
	if(strcmp(name,father.name)==0)//当前文件为所找文件
	{
		STPush(FCBst,father);//入栈 
		flag = 1;
		return 1;
	}
	else//不是的话，深度优先 
	{
		if(father.sonFCB!=NULL)//有子 
		{
			flag = FindFile(*father.sonFCB,name,FCBst);
			if(flag == 1)
			{
				//STPush(FCBst,father);
				return 1;
			}
		}
		if(father.nextFCB!=NULL)
		{
			flag = FindFile(*father.nextFCB,name,FCBst);
			if(flag == 1)
			{
				//STPush(FCBst,father);
				return 1; 
			}
		}
		
	}
	return flag;
	
}
void STInit(ST* pst)
{
	
	pst=(ST*)malloc(sizeof(ST));
	pst->a=(FCB*)malloc(sizeof(FCB));
    pst->a = NULL;//栈底
	
    //top不是数组下标,不能理解成数组下标,因为栈只能拿到栈顶的元素，而数组可以随机访问拿到中间元素
    //pst->top=-1;//指向栈顶元素
    pst->top = 0;//指向栈顶元素的下一个位置
	pst->capacity = 0;
}
 
void STPush(ST* pst,FCB x)
{
	
	pst->a[pst->top] = x;//先放值
	pst->top++;//再++
}
void STPop(ST* pst)
{	
	FCB* temp = NULL;
	pst->a[pst->top] = *temp;
	pst->top--;
}
bool STEmpty(ST* pst)//栈为空返回true,不为空返回false
{
    return pst->top == 0;
}
void init_directory()
{
	head=(FCB*)malloc(sizeof(FCB));
    FCB *father1 = (FCB*)malloc(sizeof(FCB));
    FCB *father2 = (FCB*)malloc(sizeof(FCB));
	 FCB *father3 = (FCB*)malloc(sizeof(FCB));
    FCB *f1 = (FCB*)malloc(sizeof(FCB));
    FCB *f2 = (FCB*)malloc(sizeof(FCB));
	 FCB *f3 = (FCB*)malloc(sizeof(FCB));
    FCB *f4 = (FCB*)malloc(sizeof(FCB));
    FCB *f5 = (FCB*)malloc(sizeof(FCB));
	//初始化目录文件 
	
	head->sonFCB=father1;
	
	head->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(head->name,"head");

    
    father1->name=(char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(father1->name,"father1");

    
    father2->name=(char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(father2->name,"father2");

    
    father3->name=(char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(father3->name,"father3");

    
    f1->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(f1->name, "f1");

    
    f2->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(f2->name, "f2");

    
    f3->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(f3->name, "f3");

    
    f4->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(f4->name, "f4");

    
    f5->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(f5->name, "f5");

	

	father1->nextFCB = father2;
	father1->sonFCB = f1;
	f1->nextFCB = f2;
	f2->nextFCB = f3;
	father2->sonFCB = f4; 
	f4->nextFCB = father3;
	father3->sonFCB = f5;
	
	head->nextFCB = NULL;
	f1->sonFCB = NULL;
	f2->sonFCB = NULL;
	f3->sonFCB = NULL;
	f4->sonFCB = NULL;
	f5->sonFCB = NULL;
	father2->nextFCB = NULL;
	father3->nextFCB = NULL;
	f3->nextFCB = NULL;
	f5->nextFCB = NULL;

}
