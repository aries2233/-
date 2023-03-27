#include <stdio.h>
#include "ADTLQ.h"

//��ջ�����
void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void main()
{
	system("cls");
	printf("  ��ӭʹ�÷�������\n");
	LQueue s;
	InitLQueue(&s);
	while (1)
	{
		if (LengthLQueue(&s) >= 30)
		{
			printf("  �������������ȳ��ӣ�\n");
			break;
		}
		printf("  ������ѡ���������������\n  1.����  2.ʵ��  3.�ַ���\n  0.��������\n");
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
			printf("�����룺");
			while (scanf_s("%d", &e) != 1)
			{
				printf("  ��������ʹ������������룡\n");
				clear();
			}
			EnLQueue(&s, &e);
		}
		else if (type == '2')
		{
			datatype[LengthLQueue(&s)] = type;
			float e;
			printf("�����룺");
			while (scanf_s("%lf", &e) != 1)
			{
				printf("  ��������ʹ������������룡\n");
				clear();
			}
			EnLQueue(&s, &e);
		}
		else if (type == '3')
		{
			datatype[LengthLQueue(&s)] = type;
			char e;
			printf("�����룺");
			while (scanf_s("%c", &e) != 1)
			{
				printf("  ��������ʹ������������룡\n");
				clear();
			}
			EnLQueue(&s, &e);
		}
		clear();
	}
	printf("  ������Ԫ������Ϊ��");
	TraverseLQueue(&s, LPrint);
	_getch();
	system("cls");
	char n;
	printf("\n  ��������  LinkQueue\n  ��������������ת���¹��ܣ�\n  1.���\n  2.����\n  3.��ӡ����\n  4.��ⳤ��\n  5.�ж϶����Ƿ�Ϊ��\n  6.�õ���ͷԪ��\n  7.��ն���\n  0.�˳�ϵͳ\n");
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
					printf("  �������������ȳ��ӣ�\n");
					break;
				}
				printf("  ������ѡ���������������\n  1.����  2.ʵ��  3.�ַ���\n  0.��������\n");
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
					printf("�����룺");
					while (scanf_s("%d", &e) != 1)
					{
						printf("  ��������ʹ������������룡\n");
						clear();
					}
					EnLQueue(&s, &e);
				}
				else if (type == '2')
				{
					datatype[LengthLQueue(&s)] = type;
					float e;
					printf("�����룺");
					while (scanf_s("%lf", &e) != 1)
					{
						printf("  ��������ʹ������������룡\n");
						clear();
					}
					EnLQueue(&s, &e);
				}
				else if (type == '3')
				{
					datatype[LengthLQueue(&s)] = type;
					char e;
					printf("�����룺");
					while (scanf_s("%c", &e) != 1)
					{
						printf("  ��������ʹ������������룡\n");
						clear();
					}
					EnLQueue(&s, &e);
				}
				clear();
			}
			printf("  ������Ԫ������Ϊ��");
			TraverseLQueue(&s, LPrint);
			break;
		case 2:
			datatypeDel(&datatype, &s);
			DeLQueue(&s); 
			printf("  ������Ԫ������Ϊ��");
			TraverseLQueue(&s, LPrint);
			break;
		case 3:
			printf("  ������Ԫ������Ϊ��");
			TraverseLQueue(&s, LPrint);
			break;
		case 4:
			printf("  ��ǰ���еĳ���Ϊ��%d\n", LengthLQueue(&s));
			break;
		case 5:
			printf("  �ж϶����Ƿ�Ϊ�գ�%d ���ǿ�Ϊ0����Ϊ1��\n", IsEmptyLQueue(&s));
			break;
		case 6:
		{
			void* e = 0;
			if (GetHeadLQueue(&s, &e))
			{ }
			else
			{
				printf("  ����������Ԫ�ء�\n");
			}
			break;
		}
		case 7:
			ClearLQueue(&s);
			printf("  ��������գ�\n");
			break;
		}
		_getch();
		system("cls");
		printf("\n  ��������  LinkQueue\n  ��������������ת���¹��ܣ�\n  1.���\n  2.����\n  3.��ӡ����\n  4.��ⳤ��\n  5.�ж϶����Ƿ�Ϊ��\n  6.�õ���ͷԪ��\n  7.��ն���\n  0.�˳�ϵͳ\n");
		do
		{
			n = _getch();
		} while (n < '0' && n > '7');
	}
}