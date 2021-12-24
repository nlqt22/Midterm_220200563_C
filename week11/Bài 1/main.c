#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LENGTH 128
#define TELEPHONE_LENGTH 15
#define EMAIL_LENGTH 128
#define MAX 101

typedef struct Address {
    char name[NAME_LENGTH];
    char telephone[TELEPHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Address;

typedef Address ElementType;

void getAddress(Address A) {
    printf("+------------------------------+----------------------------------------+---------------+\n");
    printf("|%-30s|%-40s|%-15s|\n", A.name, A.email, A.telephone);
    printf("+------------------------------+----------------------------------------+---------------+\n");
}

Address setAddress(char name[], char email[], char telephone[]) {
    Address A;
    strcpy(A.name, name);
    strcpy(A.telephone, telephone);
    strcpy(A.email, email);
    return A;
}

char *CSV_getField(char *line, int num) {
    char *token;
    for(token = strtok(line, ";"); token && *token; token = strtok(NULL, ";\n")) {
        if(!--num) return token;
    } 
    return NULL;
}

void quicksort(ElementType a[], int l, int r) {
    int i = l, j = r;
    ElementType m = a[(l+r)/2];
    while(i <= j) {
        while(strcmp(a[i].name, m.name) < 0) ++i;
        while(strcmp(a[j].name, m.name) > 0) --j;
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

int main() {
    ElementType list[MAX];
    char line[1024];
    int start = 0;
    FILE *f = fopen("data.csv", "r");
    fgets(line, 1024, f); // remove first line
    while(fgets(line, 1024, f)) {
        char *tmp1 = strdup(line), *tmp2 = strdup(line), *tmp3 = strdup(line);
        list[start] = setAddress(CSV_getField(tmp1, 1), CSV_getField(tmp2, 2), CSV_getField(tmp3, 3));
        free(tmp1); free(tmp2); free(tmp3);
        ++start;
    }
    quicksort(list, 0, start-1);
    for(int i = 0; i < start; ++i) {
        getAddress(list[i]);
    }
}