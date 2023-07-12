//
// Created by Kevin Liam on 2023/07/05.
//
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[50];
    scanf("%s", &str);

    strcat(str, "??!");

    printf("%s", str);

    return 0;
}