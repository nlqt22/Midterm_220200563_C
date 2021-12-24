#ifndef LIST_H
#define LIST_H

#include "address.h"
typedef Address ElementType;

typedef struct _Node {
    ElementType Element;
    struct _Node *next;
} Node;

typedef Node List;

void List_Init(List*);
List* List_CreateNode(ElementType);
List* List_Insert(ElementType, List*);

#endif