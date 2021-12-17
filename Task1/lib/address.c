#include <stdio.h>
#include <string.h>
#include "algorithm.h"
#include "address.h"

Address setAddress(char name[], char email[], char telephone[]) {
    Address A;
    strcpy(A.name, name);
    strcpy(A.telephone, telephone);
    strcpy(A.email, email);
    return A;
}

int findByFullName(char name[], Address list[], int n) {
    Address X = setAddress(name, "None", "None");
    int key = binary_search(list, X, 0, n-1);
    return key;
}

void getAddress(Address A) {
    printf("+------------------------------+----------------------------------------+---------------+\n");
    printf("|%-30s|%-40s|%-15s|\n", A.name, A.email, A.telephone);
    printf("+------------------------------+----------------------------------------+---------------+\n");
}


