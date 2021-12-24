#include <stdio.h>
#include "queue.h"

void Queue_Init(Queue *Q) {
    Q->Front = -1;
    Q->Rear = -1;
}

int Queue_IsEmpty(Queue Q) {
    return Q.Front == -1;
}

int Queue_IsFull(Queue Q) {
    return (Q.Rear-Q.Front+1) == MaxLength;
}

void Queue_Enqueue(ElementType X, Queue *Q) {
    if(!Queue_IsFull(*Q)) {
        if(Queue_IsEmpty(*Q)) Q->Front = 0;
        Q->Element[++Q->Rear] = X;
    } else {
        printf("Queue is full!");
    }
}

ElementType Queue_Dequeue(Queue *Q) {
    ElementType x;
    if(!Queue_IsEmpty(*Q)) {
        x = Q->Element[Q->Front];
        Q->Front++;
        if(Q->Front > Q->Rear) Queue_Init(Q);
        return x;
    }
}