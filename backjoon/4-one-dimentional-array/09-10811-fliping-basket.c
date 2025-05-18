#include <stdio.h>

int main(void) {
    int basket_num, flip_num;
    scanf("%d %d", &basket_num, &flip_num);

    int basket[basket_num];
    for (int i = 0; i < basket_num; i++) {
        basket[i] = i + 1;
    }
    
    for (int i = 0; i < flip_num; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        for (int j = 0; j < (end - start + 1) / 2; j++) {
            int tmp = basket[start - 1 + j];
            basket[start - 1 + j] = basket[end - 1 - j];
            basket[end - 1 - j] = tmp;
        }
    }

    for (int i = 0; i < basket_num; i++) {
        printf("%d ", basket[i]);
    }

    return 0;
}
