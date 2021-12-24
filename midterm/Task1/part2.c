#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/address.h"
#include "./lib/filereader.h"
#include "./lib/algorithm.h"
#include "./lib/list.h"

char line[1024];

// void sortByName(ElementType list[], int n) {
//     FILE *fout = fopen("./out/sortByName.csv", "w");
//     insertion_sort(list, n);
//     fprintf(fout, "name;email;telephone\n");
//     for(int i = 0; i < n; ++i) {
//         fprintf(fout, "%s;%s;%s\n", list[i].name, list[i].email, list[i].telephone);
//     }
// }

void readString(char field[], char value[]) {
    printf("%s: ", field);
    fgets(value, NAME_LENGTH, stdin);
    value[strlen(value)-1] = '\0';
}

// void searchByFullName(ElementType list[], int n) {
//     list[-1] = setAddress("Not Found", "Not Found", "Not Found");
//     char name[NAME_LENGTH];
//     readString("Full Name", name);
//     getAddress(list[findByFullName(name, list, n)]);
// }

    // for(student_t st = root; st != NULL; st = st->next) {
    //     printf("|%-10s|%-29s|%-8d|\n", st->id, st->name, st->grade);
    //     printf("+----------+-----------------------------+--------+\n");
    // }

int main() {
    List list;
    List_Init(&list);
    int count = 0;
    FILE *f = fopen("./data/input.csv", "r");
    fgets(line, 1024, f); // remove first line
    while(fgets(line, 1024, f)) {
        char *tmp1 = strdup(line), *tmp2 = strdup(line), *tmp3 = strdup(line);
        Address new = setAddress(CSV_getField(tmp1, 1), CSV_getField(tmp2, 2), CSV_getField(tmp3, 3));
        List_Insert(new, &list);
        ++count;
        free(tmp1); free(tmp2); free(tmp3);
    }
    fclose(f);
    for(List *p = &list; p->next != NULL; p = p->next) {
        getAddress(p->Element);
    }
    printf("%d", count);
}