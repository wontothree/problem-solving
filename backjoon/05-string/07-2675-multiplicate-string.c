#include <stdio.h>

int main(void) {
    int test_case_num;
    scanf("%d", &test_case_num);

    for (int i = 0; i < test_case_num; i++) {
        int multiplication;
        char word[20];
        scanf("%d %s", &multiplication, word);

        int j = 0;
        while (word[j] != '\0') {
            for (int k = 0; k < multiplication; k++) {
                printf("%c", word[j]);
            }
            j++;
        }
        printf("\n");
    }
    
    return 0;
}
