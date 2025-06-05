#include <stdio.h>

int main(void) {
    int dot1_x, dot1_y, dot2_x, dot2_y, dot3_x, dot3_y;
    scanf("%d %d\n%d %d\n%d %d", &dot1_x, &dot1_y, &dot2_x, &dot2_y, &dot3_x, &dot3_y);

    if (dot1_x == dot2_x) {
        printf("%d ", dot3_x);
    } else if (dot1_x == dot3_x) {
        printf("%d ", dot2_x);
    } else {
        // dot2_x == dot3_x
        printf("%d ", dot1_x);
    }

    if (dot1_y == dot2_y) {
        printf("%d", dot3_y);
    } else if (dot1_y == dot3_y) {
        printf("%d", dot2_y);
    } else {
        // dot2_x == dot3_x
        printf("%d", dot1_y);
    }

    return 0;
}