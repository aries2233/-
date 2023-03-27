#include <stdio.h>
#include "ADTLinkStack.h"

//清空缓冲区
void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void main()
{
	system("cls");
	printf("  欢迎使用链栈\n");
	LinkStack s;
	initLStack(&s);
	int e;
	printf("  请输入整型数据，每个数据间用回车或空格隔开，输入0即为停止输入！\n");
	while (scanf_s("%d", &e) != 1)
	{
		printf("  输入的类型错误，请重新输入！\n");
		clear();
	}
	while (e)
	{
		pushLStack(&s, e);
		while (scanf_s("%d", &e) != 1)
		{
			printf("  输入的类型错误，请重新输入！\n");
			clear();
		}
	}
	printf("  栈中元素依次为：");
	printLStack(s);
	_getch();
	system("cls");
	char n;
	printf("\n  链 栈  LinkStack\n  请输入数字以跳转以下功能：\n  1.入栈\n  2.出栈\n  3.打印链栈\n  4.检测长度\n  5.判断栈是否为空\n  6.得到栈顶元素\n  7.清空栈\n  0.退出系统\n");
	do
	{
		n = _getch();
	} while (n < '0' && n > '7');
	while (1)
	{
		printf("\n");
		n = n - '0';
		switch (n)
		{
		case 0:
			exit(0);
		case 1:
			clear();
			printf("  请输入整型数据，每个数据间用回车或空格隔开，输入0即为停止输入！\n");
			while (scanf_s("%d", &e) != 1)
			{
				printf("  输入的类型错误，请重新输入！\n");
				clear();
			}
			while (e)
			{
				pushLStack(&s, e);
				while (scanf_s("%d", &e) != 1)
				{
					printf("  输入的类型错误，请重新输入！\n");
					clear();
				}
			}
			printf("  栈中元素依次为：");
			printLStack(s);
			break;
		case 2:
			popLStack(&s, &e);
			printf("  出栈元素为：%d\n", e);
			printf("  栈中元素依次为：");
			printLStack(s);
			break;
		case 3:
			printf("  栈中元素依次为：");
			printLStack(s);
			break;
		case 4:
			LStackLength(&s, &e);
			printf("  当前栈的长度为：%d\n", e);
			break;
		case 5:
			printf("  判断栈顶是否为空：%d （非空为0，空为1）\n",isEmptyLStack(&s));
			break;
		case 6:
			getTopLStack(&s, &e);
			printf("  栈顶元素为：%d\n", e);
			break;
		case 7:
			clearLStack(&s);
			printf("  栈已清空！\n");
			break;
		}
		_getch();
		system("cls");
		printf("\n  链 栈  LinkStack\n  请输入数字以跳转以下功能：\n  1.入栈\n  2.出栈\n  3.打印链栈\n  4.检测长度\n  5.判断栈是否为空\n  6.得到栈顶元素\n  7.清空栈\n  0.退出系统\n");
		do
		{
			n = _getch();
		} while (n < '0' && n > '7');
	}
}