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
	printf("  ��ӭʹ�õ�����ģ��\n");
	SLL Lhead = NULL;
	Lhead = (SLL)malloc(sizeof(SLLnode));
	InitSLL(&Lhead);
	int e;
	printf("  �������������ݣ�ÿ�����ݼ��ûس�����������0��Ϊֹͣ���룡\n");
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
	printf("\n  ��������������ת���¹��ܣ�\n  1.ͷ������\n  2.����ָ��λ��\n  3.ɾ��ָ��λ��\n  4.����ɾ��\n  5.��ӡ����\n  6.��ż����\n  7.�����е�����\n  8.����Ƿ�ɻ�\n  9.��ת����\n  0.�˳�ϵͳ\n");
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
			printf("  �������������ݣ�ÿ�����ݼ��ûس�����������0��Ϊֹͣ���룡\n");
			scanf_s("%d", &e);
			while (e)
			{
				AddSLL(&Lhead, e);
				scanf_s("%d", &e);
			}
			PriSLL(Lhead);
			break;
		case 2:
			printf("  ������ָ��λ�ã�\n");
			int i;
			scanf_s("%d", &i);
			printf("  ������һ���������ݣ�\n");
			scanf_s("%d", &e);
			InsertSLL(&Lhead, i, e);
			break;
		case 3:
			printf("  ������ָ��λ�ã�\n");
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
			printf("  ��ѡ��תģʽ��\n  1.�ǵݹ鷽ʽ\n  2.�ݹ鷽ʽ\n");
			char m = 0;
			do
			{
				m = _getch();
			} while (m != '1' && m != '2');
			if(m=='1')
				reversalSLL1(&Lhead);
			else
				Lhead->next = reversalSLL2(Lhead->next);
			printf("  ����ǵݹ鷴ת��ɣ�\n");
			break;
		}
		_getch();
		system("cls");
		printf("\n  ��������������ת���¹��ܣ�\n  1.ͷ������\n  2.����ָ��λ��\n  3.ɾ��ָ��λ��\n  4.����ɾ��\n  5.��ӡ����\n  6.��ż����\n  7.�����е�����\n  8.����Ƿ�ɻ�\n  9.��ת����\n  0.�˳�ϵͳ\n");
		do
		{
			n = _getch();
		} while (n < '0' && n > '9');
	}
}

void runDLL()
{
	system("cls");
	printf("  ��ӭʹ��˫������ģ��\n");
	DLL Lhead = NULL;
	Lhead = (DLL)malloc(sizeof(DLLnode));
	InitDLL(&Lhead);
	int e;
	printf("  �������������ݣ�ÿ�����ݼ��ûس�����������0��Ϊֹͣ���룡\n");
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
	printf("\n  ��������������ת���¹��ܣ�\n  1.ͷ������\n  2.����ָ��λ��\n  3.ɾ��ָ��λ��\n  4.����ɾ��\n  5.��ӡ����\n  0.�˳�ϵͳ\n");
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
			printf("  �������������ݣ�ÿ�����ݼ��ûس�����������0��Ϊֹͣ���룡\n");
			scanf_s("%d", &e);
			while (e)
			{
				AddDLL(&Lhead, e);
				scanf_s("%d", &e);
			}
			PriDLL(Lhead);
			break;
		case 2:
			printf("  ������ָ��λ�ã�\n");
			int i;
			scanf_s("%d", &i);
			printf("  ������һ���������ݣ�\n");
			scanf_s("%d", &e);
			InsertDLL(&Lhead, i, e);
			break;
		case 3:
			printf("  ������ָ��λ�ã�\n");
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
		printf("\n  ��������������ת���¹��ܣ�\n  1.ͷ������\n  2.����ָ��λ��\n  3.ɾ��ָ��λ��\n  4.����ɾ��\n  5.��ӡ����\n  0.�˳�ϵͳ\n");
		do
		{
			n = _getch();
		} while (n < '0' && n > '9');
	}
}