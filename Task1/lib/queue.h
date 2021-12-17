#ifndef QUEUE_H
#define QUEUE_H
#define MaxLength 10

#include "address.h"

typedef Address ElementType;
typedef struct _Queue{
    ElementType Element[MaxLength];
    int Front, Rear;
} Queue;

void Queue_Init(Queue*);
int Queue_IsEmpty(Queue);
int Queue_IsFull(Queue);
void Queue_Enqueue(ElementType, Queue*);
ElementType Queue_Dequeue(Queue*);

#endif