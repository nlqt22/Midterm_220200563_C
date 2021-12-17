#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/filereader.h"
#include "./lib/algorithm.h"
#include "./lib/address.h"
#include "./lib/queue.h"

char line[1024];

int main() {
    Queue queue;
    Queue_Init(&queue);

    FILE *f = fopen("./data/input.csv", "r");
    fgets(line, 1024, f); // remove first line
    while(fgets(line, 1024, f)) {
        char *tmp1 = strdup(line), *tmp2 = strdup(line), *tmp3 = strdup(line);
        Queue_Enqueue(setAddress(CSV_getField(tmp1, 1), CSV_getField(tmp2, 2), CSV_getField(tmp3, 3)), &queue);
        free(tmp1); free(tmp2); free(tmp3);
    }
    fclose(f);
    
    FILE *fout = fopen("./out/traversalByQueue.csv", "w");
    fprintf(fout, "name;email;telephone\n");
    while(!Queue_IsEmpty(queue)) {
        Address x = Queue_Dequeue(&queue);
        fprintf(fout, "%s;%s;%s\n", x.name, x.email, x.telephone);
        getAddress(x);
    }
}
