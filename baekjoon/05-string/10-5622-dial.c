#include <stdio.h>

int main(void) {
    char word[15];
    scanf("%s", word);

    int total_time = 0;
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == 'A') {
            total_time += 3;
        } else if (word[i] >= 'P' && word[i] <= 'S') {
            total_time += 8;
        } else if (word[i] >= 'T' && word[i] <= 'V') {
            total_time += 9;
        } else if (word[i] >= 'W' && word[i] <= 'Z') {
            total_time += 10;
        } else {
            total_time += (word[i] - 'A') / 3 + 3;
        }
        i++;
    }

    printf("%d", total_time);

    return 0;
}