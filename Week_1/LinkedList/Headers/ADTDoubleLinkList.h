#include <stdio.h>
#include <stdlib.h>
//����DoubleLinkList
typedef struct DLLnode
{
	int data;
	struct DLLnode* prior;
	struct DLLnode* next;
}DLLnode, * DLL;
//��ʼ��˫����
int InitDLL(DLL* L)
{
	*L = (DLL)malloc(sizeof(DLLnode));
	if (!(*L))
		return 0;
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return 1;
}
//˫����ͷ��
void AddDLL(DLL* L, int e)
{
	DLL p;
	p = (DLL)malloc(sizeof(DLLnode));
	if ((*L)->next != NULL)
	{
		DLL q = (*L)->next;
		p->prior = (*L);
		p->next = q;
		(*L)->next = p;
		q->prior = p;
		p->data = e;
	}
	else
	{
		(*L)->next = p;
		p->prior = (*L);
		p->data = e;
		p->next = NULL;
	}
}
//˫�������
int InsertDLL(DLL* L, int i, int e)
{
	int j;
	DLL p, q;
	p = *L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		printf("  ��λ�ò����ڣ�\n");
		return 0;
	}
	q = (DLL)malloc(sizeof(DLLnode));
	q->data = e;
	q->next = p->next;
	p->next = q;
	q->prior = p;
	p = q->next;
	p->prior = q;
	return 1;
}
//˫����ɾ��
int DelDLL(DLL* L, int i)
{
	int j;
	DLL p, temp;
	p = *L;
	j = 1;
	while (p->next && j < i)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i)
	{
		printf("  �޷��ҵ���Ԫ�أ�\n");
		return 0;
	}
	temp = p->next;
	if (temp->next)
	{
		p->next = temp->next;
		p = p->next;
		p->prior = temp->prior;
		free(temp);
	}
	else
	{
		p->next = NULL;
		free(temp);
	}
}
//˫�����ӡ
void PriDLL(DLL L)
{
	DLL p = L->next;
	printf("  Ŀǰ����Ϊ��\n  ");
	while (p)
	{
		printf(" %d ", p->data);
		p = p->next;
	}
}
//˫��������ɾ��
void ClearDLL(DLL* L)
{
	DLL p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
}