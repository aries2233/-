#include <stdio.h>
#include "ADTTree.h"
#include "ADTs.h"

//��ջ�����
void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void main()
{
	system("cls");
	printf("  ��ӭʹ�ö�����\n");
	BST T;
	BST_init(&T);
	int e;
	printf("  ���������������Թ����µĽ�㣬����0��Ϊֹͣ��\n");
	BST_insert(&T);
	_getch();
	system("cls");
	char n;
	printf("\n  ������\n  ��������������ת���¹��ܣ�\n  1.��������\n  2.������\n    ǰ��������ǵݹ飩\n  4.ǰ��������ݹ飩\n    ����������ǵݹ飩\n  6.����������ݹ飩\n    ����������ǵݹ飩\n  8.����������ݹ飩\n    �������\n  0.�˳�ϵͳ\n");
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
			clear();
			printf("������Ҫ���ҵ����ݣ�");
			while (scanf_s("%d", &e) != 1)
			{
				printf("  ��������ʹ������������룡\n");
				clear();
			}
			BST_search(T, e);
			break;
		case 2:
			BST_delete(&T);
			break;
		case 3:
			/*printf("  ǰ�����Ϊ��\n");
			BST_preorderI(T);*/
			break;
		case 4:
			printf("  ǰ�����Ϊ��\n");
			BST_preorderR(T);
			break;
		case 5:
			/*printf("  �������Ϊ��\n");
			BST_inorderR(T);*/
			break;
		case 6:
			printf("  �������Ϊ��\n");
			BST_inorderR(T);
			break;
		case 7:
			/*printf("  �������Ϊ��\n");
			BST_postorderI(T);*/
			break;
		case 8:
			printf("  �������Ϊ��\n");
			BST_postorderR(T);
			break;
		case 9:
			/*printf("  �������Ϊ��\n");
			BST_levelOrder(T);*/
			break;
		}
		_getch();
		system("cls");
		printf("\n  ������\n  ��������������ת���¹��ܣ�\n  1.��������\n  2.������\n    ǰ��������ǵݹ飩\n  4.ǰ��������ݹ飩\n    ����������ǵݹ飩\n  6.����������ݹ飩\n    ����������ǵݹ飩\n  8.����������ݹ飩\n    �������\n  0.�˳�ϵͳ\n");
		do
		{
			n = _getch();
		} while (n < '0' && n > '9');
	}
}