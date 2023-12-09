//
// Created by Kevin Liam on 2023/10/25.
//
// 1. factorial을 계산하는 함수를 구현하라.

#include <stdio.h>

int factorial(int n)
{
    if (n == 1) return 1;
    return n * factorial(n-1);
}

int main(void)
{
    int n;
    printf("팩토리얼 값을 구하고 싶은 값을 입력하시오 : ");
    scanf("%d", &n);
    printf("%d의 팩터리얼 값은 : %d\n", n, factorial(n));
    return 0;
}