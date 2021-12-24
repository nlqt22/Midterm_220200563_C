#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

void insertion_sort(ElementType list[], int n) {
    ElementType next;
    int i, j;
    for(i = 1; i < n; ++i) {
        next = list[i];
        for(j = i - 1; j >= 0 && next < list[j]; --j) {
            list[j+1] = list[j];
        }
        list[j+1] = next;
    }
}

void quicksort(ElementType a[], int l, int r) {
    int i = l, j = r;
    ElementType m = a[(l+r)/2];
    while(i <= j) {
        while(a[i] < m) ++i;
        while(a[j] > m) --j;
        if(i <= j) {
            ElementType tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++; j--;
        }
    }
    if(l < j) quicksort(a, l, j);
    if(i < r) quicksort(a, i, r);
}

void randomize(int a[], int b[], int n) {
    const int MIN = 0;
    const int MAX = 100;
    for(int i = 0; i < n; ++i) {
        a[i] = MIN + rand() % (MAX - MIN + 1);
        b[i] = a[i];
    }
}

int main() {
    printf("Nhap so luong phan tu :");
    int n; scanf("%d", &n);
    int a[100], b[100];
    randomize(a, b, n);
    time_t t1, t2;
    time(&t1);
    insertion_sort(a, n);
    time(&t2);
    printf("Insertion Sort: %lf\n", difftime(t2, t1));
    time(&t1);
    quicksort(b, 0, n-1);
    time(&t2);
    printf("Quick Sort: %lf\n", difftime(t2, t1));
}