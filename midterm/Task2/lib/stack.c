#include <stdio.h>
#include "stack.h"

void Stack_Init(Stack* stack) {
    (*stack).top = 0;
}

int Stack_IsEmpty(Stack stack) {
    return stack.top == -1;
}

int Stack_IsFull(Stack stack) {
    return stack.top == MaxLength;
}

void Stack_Push(ElementType element, Stack* stack) {
    if(Stack_IsFull(*stack)) {
        printf("Stack overflow.\n");
    } else (*stack).Element[(*stack).top++] = element;
}

ElementType Stack_Pop(Stack* stack) {
    if(Stack_IsEmpty(*stack)) {
        printf("Stack underflow.\n");
    } else return (*stack).Element[--(*stack).top];
}