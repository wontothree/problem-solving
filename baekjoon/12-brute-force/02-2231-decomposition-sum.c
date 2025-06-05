#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int number;
    scanf("%d", &number);

    bool flag = true;
    for (int candidate = 1; candidate < number; candidate++) {
        int decomposition_sum = candidate;
        char number_[1000000];
        sprintf(number_, "%d", candidate);

        // decomposition sum of candidate
        int idx = 0;
        while (number_[idx] != '\0') {
            decomposition_sum += number_[idx] - '0';
            idx++;
        }

        if (decomposition_sum == number) {
            printf("%d\n", candidate);
            flag = false;
            break;
        }
    }

    if (flag) {
        printf("%d\n", 0);
    }

    return 0;
}