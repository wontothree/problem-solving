#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);

    int nums[100];
    for (int i = 0; i < num; i++) {
        scanf("%d ", &nums[i]);
    }

    int choosed_num;
    scanf("%d", &choosed_num);

    int count = 0;
    for (int i = 0; i < num; i++) {
        if (nums[i] == choosed_num) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}