//
// Created by Kevin Liam on 2023/10/25.
//
// 4. 1부터 n까지의 숫자를 전부 합하여 반환하는 순환적인 함수를 작성하라.
#include <stdio.h>

int sum(int n)
{
    if (n == 1) return 1;
    return n + sum(n-1);
}

int main(void)
{
    int n;
    printf("n의 값을 입력하시오: ");
    scanf("%d", &n);

    int result = sum(n);
    printf("구하는 합은 : %d\n", sum(n));
    return 0;
}