#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // 문자열을 이용한 풀이
//    char a[4], b[4];
//    scanf("%s\n%s", a, b);
//
//    long l = strtol(a, NULL, 10);
//    long m = strtol(b, NULL, 10);
//    int x = b[2] - '0';
//    int y = b[1] - '0';
//    int z = b[0] - '0';
//
//    printf("%ld\n%ld\n%ld\n%ld", l * x, l * y, l * z, l * m);

    // 몫과 나머지를 이용한 풀이
    int a, b;
    scanf("%d\n%d", &a, &b);
    printf("%d\n%d\n%d\n%d", a * (b % 10), a * (b / 10 % 10), a * (b / 100), a * b);
    return 0;
}
