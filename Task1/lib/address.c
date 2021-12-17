#include <stdio.h>
#include <string.h>
#include "address.h"

Address setAddress(char name[], char email[], char telephone[]) {
    Address A;
    strcpy(A.name, name);
    strcpy(A.telephone, telephone);
    strcpy(A.email, email);
    return A;
}

void getAddress(Address A) {
    printf("%s | %s | %s \n", A.name, A.email,  A.telephone);
}
