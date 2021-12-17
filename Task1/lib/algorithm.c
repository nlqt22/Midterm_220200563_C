#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "address.h"
#include "algorithm.h"

void insertion_sort(ElementType list[], int n) {
    ElementType next;
    int i, j;
    for(i = 1; i < n; ++i) {
        next = list[i];
        for(j = i - 1; j >= 0 && strcmp(next.name, list[j].name) == -1; --j) {
            list[j+1] = list[j];
        }
        list[j+1] = next;
    }
}

int binary_search(ElementType A[], ElementType X, int Lo, int Hi) {
    if(Lo > Hi) {
        return -1;
    }
    int Mid = (Lo + Hi) / 2;
    if(strcmp(X.name, A[Mid].name) == 0) return Mid;
    else if (strcmp(X.name, A[Mid].name) == 1) return binary_search(A, X, Mid+1, Hi);
    else return binary_search(A, X, Lo, Mid-1); 
}

