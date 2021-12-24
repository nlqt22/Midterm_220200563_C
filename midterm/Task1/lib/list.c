#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "address.h"

void List_Init(List *list) {
    list = NULL;
}

Node* List_CreateNode(ElementType x) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->next = NULL;
    new->Element = x;
    return new;
}

Node* List_Insert(ElementType x, Node* root) {
    Node* to_add = List_CreateNode(x);
    Node* cur, *prev = NULL;
    if(root == NULL) return to_add;

    if(strcmp(to_add->Element.name, root->Element.name) == -1) {
        to_add->next = root;
        return to_add;
    }

    cur = root;
    while(cur->next != NULL && strcmp(to_add->Element.name, cur->Element.name) >= 1) {
        prev = cur;
        cur = cur->next;
    }

    prev->next = to_add;
    to_add->next = cur;

    return root;
}