//
// Created by Kevin Liam on 2023/10/25.
//
// 다음을 계산하는 순환적인 프로그램을 작성하라.
// 1 + 1/2 + 1/3 + ... + 1/n

#include <stdio.h>

// 1 + 1/2 + 1/3 + ... + 1/n을 재귀적으로 계산하는 함수
double calculateSum(int n) {
    // 기저 사례: n이 1 이하인 경우 1을 반환
    if (n <= 1) {
        return 1.0;
    }
    // 재귀 호출: 현재 항(1/n)과 이전 항들의 합을 계산
    return 1.0 / n + calculateSum(n - 1);
}

int main() {
    int n;
    printf("n 값을 입력하세요: ");
    scanf("%d", &n);

    // 주어진 수식의 합을 계산하고 출력
    double result = calculateSum(n);
    printf("수식의 합: %lf\n", result);

    return 0;
}
