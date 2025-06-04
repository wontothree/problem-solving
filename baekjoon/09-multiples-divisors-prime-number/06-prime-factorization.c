#include <stdio.h>

int main(void) {
    // input
    int num;
    scanf("%d", &num);

    // declare and initialize
    int prime_factors[1000000];
    int last = 0;
    for (int index = 0; index < 1000000; index++) {
        prime_factors[index] = 0;
    }

    // prime factorization
    while (num != 1) {
        for (int factor = 2; factor <= num; factor++) {
            if (num % factor == 0) {
                num /= factor;
                prime_factors[last] = factor;
                last++;
                break;
            }
        }
    }

    for (int index = 0; index < last; index++) {
        printf("%d\n", prime_factors[index]);
    }

    return 0;
}