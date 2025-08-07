#include <stdio.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void selection_sort(int list [], int size) {
    int min, tmp;
    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (list[min] > list[j])
                min = j;
        }
        SWAP(list[i], list[min], tmp);
    }
}

int main(void) {
    // input
    int size;
    scanf("%d", &size);

    // initialize array
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    // input
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    // sort
    selection_sort(arr, size);

    // print

    printf("---\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
