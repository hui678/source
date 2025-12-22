#define _CRT_SECURE_NO_WARNINGS
#include "contest.h"
void menu()
{
	printf("**********************日日的通讯录*************************\n");
	printf("**********************1.add2.dele**************************\n");
	printf("**********************3.sear 4.update**********************\n");
	printf("**********************5.show 0.out*************************\n");
}
enum function
{
	Exit,
	Add,
	Dele,
	Sear,
	Update,
	Show,
};
int main()
{
	int input = 0;
	num = 0;
	node* head = NULL;
	//初始化
	init(&head);
	do
	{
		menu();
		while (scanf("%d", &input) != 1)
		{
			printf("请输入功能对应数字\n");
			while (getchar() != '\n');
			menu();
		}
		switch (input)
		{
		case Exit:
			/*savecon(&head);*/
			free(head);
			break;
		case Add:
			ADD(&head);
			break;
		case Dele:
			DELE(&head);
			break;
		case Sear:
			SEAR(&head);
			break;
		case Update:
			UPDATE(&head);
			break;
		case Show:
			SHOW(&head);
			break;
		}
	} while (input);

}
int modifyStudent(Student arr[], int count, char *id)
{
    int index = queryStudent(arr, count, id);
    if (index == -1)
    {
        return -1;
    }

    printf("\n开始修改该学生的信息（直接回车表示保留原信息）：\n");

    char newName[20] = {0};
    int newAge = 0;
    float newScore = 0.0f;
    char tempBuffer[50] = {0};

    printf("原姓名：%s，请输入新姓名：", arr[index].name);
    fgets(tempBuffer, sizeof(tempBuffer), stdin);
    tempBuffer[strcspn(tempBuffer, "\n")] = '\0';
    if (strlen(tempBuffer) > 0)
    {
        strncpy(newName, tempBuffer, sizeof(newName) - 1);
        newName[sizeof(newName) - 1] = '\0';
        strcpy(arr[index].name, newName);
    }

    printf("原年龄：%d，请输入新年龄：", arr[index].age);
    fgets(tempBuffer, sizeof(tempBuffer), stdin);
    tempBuffer[strcspn(tempBuffer, "\n")] = '\0';
    if (strlen(tempBuffer) > 0)
    {
        if (sscanf(tempBuffer, "%d", &newAge) == 1 && newAge > 0 && newAge < 100)
        {
            arr[index].age = newAge;
        }
        else
        {
            printf("年龄输入无效，保留原年龄！\n");
        }
    }

    printf("原成绩：%.2f，请输入新成绩：", arr[index].score);
    fgets(tempBuffer, sizeof(tempBuffer), stdin);
    tempBuffer[strcspn(tempBuffer, "\n")] = '\0';
    if (strlen(tempBuffer) > 0)
    {
        if (sscanf(tempBuffer, "%f", &newScore) == 1 && newScore >= 0.0f && newScore <= 100.0f)
        {
            arr[index].score = newScore;
        }
        else
        {
            printf("成绩输入无效，保留原成绩！\n");
        }
    }

    printf("\n学生信息修改成功！\n");
    printf("修改后的信息：\n");
    printf("ID:%s\n Name:%s\n Age:%d\n Score:%.2f\n", arr[index].id, arr[index].name, arr[index].age, arr[index].score);
    return index;
}
