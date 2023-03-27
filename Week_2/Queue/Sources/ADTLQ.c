#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "ADTLQ.h" 

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if (!Q->front)
		exit(0);
	Q->front->next = NULL;
	return TRUE;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) 
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return TRUE;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue* Q, void* e) 
{
	Node* p;
	if (Q->front == Q->rear)
		return FALSE;
	printf("  ��ͷԪ��Ϊ��");
	if (datatype[0] == '2')
	{
		memcpy(e, Q->front->next->data, sizeof(double));
		printf("%.3lf\n", *(double*)e);
	}
	else if (datatype[0] == '3')
	{
		memcpy(e, Q->front->next->data, sizeof(char));
		printf("%c\n", *(char*)e);
	}
	else if (datatype[0] == '1')
	{
		memcpy(e, Q->front->next->data, sizeof(int));
		printf("%d\n", *(int*)e);
	}
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) 
{
	int i;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	for (i = 0; p != Q->rear; i++)
		p = p->next;
	return i;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* Q, void* data) 
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p)
		return FALSE;
	p->data = (void*)malloc(21);
	memcpy(p->data, data, 20);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) 
{
	if (Q->front == Q->rear)
		return FALSE;
	Node* p ;
	p = Q->front->next;
	Q->front->next = p->next;
	if ( Q->front->next == NULL )
		Q->rear = Q->front;
	free(p);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return;
	Node* p, * q;
	Q->rear = Q->front;
	p = Q->front->next;
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q,int *i))
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p ;
	p = Q->front->next;
	int i = 0;
	while (p != NULL) 
	{
		foo(p->data,&i);
		p = p->next;
		i++;
	}
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void* q,int *i)
{
	if (datatype[*i] == '2')
		printf("%.3lf", *(double*)q);
	if (datatype[*i] == '3')
		printf("%c", *(char*)q);
	if (datatype[*i] == '1')
		printf("%d", *(int*)q);
	printf(" -< ");
}

//datatype��ǰ��
Status datatypeDel(char* L, LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	int k;
	for (k = 1; k < LengthLQueue(Q); k++)
		L[k - 1] = L[k];
	return TRUE;
}



