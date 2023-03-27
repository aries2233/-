#include <stdio.h>
#include "ADTLQ.h"

//清空缓冲区
void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void main()
{
	system("cls");
	printf("  欢迎使用泛型链队\n");
	LQueue s;
	InitLQueue(&s);
	while (1)
	{
		if (LengthLQueue(&s) >= 30)
		{
			printf("  链队已满，请先出队！\n");
			break;
		}
		printf("  请输入选择输入的数据类型\n  1.整型  2.实型  3.字符型\n  0.不再输入\n");
		do
		{
			type = _getch();
		} while (type < '0' && type > '3');
		if (type == '0')
			break;
		else if (type == '1')
		{
			datatype[LengthLQueue(&s)] = type;
			int e;
			printf("请输入：");
			while (scanf_s("%d", &e) != 1)
			{
				printf("  输入的类型错误，请重新输入！\n");
				clear();
			}
			EnLQueue(&s, &e);
		}
		else if (type == '2')
		{
			datatype[LengthLQueue(&s)] = type;
			float e;
			printf("请输入：");
			while (scanf_s("%lf", &e) != 1)
			{
				printf("  输入的类型错误，请重新输入！\n");
				clear();
			}
			EnLQueue(&s, &e);
		}
		else if (type == '3')
		{
			datatype[LengthLQueue(&s)] = type;
			char e;
			printf("请输入：");
			while (scanf_s("%c", &e) != 1)
			{
				printf("  输入的类型错误，请重新输入！\n");
				clear();
			}
			EnLQueue(&s, &e);
		}
		clear();
	}
	printf("  队列中元素依次为：");
	TraverseLQueue(&s, LPrint);
	_getch();
	system("cls");
	char n;
	printf("\n  泛型链队  LinkQueue\n  请输入数字以跳转以下功能：\n  1.入队\n  2.出队\n  3.打印队列\n  4.检测长度\n  5.判断队列是否为空\n  6.得到队头元素\n  7.清空队列\n  0.退出系统\n");
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
			while (1)
			{
				if (LengthLQueue(&s) >= 30)
				{
					printf("  链队已满，请先出队！\n");
					break;
				}
				printf("  请输入选择输入的数据类型\n  1.整型  2.实型  3.字符型\n  0.不再输入\n");
				do
				{
					type = _getch();
				} while (type < '0' && type > '3');
				if (type == '0')
					break;
				else if (type == '1')
				{
					datatype[LengthLQueue(&s)] = type;
					int e;
					printf("请输入：");
					while (scanf_s("%d", &e) != 1)
					{
						printf("  输入的类型错误，请重新输入！\n");
						clear();
					}
					EnLQueue(&s, &e);
				}
				else if (type == '2')
				{
					datatype[LengthLQueue(&s)] = type;
					float e;
					printf("请输入：");
					while (scanf_s("%lf", &e) != 1)
					{
						printf("  输入的类型错误，请重新输入！\n");
						clear();
					}
					EnLQueue(&s, &e);
				}
				else if (type == '3')
				{
					datatype[LengthLQueue(&s)] = type;
					char e;
					printf("请输入：");
					while (scanf_s("%c", &e) != 1)
					{
						printf("  输入的类型错误，请重新输入！\n");
						clear();
					}
					EnLQueue(&s, &e);
				}
				clear();
			}
			printf("  队列中元素依次为：");
			TraverseLQueue(&s, LPrint);
			break;
		case 2:
			datatypeDel(&datatype, &s);
			DeLQueue(&s); 
			printf("  队列中元素依次为：");
			TraverseLQueue(&s, LPrint);
			break;
		case 3:
			printf("  队列中元素依次为：");
			TraverseLQueue(&s, LPrint);
			break;
		case 4:
			printf("  当前队列的长度为：%d\n", LengthLQueue(&s));
			break;
		case 5:
			printf("  判断队列是否为空：%d （非空为0，空为1）\n", IsEmptyLQueue(&s));
			break;
		case 6:
		{
			void* e = 0;
			if (GetHeadLQueue(&s, &e))
			{ }
			else
			{
				printf("  队列中暂无元素。\n");
			}
			break;
		}
		case 7:
			ClearLQueue(&s);
			printf("  队列已清空！\n");
			break;
		}
		_getch();
		system("cls");
		printf("\n  泛型链队  LinkQueue\n  请输入数字以跳转以下功能：\n  1.入队\n  2.出队\n  3.打印队列\n  4.检测长度\n  5.判断队列是否为空\n  6.得到队头元素\n  7.清空队列\n  0.退出系统\n");
		do
		{
			n = _getch();
		} while (n < '0' && n > '7');
	}
}