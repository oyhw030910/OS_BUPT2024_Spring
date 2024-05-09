#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct FCB
{
	char *name;//�ļ���
	int type;
	int node_num;//�ӽ���������ͨ�ļ�Ϊ0
	FILE file;//�ļ�����
	struct FCB *nextFCB;
	struct FCB *sonFCB;
}FCB;

FCB init_directory(struct FCB total_directory);//��ʼ���洢�ṹ 
void CreateFile(FCB root,char * filename);//��fatherĿ¼�´����ļ� 
void DeleteFile(FCB file);//ɾ����
void Rename(FCB file);//�޸�Ŀ¼�� 
void Dir_ls(FCB file);//�г�����Ŀ¼�� 
int FindFile(FCB *father,char * name);//�ҵ���Ӧ�ļ� 
int FindFile_c(FCB father,char * name,char * newname);
int main()
{	
	struct FCB total_directory,temp;//��Ŀ¼ 
	struct FCB * a;
	int flag=0;
	char * name;
	name = "f3";
	total_directory = init_directory(total_directory);
	printf("%s",total_directory.sonFCB->sonFCB->nextFCB->nextFCB->name);
	a = total_directory.sonFCB;
	printf("\n%s ****\n",a->name);
	//CreateFile(total_directory,name);
	flag = FindFile(&total_directory,name);
	printf("%d",flag);
	return 0; 
} 

int FindFile(FCB *father,char * name)
{
	
	int flag = 0;

	if(!strcmp(name,father->name))//��ǰ�ļ�Ϊ�����ļ�
	{
		flag = 1;
		return flag;
	}
	else//���ǵĻ���������� 
	{
		if(father->sonFCB != NULL)//���� 
		{
			printf("%s\n",father->name);
			
			flag = FindFile(father->sonFCB,name);
			
			if(flag == 1)
				return flag;
		}
		
		if(father->nextFCB != NULL)//���ֵ�
		{
			printf("%s      111\n",father->name);
			flag = FindFile(father->nextFCB,name);
			if(flag == 1)
				return flag;
		}
		
		return flag;
	}
	
	
}

int FindFile_c(FCB father,char * name,char * newname)
{
	int flag = 0;
	FCB temp = *father.sonFCB;
	FCB newfcb;
	
	if(strcmp(name,father.name))//��ǰ�ļ�Ϊ�����ļ�
	{
		
		flag = 1;
		while(temp.nextFCB!=NULL)
			temp = *temp.nextFCB;
		newfcb.name = newname;
		newfcb.sonFCB = NULL;
		newfcb.nextFCB = NULL;
		*temp.nextFCB = newfcb;
		return 1;
	}
	else//���ǵĻ���������� 
	{
		if(father.sonFCB!=NULL)//���� 
		{
			flag = FindFile(father.sonFCB,name);
			if(flag == 1)
				return 1;
		}
		if(father.nextFCB!=NULL)
		{
			flag = FindFile(father.nextFCB,name);
			if(flag == 1)
				return 1;
		}
	}
	return flag;
	
}
/*void CreateFile(FCB root,char * filename)
{
	int i = 0;
	char * location;
	
	i = FindFile(root,filename);
	if(i==1)
	{
		printf("There has a file with the same name./n");//���� 
		return;
	}
	printf("1");
	
	scanf("input the directory:%s/n",&location);
	printf("%s",location);
	i = FindFile_c(root,location,filename);
	
	
}
*/
FCB init_directory(struct FCB total_directory)
{
	FCB father1,father2,father3,temp;//Ŀ¼�ļ�
	FCB f1,f2,f3,f4,f5; 
	//��ʼ��Ŀ¼�ļ� 
	total_directory.name = "total";
	total_directory.type = 1;
	total_directory.node_num = 2;
	
	father1.name="father1";
	father1.type = 1;
	father1.node_num = 3;
	
	father2.name="father2";
	father2.type = 1;
	father2.node_num = 2;
	
	father3.name="father3";
	father3.type = 1;
	father3.node_num = 1;
	
	f1.name = "f1";
	f1.type = 0;
	
	f2.name = "f2";
	f2.type = 0;
	
	f3.name = "f3";
	f3.type = 0;
	
	f4.name = "f4";
	f4.type = 0;
	
	f5.name = "f5";
	f5.type = 0;
	
	total_directory.sonFCB = &father1;	
	father1.nextFCB = &father2;
	father1.sonFCB = &f1;
	f1.nextFCB = &f2;
	f2.nextFCB = &f3;
	father2.sonFCB = &f4; 
	f4.nextFCB = &father3;
	father3.sonFCB = &f5;
	
	total_directory.nextFCB = NULL;
	f1.sonFCB = NULL;
	f2.sonFCB = NULL;
	f3.sonFCB = NULL;
	f4.sonFCB = NULL;
	f5.sonFCB = NULL;
	father2.nextFCB = NULL;
	father3.nextFCB = NULL;
	f3.nextFCB = NULL;
	f5.nextFCB = NULL;
	temp = *total_directory.sonFCB;

	return total_directory;
}

