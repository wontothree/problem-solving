#include <stdio.h>

int main(void) {
    int basket_num, ball_num;
    scanf("%d %d", &basket_num, &ball_num);

    int basket[basket_num];
    for (int i = 0; i < basket_num; i++) {
        basket[i] = 0;
    }

    int start, end, ball;
    for (int i = 0; i < ball_num; i++) {
        scanf("%d %d %d", &start, &end, &ball);

        for (int j = start - 1; j <= end - 1; j++) {
            basket[j] = ball;
        }
    }

    for (int i = 0; i < basket_num; i++) {
        printf("%d ", basket[i]);
    }

    return 0;
}