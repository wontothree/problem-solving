#include <stdio.h>

int main(void) {
    int total_price;
    int type_num;
    int product_price[100], product_num[100];
    int sum = 0;

    scanf("%d", &total_price);
    scanf("%d", &type_num);

    for (int i = 0; i < type_num; i++) {
        scanf("%d %d", &product_price[i], &product_num[i]);
        sum += product_num[i] * product_price[i];
    }

    if (total_price == sum) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}