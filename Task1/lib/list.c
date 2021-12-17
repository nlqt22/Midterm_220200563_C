#include <stdio.h>

#include "list.h"
#include "address.h"

Node* List_Init() {
    return NULL;
}

Node* List_CreateNode(ElementType x) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->next = NULL;
    new->Element = x;
    return new;
}

Node* List_Insert(ElementType x, Node* root) {
    Node* to_add = List_CreateNode(x);
    Node* cur;
    if(root == NULL) return to_add;
    else {
        Node *p = root;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = to_add;
        return root;
    }
}