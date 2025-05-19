#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);

    char num_series[num];
    scanf("%s", num_series);

    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += num_series[i] - '0';
    }

    printf("%d", sum);

    return 0;
}