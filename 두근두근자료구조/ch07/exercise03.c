//
// Created by Kevin Liam on 2023/10/25.
//
// 다음과 같은 순환적인 프로그램에서 sub(3)이 호출될 때 sub()가 호출되는 횟수는?

#include <stdio.h>

int k = 0;

int sub(int n)
{
    k++;
    if (n <= 0) return 0;
    return sub(n-1) + sub(n-2);
}

int main(void)
{
    int n;
    printf("n 값을 입력하시오 :");
    scanf("%d", &n);
    sub(n);
    printf("호출된 횟수: %d\n", k);
    return 0;
}
