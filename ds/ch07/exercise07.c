//
// Created by Kevin Liam on 2023/10/25.
//
// 7. 순환을 사용하여 1부터 10까지를 화면에 출력하는 프로그램을 작성해보자.
// 자연수: 1 2 3 4 4 5 6 7 8 9 10

#include <stdio.h>

int printNumber(int n)
{
    int k = n;
    if (n == 1) return printf("10 ");
    printf("%d ", 11 - k);
    return printNumber(n - 1);
}

int main(void)
{
    printf("자연수 :");
    printNumber(10);
}