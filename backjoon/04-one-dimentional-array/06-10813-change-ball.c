#include <stdio.h>

int main(void) {
    int basket_num, changing_num;
    scanf("%d %d", &basket_num, &changing_num);

    int basket[basket_num];
    for (int i = 0; i < basket_num; i++) {
        basket[i] = i + 1;
    }


    int first, second;
    for (int i = 0; i < changing_num; i++) {
        scanf("%d %d", &first, &second);

        int temp = basket[first - 1];
        basket[first - 1] = basket[second - 1];
        basket[second - 1] = temp;
    }

    for (int i = 0; i < basket_num; i++) {
        printf("%d ", basket[i]);
    }

    return 0;
}