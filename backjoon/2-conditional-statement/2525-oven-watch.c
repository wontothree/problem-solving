#include <stdio.h>

int main(void) {
    int hour, minute, cooking_time;

    scanf("%d %d\n%d", &hour, &minute, &cooking_time);

    printf("%d %d", (hour + (minute + cooking_time) / 60) % 24, (minute + cooking_time) % 60);

    return 0;
}
