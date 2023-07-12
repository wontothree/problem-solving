//
// Created by Kevin Liam on 2023/07/05.
//
#include <stdio.h>

int main(void) {
    int a, b;
    int plus, minus, multiply, divide, remain;
    scanf("%d %d", &a, &b);

//    printf("%d\n", a + b);
//    printf("%d\n", a - b);
//    printf("%d\n", a * b);
//    printf("%d\n", a / b);
//    printf("%d\n", a % b);

    plus = a + b;
    minus = a - b;
    multiply = a * b;
    divide = a / b;
    remain = a % b;

    printf("d\n", plus);
    printf("d\n", minus);
    printf("d\n", multiply);
    printf("d\n", divide);
    printf("d\n", remain);

    return 0;
}