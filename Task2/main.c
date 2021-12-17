#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "./lib/stack.h"

int uutien(char x) {
    if(x == '*' || x == '/') {
        return 2;
    } else if(x == '+' || x == '-') {
        return 1;
    } else return 0;
}

int main() {
    Stack stack;
    Stack_Init(&stack);
    char infix[100];
    printf("Infix: ");
    scanf("%s", infix);
    char *i = infix, *j = infix, x;
    printf("Postfix: ");
    while((*i) != '\0') {
        if(isalnum(*i)) {
            printf("%c ", *i);
        } else if(*i == '(') {
            Stack_Push(*i, &stack);
        } else if(*i == ')') {
            while((x = Stack_Pop(&stack)) != '(') printf("%c ", x);
        } else {
            while(uutien(stack.Element[stack.top]) > uutien(*i)) 
                printf("%c ", Stack_Pop(&stack));
            Stack_Push(*i, &stack);
        }
        ++i;
    }
    while(!Stack_IsEmpty(stack)) {
        printf("%c ", Stack_Pop(&stack));
    }
    printf("\n");
    system("pause");
}