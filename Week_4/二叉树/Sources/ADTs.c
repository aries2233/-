
#include "ADTs.h"

Stack* createStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->top == NULL;
}

void push(Stack* stack, BSTNode* t)
{
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->treeNode = t;
    stackNode->next = stack->top;
    stack->top = stackNode;
}

BSTNode* pop(Stack* stack)
{
    if (isEmpty(stack)) 
    {
        return NULL;
    }
    StackNode* stackNode = stack->top;
    BST t = stackNode->treeNode;
    stack->top = stackNode->next;
    free(stackNode);
    return t;
}


// ╤сап
Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmptyQ(Queue* queue)
{
    return queue->front == NULL;
}

BSTNode* deQueue(Queue* queue) 
{
    if (isEmptyQ(queue))
    {
        return NULL;
    }
    BSTNode* node = queue->front->node;
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return node;
}

void enQueue(Queue* queue, BSTNode* node) 
{
    QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode));
    queueNode->node = node;
    queueNode->next = NULL;
    if (isEmptyQ(queue))
    {
        queue->front = queueNode;
        queue->rear = queueNode;
    }
    else
    {
        queue->rear->next = queueNode;
        queue->rear = queueNode;
    }
}
