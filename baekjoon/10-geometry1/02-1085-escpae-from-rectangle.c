#include <stdio.h>

int main(void) {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int distance_left = x, distance_bottom = y;
    int distance_right = w - x;
    int distance_top = h - y;

    int distances[4];
    distances[0] = distance_bottom;
    distances[1] = distance_top;
    distances[2] = distance_right;
    distances[3] = distance_left;

    int min = distances[0];
    for (int i = 1; i < 4; i++) {
        if (min > distances[i]) {
            min = distances[i];
        }
    }

    printf("%d", min);

    return 0;
}