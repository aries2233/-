#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "ADTLQ.h" 

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e) 
{
	Node* p;
	if (Q->front == Q->rear)
		return FALSE;
	printf("  队头元素为：");
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度
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
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q

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

//datatype的前移
Status datatypeDel(char* L, LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	int k;
	for (k = 1; k < LengthLQueue(Q); k++)
		L[k - 1] = L[k];
	return TRUE;
}



