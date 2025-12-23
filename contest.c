int modifyStudent(Student arr[], int count, char *id)
{
    int index = queryStudent(arr, count, id);
    if (index == -1)
    {
        return -1;
    }

    clearInputBuffer();

    printf("\n请输入该学生的新信息：\n");
    printf("新姓名：");
    fgets(arr[index].name, sizeof(arr[index].name), stdin);
    arr[index].name[strcspn(arr[index].name, "\n")] = '\0';

    printf("新年龄：");
    scanf("%d", &arr[index].age);
    clearInputBuffer();

    printf("新成绩：");
    scanf("%f", &arr[index].score);
    clearInputBuffer();

    printf("\n学生信息修改成功！\n修改后的信息：\n");
    printf("ID:%s\n Name:%s\n Age:%d\n Score:%.2f\n", arr[index].id, arr[index].name, arr[index].age, arr[index].score);
    return index;
}
#define _CRT_SECURE_NO_WARNINGS
#include "contest.h"
void ADD(node** phead)
{
	node* new = malloc(sizeof(node));
	if (new == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	printf("请输入姓名\n");
	scanf("%s", new->name);
	printf("请输入号码\n");
	scanf("%s", new->tele);
	if (*phead == NULL)
	{
		*phead = new;
		new->next = NULL;
	}
	else
	{
		node* p = *phead;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = new;
		new->next = NULL;
	}
	printf("联系人添加完毕\n");
	num++;
}
node* get(node**phead)
{
	if (*phead == NULL)
	{
		printf("链表为空，无联系人可操作！\n");
		return NULL;
	}
	char goatname[20] = { 0 };
	printf("请输入要操作的联系人姓名\n");
	scanf("%s", goatname);
	node* p = *phead;
	if (strcmp(goatname, p->name)==0)
	{
		return p;
	}
	while (p->next!= NULL &&strcmp(goatname, (p->next)->name)!=0)
	{
		p = p->next;
	}
	if (p->next== NULL)
	{
		printf("不存在此联系人\n");
		return NULL;
	}
	else
	{
		return p;
	}
}
void DELE(node** phead)
{
	if (*phead == NULL)
	{
		printf("暂无联系人数据\n");
		return ;
	}
	//写一个查找函数
	node* re = get(phead);
	if (re == NULL)
	{
		return;
	}
	else if (re == *phead)
	{
		node* temp = (*phead)->next;
		*phead=temp;
		free(re);
	}
	else
	{
		node* temp = re->next;
		re->next= (re->next)->next;
		free(temp);
		temp= NULL;
	}
	printf("删除完毕\n");
	num--;
}
void SEAR(node** phead)
{
	if (*phead == NULL)
	{
		printf("暂无联系人数据\n");
		return;
	}
	node* re = get(phead);
	if (re == NULL)
	{
		return;
	}
	else if (re ==*phead)
	{
		printf("姓名:  %s\n号码:   %s\n", re->name, re->tele);
		return;
	}
	else
	{
		printf("姓名:  %s\n号码:   %s\n", (re->next)->name, (re->next)->tele);
	}
}
void UPDATE(node** phead)
{
	if (*phead == NULL)
	{
		printf("暂无联系人数据\n");
		return;
	}
	node* re = get(phead);
	if (re == NULL)
	{
		return;
	}
	else if (re==*phead)
	{
		printf("请输入新的号码\n");
		scanf("%s", re->tele);
	}
	else
	{
		printf("请输入新的号码\n");
		scanf("%s", (re->next)->tele);
	}
}
void SHOW(node** phead)
{
	if (*phead == NULL)
	{
		printf("暂无联系人数据\n");
		return;
	}
	node* p = *phead;
	while (p!= NULL)
	{
		printf("姓名:%s\n号码:%s\n", p->name, p->tele);
		p = p->next;
	}
}
void init(node** phead)
{
	*phead = NULL;
	num = 0;
	printf("初始化完成\n");
}
//void init(node** phead)
//{
//	FILE* tp = fopen("C:\\Users\\28152\\Desktop\\链表通讯录2.txt", "rb");
//	if (tp == NULL)
//	{
//		printf("%s", strerror(errno));
//		return;
//	}
//	fread(&num, sizeof(int), 1, tp);
//	node* new = NULL;
//	node* temp = NULL;//关键指针
//	for (int i = 1; i <= num; i++)
//	{
//		new = calloc(1, sizeof(node));
//		fread(new, sizeof(node), 1, tp);
//		if (*phead == NULL)
//		{
//			*phead = new;
//			temp = new;
//		}
//		else
//		{
//			temp->next = new;
//			temp = new;
//		}
//	}
//	fclose(tp);
//	tp = NULL;
//}
//void savecon(node** phead)
//{
//	if (*phead == NULL)
//	{
//		return;
//	}
//	FILE* tp = fopen("C:\\Users\\28152\\Desktop\\链表通讯录2.txt", "wb");
//	if (tp == NULL)
//	{
//		printf("%s", strerror(errno));
//		return;
//	}
//	fwrite(&num, sizeof(int), 1, tp);
//	node* temp = *phead;
//	while (temp != NULL)
//	{
//		fwrite(temp, sizeof(node), 1, tp);
//		temp = temp->next;
//	}
//	fclose(tp);
//	tp = NULL;

//}

