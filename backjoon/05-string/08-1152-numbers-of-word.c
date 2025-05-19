#include <stdio.h>

int main(void) {
    char string[1000000];
    scanf("%s", string);

    int j = 0;
    int word_num = 0;
    while (string[j] != '\0') {
        if (string[j] != ' ' && string[j + 1] == ' ') {
            word_num++;
            printf("%d", word_num);
        }
        j++;
    }

    printf("%d", word_num + 1);

    return 0;
}