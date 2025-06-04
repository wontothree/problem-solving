#include <stdio.h>

int main(void) {
    int test_case_num;
    scanf("%d", &test_case_num);

    // declare and initialize
    int test_case[1000];
    for (int i = 0; i < 1000; i++) {
        test_case[i] = 0;
    }

    for (int i = 0; i < test_case_num; i++) {
        scanf("%d", &test_case[i]);
    }

    int prime_num = test_case_num;
    for (int i = 0; i < test_case_num; i++) {
        if (test_case[i] == 1) {
            prime_num--;
        }
        int divisor_num;
        for (int j = 2; j < test_case[i]; j++) {
            if (test_case[i] % j == 0) {
                prime_num--;
                break;
            }
        }
    }

    printf("%d", prime_num);

    return 0;
}
