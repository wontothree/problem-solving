#include <stdio.h>

int main(void) {
    char word[100];
    scanf("%s", word);

    for (int i = 'a'; i <= 'z'; i++) {
        int j = 0;
        int found = 0;
        while (word[j] != '\0') {
            if (word[j] == i) {
                break;
            }
            j++;
        }

        if (word[j] == '\0') {
            j = -1;
        }
                
        printf("%d ", j);
    }

    return 0;
}