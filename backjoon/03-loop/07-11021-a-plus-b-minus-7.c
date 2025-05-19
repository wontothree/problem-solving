#include <stdio.h>

int main(void) {
    int test_case_num;
    scanf("%d", &test_case_num);

    int num1[100], num2[100];
    for (int i = 0; i < test_case_num; i++) {
        scanf("%d %d", &num1[i], &num2[i]);
    }

    for (int i = 0; i < test_case_num; i++) {
        printf("Case #%d: %d\n", i + 1, num1[i] + num2[i]);
    }
}