#include "ADTTree.h"
#include <stdio.h>

Status BST_init(BST* T)
{
	*T = NULL;
	return succeed;
}

Status BST_insert(BST* T)
{
	ElemType ch; 
	while (scanf_s("%d", &ch) != 1)
	{
		printf("  输入的类型错误，请重新输入！\n");
		clear();
	}
	if (ch == 0)
		*T = NULL;
	else
	{
		*T = (BST)malloc(sizeof(BSTNode));
		if (!*T)
			exit(failed);
		(*T)->value= ch; /* 生成根结点 */
		printf("  请输入整型数据以构造新的结点，输入0即为停止！\n");
		BST_insert(&(*T)->left); /* 构造左子树 */
		printf("  请输入整型数据以构造新的结点，输入0即为停止！\n");
		BST_insert(&(*T)->right); /* 构造右子树 */
	}
}

Status BST_delete(BST* T)
{
	if (*T)
	{
		if ((*T)->left) /* 左孩子 */
			BST_delete(&(*T)->left); /* 销毁 */
		if ((*T)->right) /* 右孩子 */
			BST_delete(&(*T)->right); /* 销毁 */
		free(*T); 
		*T = NULL; 
	}
}

Status BST_search(BST T, ElemType e)
{
	if (T == NULL)
		return;
	if (T->value == e)
		printf("  已找到该数据！\n");
	BST_search(T->left,e);
	BST_search(T->right,e);
}

Status BST_preorderI(BST T)
{
	Stack* stack = createStack();
	BST t = T;
	while (t != NULL || !isEmpty(stack))
	{
		while (t != NULL)
		{
			printf("%d ", t->value);
			push(stack, t);
			t = t->left;
		}
		if (!isEmpty(stack))
		{
			t = pop(stack);
			t = t->right;
		}
	}
}

Status BST_preorderR(BST T)
{
	if (T == NULL)
		return;
	printf("%d", T->value);
	BST_preorderR(T->left);
	BST_preorderR(T->right);
}

Status BST_inorderI(BST T)
{
	Stack* stack = createStack();
	BST t = T;
	while (t != NULL || !isEmpty(stack))
 {
		while (t != NULL) 
		{
			push(stack, t);
			t = t->left;
		}

		if (!isEmpty(stack)) {
			t = pop(stack);
			printf("%d ", t->value);
			t = t->right;
		}
	}
}

Status BST_inorderR(BST T)
{
	if (T == NULL)
		return;
	BST_inorderR(T->left);
	printf("%d", T->value);
	BST_inorderR(T->right);
}

Status BST_postorderI(BST T)
{
	Stack* stack = createStack();
	BST t = T;
	int lastVisited = 0;
	while (t != NULL || !isEmpty(stack))
	{
		while (t != NULL)
		{
			push(stack, t);
			t = t->left;
		}
		t = stack->top->treeNode;
		if (t->right == NULL || t->right == lastVisited)
		{
			pop(stack);
			printf("%d ", t->value);
			lastVisited = t;
			t = NULL;
		}
		else
		{
			t = t->right;
		}
	}
}

Status BST_postorderR(BST T)
{
	if (T == NULL)
		return;
	BST_postorderR(T->left);
	BST_postorderR(T->right);
	printf("%d", T->value);
}

Status BST_levelOrder(BST T)
{
	if (T == NULL) {
		return;
	}
	Queue* queue = createQueue();
	enQueue(queue, T);
	while (!isEmptyQ(queue)) {
		BST node = deQueue(queue);
		printf("%d ", node->value);
		if (node->left != NULL) {
			enQueue(queue, node->left);
		}
		if (node->right != NULL) {
			enQueue(queue, node->right);
		}
	}
}