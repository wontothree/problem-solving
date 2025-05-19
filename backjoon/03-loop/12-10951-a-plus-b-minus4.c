// #include <stdio.h>

// int main(void) {
//     int nums1[100], nums2[100];
//     int index = 0;
//     while(1) {
//         scanf("%d %d", &nums1[index], &nums2[index]);

//         printf("%d", nums1[index] + nums2[index]);
//     }

//     return 0;
// }

#include <stdio.h>

int main(void) {
    int a,b;
    while(scanf("%d %d", &a, &b)!=EOF) {
        printf("%d\n", a+b);
    }
}
