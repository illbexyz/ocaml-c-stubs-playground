#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "playground.h"

void hello_world() {
    printf("hello from C!\n");
}

int sum(int x, int y) {
    return x + y;
}

int sum_int_array(int *array, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += array[i];
    }
    return res;
}

void array_head_to_zero(int *array, int size) {
    if (size > 0) {
        array[0] = 0;
    }
}

char* concat_strings(char* s1, char* s2) {
    char* res = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(res, "");
    strcat(res, s1);
    strcat(res, s2);
    return res;
}
