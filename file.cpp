#include"file.h"
#include"ui.h"

int ReadFile(string name)
{
	
	int flag = 0;
	flag = _FindFile(name);
	
	//clearrectangle(00, 690, 1300, 754);
	/*if (flag == 1)
		outtextxy(50, 700, "1");
	else
		outtextxy(50, 700, "0");*/
	outtextxy(100, 700, "文件名");
	outtextxy(200, 700, (target->nextFCB)->name);
	outtextxy(300, 700, "文件内容");
	outtextxy(400, 700, (target->nextFCB)->word);

	if (flag == 0)
	{
		return flag;
	}
	else
	{
		
		if ((target->nextFCB)->type == 1)//目录
			return 0;
		else
		{
			
			return 1;
		}
	}
}

int WriteFile(string name, string word)
{
	int flag = 0;
	const char* s = (char*)malloc(sizeof(char));
	s = word.data();


	flag = _FindFile(name);
	if (flag == 0)
		return 0;
	else
	{
		flag = wiFindFile(*head->sonFCB, lastname, s);

		return 1;
	}

}

int wiFindFile(FCB& father, char* name, const char* s)
{
	int flag = 0;
	if (strcmp(name, father.name) == 0)//当前文件为所找文件
	{
		flag = 1;
		strcpy(father.word, s);
		//cout << father.word << endl;
		target->nextFCB = &father;
		return 1;
	}
	else//不是的话，深度优先 
	{
		if (father.sonFCB != NULL)//有子 
		{
			flag = wiFindFile(*father.sonFCB, name, s);
			if (flag == 1)
			{

				return 1;
			}
		}
		if (father.nextFCB != NULL)
		{

			flag = wiFindFile(*father.nextFCB, name, s);
			if (flag == 1)
			{

				return 1;
			}
		}

	}
	return flag;
}

char* get_file_name(string name)
{
	const char* name0 = (char*)malloc(sizeof(char));
	name0 = name.data();
	char str[80];
	const char s[2] = "/";
	char* token = (char*)malloc(sizeof(char));
	char* temp = (char*)malloc(sizeof(char));

	/* 获取第一个子字符串 */
	strcpy(str, name0);
	token = strtok(str, s);

	/* 继续获取其他的子字符串 */
	while (token != NULL)
	{
		strcpy(temp, token);
		token = strtok(NULL, s);
	}
	//free(token);
	return temp;
}

char* get_type(string name)
{
	const char* name0 = (char*)malloc(sizeof(char));
	name0 = name.data();
	char str[80];
	const char s[2] = "/";
	char* token = (char*)malloc(sizeof(char));

	/* 获取第一个子字符串 */
	strcpy(str, name0);
	token = strtok(str, s);
	return token;
}

char* get_second_name(string name)
{
	const char* name0 = name.data();
	char str[80];
	const char s[2] = "/";
	char* token = (char*)malloc(sizeof(char));
	char* temp1 = (char*)malloc(sizeof(char));
	char* temp2 = (char*)malloc(sizeof(char));
	/* 获取第一个子字符串 */
	strcpy(str, name0);
	token = strtok(str, s);
	strcpy(temp1, token);
	/* 继续获取其他的子字符串 */
	while (token != NULL)
	{
		strcpy(temp2, temp1);
		strcpy(temp1, token);
		token = strtok(NULL, s);
	}
	//strcpy(lastname,temp);
	//free(temp1);
	//free(token);

	return temp2;
}
int _FindFile(string name)
{

	int flag = 0;
	char* s = (char*)malloc(sizeof(char));
	s = get_file_name(name);
	strcpy(lastname, s);
	//free(s);

	flag = FindFile(*head->sonFCB, lastname);
	
	
	return flag;
}

FCB* ReturnFather(string name)
{
	_Find2File(name);
	last_father = target;
	return last_father;
}

int _Find2File(string name)
{
	int flag = 0;
	char* s = (char*)malloc(sizeof(char));
	s = get_second_name(name);
	strcpy(lastname, s);
	//free(s);
	flag = FindFile(*head->sonFCB, lastname);
	
	return flag;
}


int FindFile(FCB father, char* name)
{
	int flag = 0;
	
	if (strcmp(name, father.name) == 0)//当前文件为所找文件
	{

		flag = 1;

		target->nextFCB = &father;

		return 1;
	}
	else//不是的话，深度优先 
	{
		
		if (father.sonFCB != NULL)//有子 
		{


			flag = FindFile(*father.sonFCB, name);

			
			if (flag == 1)
			{

				return 1;
			}
		}
		if (father.nextFCB != NULL)
		{
			
			flag = FindFile(*father.nextFCB, name);

			
			if (flag == 1)
			{

				return 1;
			}
		}

	}
	return flag;

}

int creaFindFile(FCB father, char* name, char* dir, FCB* new_f)
{
	int flag = 0;
	if (strcmp(dir, father.name) == 0)//当前文件为创建目录 
	{
		flag = 1;

		FCB* temp = (FCB*)malloc(sizeof(FCB));
		if (father.sonFCB != NULL)//目标目录有子
		{

			temp = father.sonFCB;

			while (temp->nextFCB != NULL)//不是最后一个son 
			{
				temp = temp->nextFCB;
			}
			temp->nextFCB = new_f;
			strcpy(new_f->name, name);
			//strcpy(new_f->word, "");
			new_f->nextFCB = NULL;
			new_f->sonFCB = NULL;
			//free(temp);
			return 1;
		}
		else
		{

			father.sonFCB = new_f;
			strcpy(new_f->name, name);
			new_f->nextFCB = NULL;
			new_f->sonFCB = NULL;
			//free(temp);
			return 1;
		}

		return 1;
	}
	else//不是的话，深度优先 
	{
		if (father.sonFCB != NULL)//有子 
		{
			//printf("%s\n",father.name);
			flag = creaFindFile(*father.sonFCB, name, dir, new_f);
			if (flag == 1)
			{

				return 1;
			}
		}
		if (father.nextFCB != NULL)
		{

			flag = creaFindFile(*father.nextFCB, name, dir, new_f);
			if (flag == 1)
			{

				return 1;
			}
		}

	}
	return flag;

}

int CreateTheFile(string name)
{
	int flag = 0;
	int type;
	FCB* new_f = (FCB*)malloc(sizeof(FCB));
	char fname[500], temp[500], dir[500];
	//new_f->name=(char*)malloc(sizeof(char));
	char* s = (char*)malloc(sizeof(char));


	s = get_file_name(name);
	strcpy(fname, s);
	s = get_type(name);
	strcpy(temp, s);
	s = get_second_name(name);
	strcpy(dir, s);
	//free(s);
	if (strcmp(temp, s) == 0)
		new_f->type = 1;
	else
		new_f->type = 0;

	flag = _FindFile(name);
	if (flag == 1)//有重名
	{

		return 0;//创建失败 
	}

	else//无重名
	{

		flag = creaFindFile(*head->sonFCB, fname, dir, new_f);
		return 1;
	}

}

int deleFindFile(FCB& father, char* name)
{
	int flag = 0;
	target->nextFCB = &father;
	if (strcmp(name, father.name) == 0)//当前文件为所找文件
	{
		flag = 1;
		if ((father.sonFCB)->nextFCB != NULL)
			father.sonFCB = (father.sonFCB)->nextFCB;
		else
			father.sonFCB = NULL;
		return 1;
	}
	else//不是的话，深度优先 
	{
		if (father.sonFCB != NULL)//有子 
		{
			flag = deleFindFile(*father.sonFCB, name);
			if (flag == 1)
			{

				return 1;
			}
		}
		if (father.nextFCB != NULL)
		{

			flag = deleFindFile(*father.nextFCB, name);
			if (flag == 1)
			{

				return 1;
			}
		}

	}
	return flag;

}

int dele2FindFile(FCB& father, char* name, char* dir)
{
	int flag = 0;
	target->nextFCB = &father;
	if (strcmp(dir, father.name) == 0)//当前文件为所找文件所在的目录 
	{
		flag = 1;
		FCB* temp = (FCB*)malloc(sizeof(FCB));
		temp = father.sonFCB;
		while (strcmp((temp->nextFCB)->name, name) != 0) //直到temp指向要删除的文件 
		{
			temp = temp->nextFCB;
		}

		if ((temp->nextFCB)->type == 1)//要删目录 
		{
			if ((temp->nextFCB)->sonFCB == NULL)//目录为空可以删 
			{
				if ((temp->nextFCB)->nextFCB == NULL)
					temp->nextFCB = NULL;
				else
					temp->nextFCB = (temp->nextFCB)->nextFCB;
				return 1;
			}
			else//不为空，不能删 
				return 0;
		}
		else//删普通文件 
		{
			if ((temp->nextFCB)->nextFCB == NULL)
			{

				temp->nextFCB = NULL;
			}
			else
			{
				temp->nextFCB = (temp->nextFCB)->nextFCB;

			}
			return 1;
		}

		return 1;
	}
	else//不是的话，深度优先 
	{
		if (father.sonFCB != NULL)//有子 
		{
			flag = dele2FindFile(*father.sonFCB, name, dir);
			if (flag == 1)
			{

				return 1;
			}
		}
		if (father.nextFCB != NULL)
		{

			flag = dele2FindFile(*father.nextFCB, name, dir);
			if (flag == 1)
			{

				return 1;
			}
		}

	}
	return flag;

}
/*int DeleteTheFile(string name)
{
	int flag = 0;

	char fname[500], dir[500];
	FCB* temp = (FCB*)malloc(sizeof(FCB));
	//temp->name = (char*)malloc(sizeof(char));

	char* s = (char*)malloc(sizeof(char));

	s = get_file_name(name);
	strcpy(fname, s);
	s = get_second_name(name);
	strcpy(dir, s);

	flag = _FindFile(name);
	
	//free(s);
	if (flag == 0)//没有这个文件 	
	{
		//printf("file");
		return 0;//删除失败 
	}
	else
	{
		if ((target->nextFCB)->sonFCB != NULL)
			return 0;
		else
		{

			flag = _Find2File(name);//找到要删除文件的上一级目录 例如：father2/father3 target=father2 
			target = target->nextFCB;// 例如：father2/father3 target=father2 
			if (strcmp((target->sonFCB)->name, fname) == 0)//第一个子是要删掉的 
			{
				deleFindFile(*head->sonFCB, dir);

			}
			else//第一个子不是要删的 
			{

				flag = dele2FindFile(*head->sonFCB, fname, dir);

			}
			return 1;
		}



	}
}

*/

int DeleteTheFile(string name)
{
	int flag = 0;

	char fname[500], dir[500];
	FCB* temp = (FCB*)malloc(sizeof(FCB));
	//temp->name = (char*)malloc(sizeof(char));

	char* s = (char*)malloc(sizeof(char));

	s = get_file_name(name);
	strcpy(fname, s);
	s = get_second_name(name);
	strcpy(dir, s);

	flag = _FindFile(name);

	if (flag == 0)//没有这个文件 	
	{
		//printf("file");
		return 0;//删除失败 
	}
	else
	{
		if ((target->nextFCB)->sonFCB != NULL && (target->nextFCB)->type == 1)
			return 0;
		else
		{

			flag = _Find2File(name);//找到要删除文件的上一级目录 例如：father2/father3 target=father2 
			target = target->nextFCB;// 例如：father2/father3 target=father2 

			printf("%s", (target->sonFCB)->name);

			if (strcmp((target->sonFCB)->name, fname) == 0)//第一个子是要删掉的 
			{
				flag = deleFindFile(*head->sonFCB, dir);
				return 1;

			}
			else//第一个子不是要删的 
			{

				flag = dele2FindFile(*head->sonFCB, fname, dir);
				return 1;
			}
		}
	}
}
void init_directory()
{
	head = (FCB*)malloc(sizeof(FCB));
	target = (FCB*)malloc(sizeof(FCB));
	last_father = (FCB*)malloc(sizeof(FCB));
	FCB* father1 = (FCB*)malloc(sizeof(FCB));
	FCB* father2 = (FCB*)malloc(sizeof(FCB));
	FCB* father3 = (FCB*)malloc(sizeof(FCB));
	FCB* f1 = (FCB*)malloc(sizeof(FCB));
	FCB* f2 = (FCB*)malloc(sizeof(FCB));
	FCB* f3 = (FCB*)malloc(sizeof(FCB));
	FCB* f4 = (FCB*)malloc(sizeof(FCB));
	FCB* f5 = (FCB*)malloc(sizeof(FCB));
	//初始化目录文件 

	target->nextFCB = NULL;
	target->sonFCB = NULL;
	last_father->nextFCB = NULL;
	last_father->sonFCB = NULL;

	head->sonFCB = father1;
	head->type = 1;

	strcpy(head->name, "root");

	strcpy(father1->name, "dir1");
	father1->type = 1;


	strcpy(father2->name, "dir2");
	father2->type = 1;


	strcpy(father3->name, "dir3");
	father3->type = 1;

	strcpy(f1->name, "f1");
	f1->type = 0;


	strcpy(f2->name, "f2");
	f2->type = 0;


	strcpy(f3->name, "f3");
	f3->type = 0;


	strcpy(f4->name, "f4");
	f4->type = 0;


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
