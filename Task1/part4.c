#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./lib/algorithm.h"
#include "./lib/address.h"
#include "./lib/queue.h"

char line[1024];

void readString(char field[], char value[]) {
    fflush(stdin);
    printf("%s: ", field);
    fgets(value, NAME_LENGTH, stdin);
    value[strlen(value)-1] = '\0';
}

void menu() {
    printf("[1] Insert data.\n");
    printf("[2] Display data.\n");
    printf("[0] Exit.\n");
    printf("> ");
}

int main() {
    Queue queue;
    Queue_Init(&queue);
    int isFull = 10;

    int op;
    do {
        menu();
        scanf("%d", &op);
        if(op == 1) {
            char name[NAME_LENGTH], email[EMAIL_LENGTH], telephone[TELEPHONE_LENGTH];
            readString("Please type name", name);
            readString("Please type email", email);
            readString("Please type telephone number", telephone);
            if(queue.Rear-queue.Front+1 == isFull) {
                Address x = Queue_Dequeue(&queue);
                printf("Information about %s will be removed ! Detail :\n", x.name);
                getAddress(x);
            }
            Queue_Enqueue(setAddress(name, email, telephone), &queue);
        } else if (op == 2) {
            Queue queue1 = queue;
            while(!Queue_IsEmpty(queue1)) {
                Address x = Queue_Dequeue(&queue1);
                getAddress(x);
            }
        } else if (op == 0) return 0;
    } while(op >= 0 && op <= 2);
}
