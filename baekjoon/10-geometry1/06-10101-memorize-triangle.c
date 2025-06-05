#include <stdio.h>

int main(void) {
    int angle1, angle2, angle3;
    scanf("%d\n%d\n%d", &angle1, &angle2, &angle3);

    if (angle1 + angle2 + angle3 != 180) {
        printf("%s\n", "Error");
    } else if (angle1 == 60 && angle2 == 60 && angle3 == 60) {
        printf("%s\n", "Equilateral");
    } else if (angle1 == angle2 || angle2 == angle3 || angle3 == angle1) {
        printf("%s\n", "Isosceles");
    } else if (angle1 != angle2 && angle2 != angle3 && angle3 != angle1) {
        printf("%s\n", "Scalene");
    }

    return 0;
}