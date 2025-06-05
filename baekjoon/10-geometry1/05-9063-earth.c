#include <stdio.h>

int main(void) {
    int bead_num;
    scanf("%d", &bead_num);

    // initialize array
    int x[100000], y[100000];
    for (int i = 0; i < 100000; i++) {
        x[i] = 0;
        y[i] = 0;
    }

    // input coordinate
    for (int i = 0; i < bead_num; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    int min_x = x[0], max_x = x[0], min_y = y[0], max_y = y[0];
    for (int i = 0; i < bead_num; i++) {
        if (min_x > x[i]) {
            min_x = x[i];
        }
        if (max_x < x[i]) {
            max_x = x[i];
        }
        if (min_y > y[i]) {
            min_y = y[i];
        }
        if (max_y < y[i]) {
            max_y = y[i];
        }
    }

    printf("%d\n", (max_x - min_x) * (max_y - min_y));

    return 0;
}