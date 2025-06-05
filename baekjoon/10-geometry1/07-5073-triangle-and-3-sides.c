#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int side1, side2, side3;
    while (1) {
        scanf("%d %d %d", &side1, &side2, &side3);

        // break condition
        if (side1 == 0 && side2 == 0 && side3 == 0) {
            break;
        }

        // invalide
        bool flag = true;
        if (side1 > side2 && side1 > side3) {
            if (side1 >= side2 + side3) {
                printf("%s\n", "Invalid");
                flag = false;
            }
        } else if (side2 > side1 && side2 > side3) {
            if (side2 >= side1 + side3) {
                printf("%s\n", "Invalid");
                flag = false;
            }
        } else if (side3 > side1 && side3 > side2) {
            if (side3 >= side1 + side2) {
                printf("%s\n", "Invalid");
                flag = false;
            }
        }

        // equilateral
        if (flag) {
            if (side1 == side2 && side2 == side3 && side3 == side1) {
                printf("%s\n", "Equilateral");
            } else if (side1 == side2 || side2 == side3 || side3 == side1) {
                printf("%s\n", "Isosceles");
            } else {
                printf("%s\n", "Scalene");
            }
        }
    }

    return 0;
}