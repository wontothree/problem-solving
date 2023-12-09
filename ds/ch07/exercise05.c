//
// Created by Kevin Liam on 2023/10/25.
//
// 5. 다음 함수를 sum(5)로 호출하였을 때, 화면에 출력되는 내용과 함수의 반환값을 구하라.
#include <stdio.h>

int sum(int n)
{
    printf("%d\n", n);
    if(n < 1) return 0;
    return n + sum(n-1);
}

int main(void)
{
    int n;
    printf("n의 값을 입력하시오: ");
    scanf("%d", &n);

    int result = sum(n);
    printf("반환값은 %d\n", result);
}