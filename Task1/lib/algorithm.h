#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "address.h"

typedef Address ElementType;

void insertion_sort(ElementType[], int n);
int binary_search(ElementType [], ElementType, int, int);

#endif