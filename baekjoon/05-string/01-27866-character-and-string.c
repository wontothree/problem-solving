#include <stdio.h>

int main(void) {
    char word[1000];
    int order;
    scanf("%s\n%d", word, &order);

    printf("%c", word[order - 1]);

    return 0;
}