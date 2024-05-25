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
int main()
{	
	int flag=0;
	string name;
	
	init_directory();
	printf("input the road of file:");
	cin >> name;
	
	flag = _FindFile(name);
	printf("%d",flag);
	return 0;
} 
char* get_file_name(string name)
{
	const char * name0 = name.data();
	char str[80];
   const char s[2] = "/";  
   char *token;
   char *temp;
   /* 获取第一个子字符串 */
   strcpy(str,name0);
   token = strtok(str, s);
   
   /* 继续获取其他的子字符串 */
   while( token != NULL ) 
   {
		temp = token;
    	token = strtok(NULL, s);
      
   }
   //strcpy(lastname,temp);
   
  	return temp;
}

char* get_second_name(string name)
{
	const char * name0 = name.data();
	char str[80];
   const char s[2] = "/";  
   char *token;
   char *temp1;
   char *temp2;
   /* 获取第一个子字符串 */
   strcpy(str,name0);
   token = strtok(str, s);
   temp1 = token;
   /* 继续获取其他的子字符串 */
   while( token != NULL ) 
   {
   		temp2 = temp1;
		temp1 = token;
    	token = strtok(NULL, s);
      
   }
   //strcpy(lastname,temp);
   
  	return temp2;
}
int _FindFile(string name)
{
	int flag=0;
	char *s;
	
	//strcpy(lastname,get_file_name(name));
	s = get_file_name(name);
	strcpy(lastname,s);
	printf("%s is filename\n",lastname);
	flag = FindFile(*head->sonFCB,lastname);
	
	return flag;
}
int FindFile(FCB father,char * name)
{
	int flag = 0;
//	printf("111");
	if(strcmp(name,father.name)==0)//当前文件为所找文件
	{
		flag = 1;
		return 1;
	}
	else//不是的话，深度优先 
	{
		if(father.sonFCB!=NULL)//有子 
		{
			flag = FindFile(*father.sonFCB,name);
			if(flag == 1)
			{
				//STPush(FCBst,father);
				return 1;
			}
		}
		if(father.nextFCB!=NULL)
		{
			flag = FindFile(*father.nextFCB,name);
			if(flag == 1)
			{
				//STPush(FCBst,father);
				return 1; 
			}
		}
		
	}
	return flag;
	
}
//void CreateFile(string name)
//{
//	const char * name0 = name.data();
//	char str[80];
//	const char s[2] = "/";  
//	char *token;
//	char *temp;  
//   /* 获取第一个子字符串 */
//	strcpy(str,name0);
//	token = strtok(str, s);
//	temp = get_file_name(name);
//	if(head->sonFCB != NULL)
//		while(head->nextFCB != NULL)
//		{
//			if()
//		}
//}
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
	head->type = 1; 
	head->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(head->name,"head");

    
    father1->name=(char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(father1->name,"father1");
	father1->type = 1;
    
    father2->name=(char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(father2->name,"father2");
	father2->type = 1;
    
    father3->name=(char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(father3->name,"father3");
	father3->type = 1;
    
    f1->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(f1->name, "f1");
	f1->type = 0;
    
    f2->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(f2->name, "f2");
	f2->type = 0;
    
    f3->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(f3->name, "f3");
	f3->type = 0;
    
    f4->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(f4->name, "f4");
	f4->type = 0;
    
    f5->name = (char *)malloc(sizeof(char)*20); // 分配内存
    strcpy(f5->name, "f5");
	f5->type = 0;
	

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
