#include "ADTSingleLinkList.h"
#include "ADTDoubleLinkList.h"
#include "SLLexchange.h"
#include "SLLmiddle.h"
#include "SLLcycle.h"
#include "SLLreversal.h"
#include <Windows.h>

void runSLL()
{
	system("cls");
	printf("  欢迎使用单链表模块\n");
	SLL Lhead = NULL;
	Lhead = (SLL)malloc(sizeof(SLLnode));
	InitSLL(&Lhead);
	int e;
	printf("  请输入整型数据，每个数据间用回车隔开，输入0即为停止输入！\n");
	scanf_s("%d", &e);
	while (e)
	{
		AddSLL(&Lhead, e);
		scanf_s("%d", &e);
	}
	PriSLL(Lhead);
	_getch();
	system("cls");
	char n;
	printf("\n  请输入数字以跳转以下功能：\n  1.头插链表\n  2.插入指定位置\n  3.删除指定位置\n  4.整表删除\n  5.打印链表\n  6.奇偶调换\n  7.查找中点数据\n  8.检测是否成环\n  9.反转链表\n  0.退出系统\n");
	do
	{
		n = _getch();
	} while (n < '0' && n > '9');
	while (1)
	{
		printf("\n");
		n = n - '0';
		switch (n)
		{
		case 0:
			exit(0);
		case 1:
			printf("  请输入整型数据，每个数据间用回车隔开，输入0即为停止输入！\n");
			scanf_s("%d", &e);
			while (e)
			{
				AddSLL(&Lhead, e);
				scanf_s("%d", &e);
			}
			PriSLL(Lhead);
			break;
		case 2:
			printf("  请输入指定位置：\n");
			int i;
			scanf_s("%d", &i);
			printf("  请输入一个整型数据：\n");
			scanf_s("%d", &e);
			InsertSLL(&Lhead, i, e);
			break;
		case 3:
			printf("  请输入指定位置：\n");
			scanf_s("%d", &e);
			DelSLL(&Lhead, e);
			break;
		case 4:
			ClearSLL(&Lhead);
			break;
		case 5:
			PriSLL(Lhead);
			break;
		case 6:
			exchangeSLL(&Lhead);
			break;
		case 7:
			middleSLL(&Lhead);
			break;
		case 8:
			cycleSLL(&Lhead);
			break;
		case 9:
			printf("  请选择反转模式：\n  1.非递归方式\n  2.递归方式\n");
			char m = 0;
			do
			{
				m = _getch();
			} while (m != '1' && m != '2');
			if(m=='1')
				reversalSLL1(&Lhead);
			else
				Lhead->next = reversalSLL2(Lhead->next);
			printf("  链表非递归反转完成！\n");
			break;
		}
		_getch();
		system("cls");
		printf("\n  请输入数字以跳转以下功能：\n  1.头插链表\n  2.插入指定位置\n  3.删除指定位置\n  4.整表删除\n  5.打印链表\n  6.奇偶调换\n  7.查找中点数据\n  8.检测是否成环\n  9.反转链表\n  0.退出系统\n");
		do
		{
			n = _getch();
		} while (n < '0' && n > '9');
	}
}

void runDLL()
{
	system("cls");
	printf("  欢迎使用双向链表模块\n");
	DLL Lhead = NULL;
	Lhead = (DLL)malloc(sizeof(DLLnode));
	InitDLL(&Lhead);
	int e;
	printf("  请输入整型数据，每个数据间用回车隔开，输入0即为停止输入！\n");
	scanf_s("%d", &e);
	while (e)
	{
		AddDLL(&Lhead, e);
		scanf_s("%d", &e);
	}
	PriDLL(Lhead);
	_getch();
	system("cls");
	char n;
	printf("\n  请输入数字以跳转以下功能：\n  1.头插链表\n  2.插入指定位置\n  3.删除指定位置\n  4.整表删除\n  5.打印链表\n  0.退出系统\n");
	do
	{
		n = _getch();
	} while (n < '0' && n > '5');
	while (1)
	{
		printf("\n");
		n = n - '0';
		switch (n)
		{
		case 0:
			exit(0);
		case 1:
			printf("  请输入整型数据，每个数据间用回车隔开，输入0即为停止输入！\n");
			scanf_s("%d", &e);
			while (e)
			{
				AddDLL(&Lhead, e);
				scanf_s("%d", &e);
			}
			PriDLL(Lhead);
			break;
		case 2:
			printf("  请输入指定位置：\n");
			int i;
			scanf_s("%d", &i);
			printf("  请输入一个整型数据：\n");
			scanf_s("%d", &e);
			InsertDLL(&Lhead, i, e);
			break;
		case 3:
			printf("  请输入指定位置：\n");
			scanf_s("%d", &e);
			DelDLL(&Lhead, e);
			break;
		case 4:
			ClearDLL(&Lhead);
			break;
		case 5:
			PriDLL(Lhead);
			break;
		}
		_getch();
		system("cls");
		printf("\n  请输入数字以跳转以下功能：\n  1.头插链表\n  2.插入指定位置\n  3.删除指定位置\n  4.整表删除\n  5.打印链表\n  0.退出系统\n");
		do
		{
			n = _getch();
		} while (n < '0' && n > '9');
	}
}