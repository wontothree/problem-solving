#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // input
    char num1[100], num2[100];
    scanf("%s %s", num1, num2);
    
    // length of nums
    int num1_length = 0, num2_length = 0;
    while (num1[num1_length] != '\0' || num2[num2_length] != '\0') {
        if (num1[num1_length] != '\0') {
            num1_length++;
        }

        if (num2[num2_length] != '\0') {
            num2_length++;
        }
    }

    char new_num1[100], new_num2[100];
    for (int i = 0; i < num1_length; i++) {
        new_num1[i] = num1[num1_length - i - 1];
    }

    for (int i = 0; i < num2_length; i++) {
        new_num2[i] = num2[num2_length - i - 1];    
    }

    // print bigger number
    int new_num1_ = atoi(new_num1);
    int new_num2_ = atoi(new_num2);
    if (new_num1_ > new_num2_) {
        printf("%d", new_num1_);
    } else {
        printf("%d", new_num2_);
    }

    return 0;
}
