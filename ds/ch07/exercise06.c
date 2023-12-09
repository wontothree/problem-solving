//
// Created by Kevin Liam on 2023/10/25.
//
// 6. 다음 함수에서 asterisk(5)와 같이 호출할 때 출력되는 *의 개수는?

#include <stdio.h>
void asterisk(int i)
{
    if (i > 1) {
        asterisk(i/2);
        asterisk(i/2);
    }
    printf("*");
}

int main(void)
{
    asterisk(5);
    return 0;
}