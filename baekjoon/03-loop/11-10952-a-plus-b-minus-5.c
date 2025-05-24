#include <stdio.h>

int main(void) {
    int nums1[100], nums2[100];

    int last_index = 0;
    while (1) {
        scanf("%d %d", &nums1[last_index], &nums2[last_index]);

        if (nums1[last_index] == 0 && nums2[last_index] == 0) {
            break;
        }

        last_index++;
    }

    for (int i = 0; i < last_index; i++) {
        printf("%d\n", nums1[i] + nums2[i]);
    }

    return 0;
}