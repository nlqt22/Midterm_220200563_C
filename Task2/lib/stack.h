#ifndef STACK_H
#define STACK_H
#define MaxLength 100

typedef char ElementType;
typedef struct _Stack {
    ElementType Element[MaxLength];
    int top;
} Stack;

void Stack_Init(Stack*);
int Stack_IsEmpty(Stack);
int Stack_IsFull(Stack);
void Stack_Push(ElementType, Stack*);
ElementType Stack_Pop(Stack*);

#endif