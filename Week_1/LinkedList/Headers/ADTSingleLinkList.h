#include <stdio.h>
#include <stdlib.h>
//定义SingleLinkList
typedef struct SLLnode
{
    int data;
    struct SLLnode* next;
}SLLnode,*SLL;
//初始化单链表
int InitSLL(SLL* L)
{
    *L = (SLL)malloc(sizeof(SLLnode));
    if (!(*L))
        return 0;
    (*L)->next = NULL;
    return 1;
}
//单链表头插
void AddSLL(SLL* L, int e)
{
	SLL p;
	p = (SLL)malloc(sizeof(SLLnode));
	if ((* L)->next != NULL)
	{
		p->next = (*L)->next;
		(*L)->next = p;
		p->data = e;
	}
	else
	{
		(*L)->next = p;
		p->data = e;
		p->next = NULL;
	}
}
//单链表插入
int InsertSLL(SLL* L, int i, int e)
{
	int j;
	SLL p, q;
	p = *L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		printf("  该位置不存在！\n");
		return 0;
	}
	q= (SLL)malloc(sizeof(SLLnode));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
//单链表删除
int DelSLL(SLL* L, int i)
{
	int j;
	SLL p, temp;
	p = *L;
	j = 1;
	while (p->next && j < i)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i)
	{
		printf("  无法找到该元素！\n");
		return 0;
	}
	temp = p->next;
	p->next = temp->next;
	free(temp);
}
//单链表打印
void PriSLL(SLL L)
{
	SLL p = L->next;
	printf("  目前链表为：\n  ");
	while (p)
	{
		printf(" %d ",p->data);
		p = p->next;
	}
}
//单链表整表删除
void ClearSLL(SLL* L)
{
	SLL p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
}