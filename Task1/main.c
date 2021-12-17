#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/address.h"
#include "./lib/filereader.h"
#include "./lib/algorithm.h"

char line[1024];
Address list[150];

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
    FILE *fout = fopen("./out/output1.csv", "w");
    insertion_sort(list, start);
    for(int i = 0; i < start; ++i) {
        fprintf(fout, "%s;%s;%s\n", list[i].name, list[i].email, list[i].telephone);
    }

    printf("Name: ");
    char s[128];
    fgets(s, 128, stdin);
    s[strlen(s)-1] = '\0';
    Address X = setAddress(s, "None", "None");
    int key = binary_search(list, X, 0, start-1);
    if(key == -1) {
        printf("Not Found !");
        return 0;
    } else {
        getAddress(list[key]);
    }
}
