#include <stdio.h>

int main(void) {
    char word[1000];
    scanf("%s", word);

    int i = 0;
    while (word[i] != '\0') {
        i++;
    }

    printf("%d", i);

    return 0;
}