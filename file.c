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
int _FindFile(string name);
int CreateFile(string name,int ftype); 
char* get_file_name(string name);
char* get_second_name(string name);
int _Find2File(string name);
int DeleteFile(string name);
//int main()
//{	
//	int flag = 0;
//	int ftype = 0;
//	string name="head/father1/fff";
//	string name1="head/father1/f2";
//	init_directory();
//	//printf("input the road of file:");
//	//cin >> name;
//	flag = CreateFile(name,ftype);
//	printf("%d\n",flag);
//	flag = _FindFile(name);
//	printf("%d\n",flag);
////	flag =  DeleteFile(name1);
////	printf("%d\n",flag);
////	flag = _FindFile(name1);
////	printf("%d\n",flag);
//
//	return 0;
//} 


char* get_file_name(string name)
{
	const char * name0 = name.data();
	char str[80];
	const char s[2] = "/";  
	char *token=(char*)malloc(sizeof(char));
	char *temp=(char*)malloc(sizeof(char));
	
   /* 获取第一个子字符串 */
	strcpy(str,name0);
	token = strtok(str, s);
   
   /* 继续获取其他的子字符串 */
	while( token != NULL ) 
	{
		strcpy(temp,token);
    	token = strtok(NULL, s);  
	}
  	return temp;
}

char* get_second_name(string name)
{
	const char * name0 = name.data();
	char str[80];
   const char s[2] = "/";  
   char *token=(char*)malloc(sizeof(char));
   char *temp1=(char*)malloc(sizeof(char));
   char *temp2=(char*)malloc(sizeof(char));
   /* 获取第一个子字符串 */
   strcpy(str,name0);
   token = strtok(str, s);
   strcpy(temp1,token);
   /* 继续获取其他的子字符串 */
   while( token != NULL ) 
   {
   		strcpy(temp2,temp1);
		strcpy(temp1,token);
    	token = strtok(NULL, s);
   }
   //strcpy(lastname,temp);

   	
  	return temp2;
}
int _FindFile(string name)
{
	int flag=0;
	char *s=(char*)malloc(sizeof(char));
	s = get_file_name(name);
	strcpy(lastname,s);
	flag = FindFile(*head->sonFCB,lastname);
	return flag;
}


int _Find2File(string name)
{
	int flag=0;
	char *s=(char*)malloc(sizeof(char));
	s = get_second_name(name);
	strcpy(lastname,s);
	flag = FindFile(*head->sonFCB,lastname);	
	return flag;
}


int FindFile(FCB father,char * name)
{
	int flag = 0;
	if(strcmp(name,father.name)==0)//当前文件为所找文件
	{
		flag = 1;
		target->nextFCB = &father;
		return 1;
	}
	else//不是的话，深度优先 
	{
		if(father.sonFCB!=NULL)//有子 
		{
			flag = FindFile(*father.sonFCB,name);
			if(flag == 1)	
			{
				
				return 1;
			}
		}
		if(father.nextFCB!=NULL)
		{
			
			flag = FindFile(*father.nextFCB,name);
			if(flag == 1)
			{
				
				return 1; 
			}
		}
		
	}
	return flag;
	
}
int deleFindFile(FCB &father,char * name)
{
	int flag = 0;

	if(strcmp(name,father.name)==0)//当前文件为所找文件
	{
		flag = 1;
		
		if((father.sonFCB)->nextFCB!=NULL)
			father.sonFCB = (father.sonFCB)->nextFCB;
		else
			father.sonFCB = NULL;
		
		return 1;
	}
	else//不是的话，深度优先 
	{
		if(father.sonFCB!=NULL)//有子 
		{
			flag = deleFindFile(*father.sonFCB,name);
			if(flag == 1)	
			{
				
				return 1;
			}
		}
		if(father.nextFCB!=NULL)
		{
			
			flag = deleFindFile(*father.nextFCB,name);
			if(flag == 1)
			{
				
				return 1; 
			}
		}
		
	}
	return flag;
	
}

int CreateFile(string name,int ftype)
{
	int flag = 0;
	FCB *new_f = (FCB*)malloc(sizeof(FCB));
	char* fname=(char*)malloc(sizeof(char));
	new_f->name=(char*)malloc(sizeof(char));
	char *s =(char*)malloc(sizeof(char));

	s = get_file_name(name);
	strcpy(fname,s);
	
	flag = _FindFile(name);
	if(flag == 1)//有重名
	{
		
		return 0;//创建失败 
	} 
	
	else//无重名
	{
	
		flag = _Find2File(name);
		
		target = target->nextFCB;//目标目录 
		if(target->sonFCB!=NULL)//目标目录有子
		{
			
			target = target->sonFCB;
			
			while(target->nextFCB!=NULL)//不是最后一个son 
			{
				target = target->nextFCB;
			}
			target->nextFCB = new_f;
			strcpy(new_f->name,fname);
			new_f->type = ftype;
			new_f->nextFCB =NULL;
			new_f->sonFCB =NULL;
			return 1;
		 } 
		 else
		 {

		 	target->sonFCB = new_f;
		 	strcpy(new_f->name,fname);
			new_f->type = ftype;
			new_f->nextFCB =NULL;
			new_f->sonFCB =NULL;
			return 1;
		 }
		
		return flag;
	} 
	
}

int DeleteFile(string name)
{
	int flag = 0;
	
	char* fname=(char*)malloc(sizeof(char));
	char* dir=(char*)malloc(sizeof(char));
	FCB * temp =(FCB*)malloc(sizeof(FCB));
	temp->name = (char*)malloc(sizeof(char));
	
	char *s =(char*)malloc(sizeof(char));
	
	s = get_file_name(name);
	
	strcpy(fname,s);
	
	flag = _FindFile(name);
	if(flag == 0)//没有这个文件 	
		return 0;//删除失败 
	else
	{
		
		flag = _Find2File(name);//找到要删除文件的上一级目录 例如：father2/father3 target=father2 
		target = target->nextFCB;// 例如：father2/father3 target=father2 
		
		temp = target->sonFCB;//temp是该目录下第一个子 
		
		
		if(strcmp(temp->name,fname)==0)//第一个子是要删掉的 
		{
			
			if(temp->type == 1)//要删目录 
			{
				if(temp->sonFCB == NULL)//目录为空可以删 
				{
					if(temp->nextFCB == NULL)//如果没有兄弟节点了 
						target->sonFCB = NULL;
					else
						target->sonFCB = temp-> nextFCB;
					return 1;
				}
				else//不为空，不能删 
					return 0;
			}	
			
			else//删普通文件 
			{
				dir = get_second_name(name);
				deleFindFile(*head->sonFCB,dir);
				return 1;
			}
		} 
		else//第一个子不是要删的 
		{
			target = target->sonFCB;
			temp = target->nextFCB;
			while(strcmp( temp ->name,fname)!=0) //直到temp指向要删除的文件 
			{
				target = target->nextFCB;
				temp = target->nextFCB;
			}
			if(temp->type == 1)//要删目录 
			{
				if(temp->sonFCB == NULL)//目录为空可以删 
				{
					if(temp->nextFCB == NULL)
						target->nextFCB = NULL;
					else
						target->nextFCB = temp-> nextFCB;
					return 1;
				}
				else//不为空，不能删 
					return 0;
			}	
			else//删普通文件 
			{
				if(temp->nextFCB == NULL)
					target->nextFCB = NULL;
				else
					target->nextFCB = temp-> nextFCB;
				return 1; 
			}
		}
	 } 
}

void init_directory()
{
	head=(FCB*)malloc(sizeof(FCB));
	target=(FCB*)malloc(sizeof(FCB));
	target->name = (char*)malloc(sizeof(char));
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
