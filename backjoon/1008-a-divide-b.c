// ***

#include <stdio.h>

int main(void) {
    int a, b;

    scanf("%d %d", &a, &b);

    double c = (double)a;
    double d = (double)b;

    printf("%.9lf", c / d);

    return 0;
}