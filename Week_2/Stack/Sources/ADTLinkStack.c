#include "ADTLinkStack.h"
#include <stdio.h>
#include <stdlib.h>

//��ջ
//��ʼ��ջ
Status initLStack(LinkStack* s)
{
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!s->top)
        return ERROR;
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) 
{
    if (s->count == 0)
        return SUCCESS;
    else
        return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) 
{
    if (s->top == NULL)
        return ERROR;
    else
        *e = s->top->data;
    return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack* s) 
{
    LinkStackPtr p, temp;
    p = s->top;
    while (p)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
    s->count = 0;
    return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack* s)
{
    clearLStack(&s);
    free(s->top);
    return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) 
{
    *length=s->count;
    return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType e)
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->count++;
    return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data) 
{
    LinkStackPtr p;
    if (isEmptyLStack(&s))
        return ERROR;
    *data = s->top->data;
    p = s->top;
    s->top = s->top->next;
    free(p);
    s->count--;
    return SUCCESS;
}

//��ӡ��ջ
Status printLStack(LinkStack s)
{
    LinkStackPtr p;
    p = s.top;
    while (p)
    {
        printf(" %d ",p->data);
        p = p->next;
    }
    printf("\n");
    return SUCCESS;
}
