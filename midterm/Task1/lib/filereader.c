#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filereader.h"

char *CSV_getField(char *line, int num) {
    char *token;
    for(token = strtok(line, ";"); token && *token; token = strtok(NULL, ";\n")) {
        if(!--num) return token;
    } 
    return NULL;
}