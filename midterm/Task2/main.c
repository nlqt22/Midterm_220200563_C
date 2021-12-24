#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "./lib/stack.h"

char postfix[100];

int uutien(char x) {
    if(x == '*' || x == '/') {
        return 2;
    } else if(x == '+' || x == '-') {
        return 1;
    } else return 0;
}

void printPostfix(char *i) {
    Stack stack;
    Stack_Init(&stack);
    char x;
    int idx = 0;
    printf("Postfix: ");
    while((*i) != '\0') {
        if(isdigit(*i)) {
            printf("%c ", *i);
            postfix[idx++] = (*i);
        } else if(*i == '(') {
            Stack_Push(*i, &stack);
        } else if(*i == ')') {
            while((x = Stack_Pop(&stack)) != '(') {
                printf("%c ", x);
                postfix[idx++] = x;
            }
        } else {
            while(uutien(stack.Element[stack.top]) > uutien(*i)) {
                int u = Stack_Pop(&stack);
                printf("%c ", u);
                postfix[idx++] = (char)(u);
            } 
            Stack_Push(*i, &stack);
        }
        ++i;
    }
    while(!Stack_IsEmpty(stack)) {
        int u = Stack_Pop(&stack);
        printf("%c ", u);
        postfix[idx++] = (char)(u);
    }
    postfix[idx] = '\0';
    printf("\n");
}

void calculatePostfix(char *p) {
    printf("Result : ");
    Stack stack;
    Stack_Init(&stack);
    int num, n1, n2, n3;
    while((*p) != '\0') {
        if(isdigit(*p)) {
            num = *p - 48;
            Stack_Push(num, &stack);
        } else {
            n1 = Stack_Pop(&stack);
            n2 = Stack_Pop(&stack);
            switch (*p) {
                case '+': {
                    n3 = n2 + n1;
                    break;
                }
                case '-': {
                    n3 = n2 - n1;
                    break;
                }
                case '*': {
                    n3 = n2 * n1;
                    break;
                } 
                case '/': {
                    n3 = n2 / n1;
                    break;
                }
            }
            Stack_Push(n3, &stack);
        }
        ++p;
    }
    printf("%d", Stack_Pop(&stack));
}

int main() {
    char infix[100], tmp[100];
    printf("Infix  : ");
    scanf("%s", infix);
    strcpy(tmp, infix);
    char *i = infix, *p = postfix;
    printPostfix(i);
    calculatePostfix(p);
    printf("\n");
    system("pause");
}