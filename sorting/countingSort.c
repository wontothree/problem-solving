#include <stdio.h>

int main(void) {
    // input
    int size, max;
    scanf("%d %d", &size, &max);

    // initialize array
    int arr[max + 1];
    for (int i = 0; i < max + 1; i++)
        arr[i] = 0;

    // input
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        scanf("%d", &tmp);
        arr[tmp]++;
    }

    for (int i = 0; i < max + 1; i++)
        for (int j = 0; j < arr[i]; j++)
            printf("%d ", i);

    return 0;
}