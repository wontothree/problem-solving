#include <stdio.h>

int main() {
	int side1, side2, side3;
	side1 = 0;
	side2 = 0;
	side3 = 0;
	scanf("%d %d %d", &side1, &side2, &side3);
	
	if (side1 >= side2 + side3) {
	    printf("%d\n", 2 * (side2 + side3) - 1);
	} else if (side2 >= side1 + side3) {
	    printf("%d\n", 2 * (side1 + side3) - 1);
	} else if (side3 >= side1 + side2) {
	    printf("%d\n", 2 * (side1 + side2) - 1);
	} else {
	    printf("%d\n", side1 + side2 + side3);
	}
	
	return 0;
}
