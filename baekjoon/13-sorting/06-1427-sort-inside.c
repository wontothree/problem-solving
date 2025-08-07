#include <stdio.h>
#include <string.h> // sprintf
#include <stdlib.h> // snprintf, qsort

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int partition(int arr[], int low, int high) {
    int tmp;
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++; 
            SWAP(arr[i], arr[j], tmp); 
        }
    }
    SWAP(arr[i + 1], arr[high], tmp);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main(void) {
    // input
    int input_num;
    scanf("%d", &input_num);

    char str[12];
    for (int i = 0; i < 12; i++) {
        str[i] = '\0';
    }

    // int to str
    sprintf(str, "%d", input_num);

    int size = strlen(str);

    // for (int i = 0; i < size; i++) {
    //     printf("%c ", str[i]);
    // }
    // printf("\n");

    int arr[12];
    for (int i = 0; i < size; i++) {
        arr[i] = -1;
    }

    // str to int
    for (int i = 0; i < size; i++) {
        arr[i] = str[i] - '0';
    }

    // qsort(arr, size, sizeof(int), compare_integers);
    quick_sort(arr, 0, size -1);

    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
    
    return 0;
}