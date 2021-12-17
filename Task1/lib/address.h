#ifndef ADDRESS_H
#define ADDRESS_H

#define NAME_LENGTH 128
#define TELEPHONE_LENGTH 15
#define EMAIL_LENGTH 128

typedef struct Address {
    char name[NAME_LENGTH];
    char telephone[TELEPHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Address;

Address setAddress(char*, char*, char*);
void getAddress(Address);
// void copyAddress(Address *, Address *);

#endif
