#include <stdio.h>

int main(void) {
    int test_case_num;
    scanf("%d", &test_case_num);

    int nums1[100], nums2[100];
    for (int i = 0; i < test_case_num; i++) {
        scanf("%d %d", &nums1[i], &nums2[i]);
    }

    for (int i = 0; i < test_case_num; i++) {
        printf("Case #%d: %d + %d = %d\n", i + 1, nums1[i], nums2[i], nums1[i] + nums2[i]);
    }

    return 0;
}