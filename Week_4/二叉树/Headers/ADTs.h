#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "ADTTree.h"

Stack* createStack();

int isEmpty(Stack* stack);

void push(Stack* stack, BSTNode* t);

BSTNode* pop(Stack* stack);

Queue* createQueue();

int isEmptyQ(Queue* queue);

BSTNode* deQueue(Queue* queue);

void enQueue(Queue* queue, BSTNode* node);
#endif 