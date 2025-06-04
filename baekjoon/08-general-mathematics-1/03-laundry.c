#include <stdio.h>

int main(void) {
    int test_case_num;
    scanf("%d", &test_case_num);
    for (int i = 0; i < test_case_num; i++) {
        int quarter = 25;
        int dime = 10;
        int nickel = 5;
        int penny = 1;

        int small_change;
        scanf("%d", &small_change);
        printf("%d %d %d %d\n", small_change / quarter, small_change % quarter / dime, small_change % quarter % dime / nickel, small_change % quarter % dime % nickel / penny);
    }

    return 0;
}