#include <stdio.h>

int main(void) {
    int remain[10], tmp;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &tmp);
        remain[i] = tmp % 42;
    }

    int duplicate_count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 1 + i; j < 10; j++) {
            if (remain[i] == remain[j]) {
                duplicate_count++;
                break;
            }
        }
    }
    printf("%d",10 - duplicate_count);

    return 0;
}