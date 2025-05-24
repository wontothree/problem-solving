#include <stdio.h>

int main(void) {
    char sentence[1000000];
    scanf("%[^\n]", sentence);
    
    int i = 0, j = 0, word_num = 0;
    while (sentence[i] != '\0') {
        if (sentence[i] == ' ' && j != 0) {
            word_num++;
            j = 0;
        } else if (sentence[i] != ' ') {
            j = 1;
        }
        i++;
    }

    if (sentence[i] == '\0' && j == 1) {
        word_num++;
    }
    
    printf("%d", word_num);
    
    return 0;
}