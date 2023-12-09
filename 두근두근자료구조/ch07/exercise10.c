//
// Created by Kevin Liam on 2023/10/25.
//
// 이항계수를 계산하는 순환함수를 작성하라. 이항계수는 순환적으로 정의된다. 반복함수로도 구현해보라.

#include <stdio.h>

int binomialCoefficient(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return binomialCoefficient(n-1, k-1) + binomialCoefficient(n-1, k);
}

int main(void)
{
    int n, k;
    printf("n 값을 입력하시오 : ");
    scanf("%d", &n);
    printf("k 값을 입력하시오 : ");
    scanf("%d", &k);

    int result = binomialCoefficient(5, 3);
    printf("구하는 값은 : %d\n", result);
    return 0;
}