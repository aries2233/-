#include <stdio.h>
#include "ADTTree.h"
#include "ADTs.h"

//清空缓冲区
void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void main()
{
	system("cls");
	printf("  欢迎使用二叉树\n");
	BST T;
	BST_init(&T);
	int e;
	printf("  请输入整型数据以构造新的结点，输入0即为停止！\n");
	BST_insert(&T);
	_getch();
	system("cls");
	char n;
	printf("\n  二叉树\n  请输入数字以跳转以下功能：\n  1.查找数据\n  2.销毁树\n    前序遍历（非递归）\n  4.前序遍历（递归）\n    中序遍历（非递归）\n  6.中序遍历（递归）\n    后序遍历（非递归）\n  8.后序遍历（递归）\n    层序遍历\n  0.退出系统\n");
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
			printf("请输入要查找的数据：");
			while (scanf_s("%d", &e) != 1)
			{
				printf("  输入的类型错误，请重新输入！\n");
				clear();
			}
			BST_search(T, e);
			break;
		case 2:
			BST_delete(&T);
			break;
		case 3:
			/*printf("  前序遍历为：\n");
			BST_preorderI(T);*/
			break;
		case 4:
			printf("  前序遍历为：\n");
			BST_preorderR(T);
			break;
		case 5:
			/*printf("  中序遍历为：\n");
			BST_inorderR(T);*/
			break;
		case 6:
			printf("  中序遍历为：\n");
			BST_inorderR(T);
			break;
		case 7:
			/*printf("  后序遍历为：\n");
			BST_postorderI(T);*/
			break;
		case 8:
			printf("  后序遍历为：\n");
			BST_postorderR(T);
			break;
		case 9:
			/*printf("  层序遍历为：\n");
			BST_levelOrder(T);*/
			break;
		}
		_getch();
		system("cls");
		printf("\n  二叉树\n  请输入数字以跳转以下功能：\n  1.查找数据\n  2.销毁树\n    前序遍历（非递归）\n  4.前序遍历（递归）\n    中序遍历（非递归）\n  6.中序遍历（递归）\n    后序遍历（非递归）\n  8.后序遍历（递归）\n    层序遍历\n  0.退出系统\n");
		do
		{
			n = _getch();
		} while (n < '0' && n > '9');
	}
}