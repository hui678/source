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