#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/address.h"
#include "./lib/filereader.h"
#include "./lib/algorithm.h"

char line[1024];
Address list[150];

void sortByName(ElementType list[], int n) {
    FILE *fout = fopen("./out/sortByName.csv", "w");
    insertion_sort(list, n);
    fprintf(fout, "name;email;telephone\n");
    for(int i = 0; i < n; ++i) {
        fprintf(fout, "%s;%s;%s\n", list[i].name, list[i].email, list[i].telephone);
    }
}

void readString(char field[], char value[]) {
    printf("%s: ", field);
    fgets(value, NAME_LENGTH, stdin);
    value[strlen(value)-1] = '\0';
}

void searchByFullName(ElementType list[], int n) {
    list[-1] = setAddress("Not Found", "Not Found", "Not Found");
    char name[NAME_LENGTH];
    readString("Full Name", name);
    getAddress(list[findByFullName(name, list, n)]);
}

int main() {
    int start = 0;
    FILE *f = fopen("./data/input.csv", "r");
    fgets(line, 1024, f); // remove first line
    while(fgets(line, 1024, f)) {
        char *tmp1 = strdup(line), *tmp2 = strdup(line), *tmp3 = strdup(line);
        list[start] = setAddress(CSV_getField(tmp1, 1), CSV_getField(tmp2, 2), CSV_getField(tmp3, 3));
        free(tmp1); free(tmp2); free(tmp3);
        ++start;
    }
    fclose(f);
    sortByName(list, start);
    searchByFullName(list, start);
}
