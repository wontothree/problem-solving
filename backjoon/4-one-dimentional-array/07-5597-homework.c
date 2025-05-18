#include <stdio.h>

int main(void) {
    int check[30];
    for (int i = 0; i < 30; i++) {
        check[i] = 0;
    }

    int temp;
    for (int i = 0; i < 28; i++) {
        scanf("%d", &temp);
        check[temp - 1] = 1;
    }

    for (int i = 0; i < 30; i++) {
        if (check[i] == 0) {
            printf("%d ", i + 1);
        }
    }

    return 0;
}