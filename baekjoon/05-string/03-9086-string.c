#include <stdio.h>

int main(void) {
    int test_case_num;
    scanf("%d", &test_case_num);

    char word[1000];
    for (int i = 0; i < test_case_num; i++) {
        scanf("%s", word);

        int j = 0;
        while (word[j] != '\0') {
            j++;
        }

        printf("%c%c\n", word[0], word[j-1]);
    }

    return 0;
}
