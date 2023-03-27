#include <stdio.h>
#include "ADTLinkStack.h"

//��ջ�����
void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void main()
{
	system("cls");
	printf("  ��ӭʹ����ջ\n");
	LinkStack s;
	initLStack(&s);
	int e;
	printf("  �������������ݣ�ÿ�����ݼ��ûس���ո����������0��Ϊֹͣ���룡\n");
	while (scanf_s("%d", &e) != 1)
	{
		printf("  ��������ʹ������������룡\n");
		clear();
	}
	while (e)
	{
		pushLStack(&s, e);
		while (scanf_s("%d", &e) != 1)
		{
			printf("  ��������ʹ������������룡\n");
			clear();
		}
	}
	printf("  ջ��Ԫ������Ϊ��");
	printLStack(s);
	_getch();
	system("cls");
	char n;
	printf("\n  �� ջ  LinkStack\n  ��������������ת���¹��ܣ�\n  1.��ջ\n  2.��ջ\n  3.��ӡ��ջ\n  4.��ⳤ��\n  5.�ж�ջ�Ƿ�Ϊ��\n  6.�õ�ջ��Ԫ��\n  7.���ջ\n  0.�˳�ϵͳ\n");
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
			printf("  �������������ݣ�ÿ�����ݼ��ûس���ո����������0��Ϊֹͣ���룡\n");
			while (scanf_s("%d", &e) != 1)
			{
				printf("  ��������ʹ������������룡\n");
				clear();
			}
			while (e)
			{
				pushLStack(&s, e);
				while (scanf_s("%d", &e) != 1)
				{
					printf("  ��������ʹ������������룡\n");
					clear();
				}
			}
			printf("  ջ��Ԫ������Ϊ��");
			printLStack(s);
			break;
		case 2:
			popLStack(&s, &e);
			printf("  ��ջԪ��Ϊ��%d\n", e);
			printf("  ջ��Ԫ������Ϊ��");
			printLStack(s);
			break;
		case 3:
			printf("  ջ��Ԫ������Ϊ��");
			printLStack(s);
			break;
		case 4:
			LStackLength(&s, &e);
			printf("  ��ǰջ�ĳ���Ϊ��%d\n", e);
			break;
		case 5:
			printf("  �ж�ջ���Ƿ�Ϊ�գ�%d ���ǿ�Ϊ0����Ϊ1��\n",isEmptyLStack(&s));
			break;
		case 6:
			getTopLStack(&s, &e);
			printf("  ջ��Ԫ��Ϊ��%d\n", e);
			break;
		case 7:
			clearLStack(&s);
			printf("  ջ����գ�\n");
			break;
		}
		_getch();
		system("cls");
		printf("\n  �� ջ  LinkStack\n  ��������������ת���¹��ܣ�\n  1.��ջ\n  2.��ջ\n  3.��ӡ��ջ\n  4.��ⳤ��\n  5.�ж�ջ�Ƿ�Ϊ��\n  6.�õ�ջ��Ԫ��\n  7.���ջ\n  0.�˳�ϵͳ\n");
		do
		{
			n = _getch();
		} while (n < '0' && n > '7');
	}
}