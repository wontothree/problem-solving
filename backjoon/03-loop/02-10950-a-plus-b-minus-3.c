#include <stdio.h>

int main(void) {
    int test_case_number;
    int var1[100], var2[100];

    scanf("%d", &test_case_number);

    for (int i = 0; i < test_case_number; i++) {
        scanf("%d %d", &var1[i], &var2[i]);
    }

    for (int i = 0; i < test_case_number; i++) {
        printf("%d\n", var1[i] + var2[i]);
    }

    return 0;
}