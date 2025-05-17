#include <stdio.h>

int main(void) {
    int test_case_num, num1[1000000], num2[1000000];

    scanf("%d", &test_case_num);
    for (int i = 0; i < test_case_num; i++) {
        scanf("%d %d", &num1[i], &num2[i]);
    }

    for (int i = 0; i < test_case_num; i++) {
        printf("%d\n", num1[i] + num2[i]);
    }

    return 0;
}