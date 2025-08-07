#include <stdio.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void insertion_sort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
    }
}

void selection_sort(int list [], int num)
{
    int max, tmp;
    for (int i = 0; i < num - 1; i++) {
        max = i;
        for (int j = i + 1; j < num; j++) {
            if (list[j] > list[max]) {
                max = j;
            }
        }
        SWAP(list[i], list[max], tmp);
    }
}

int main(void) {
    int size;
    scanf("%d", &size);

    int list[size];
    for (int i = 0; i < size; i++) {
        list[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    selection_sort(list, size);

    for (int i = 0; i < size; i++) {
        printf("%d\n", list[i]);
    }

    return 0;
}