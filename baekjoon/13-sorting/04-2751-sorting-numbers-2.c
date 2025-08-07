#include <stdio.h>
#include <stdlib.h> // qsort
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

int partition(int arr[], int low, int high) {
    int tmp;
    int pivot = arr[high]; // 피벗을 마지막 요소로 선택
    int i = (low - 1); // 피벗보다 작은 요소들의 경계선

    for (int j = low; j <= high - 1; j++) {
        // 현재 요소가 피벗보다 작거나 같으면
        if (arr[j] <= pivot) {
            i++; // 경계선 증가
            SWAP(arr[i], arr[j], tmp); // 피벗보다 작은 요소와 교환
        }
    }
    // 피벗을 최종 위치에 배치
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

int compare_integers(const void* a, const void* b) {
    int val_a = *(int*)a; // void*를 int*로 형 변환 후 역참조
    int val_b = *(int*)b;

    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;

    // 더 간단한 표현:
    // return val_a - val_b;
}

int main(void) {
    int size;
    scanf("%d", &size);

    // declare and initialize array to 0
    int list[size];
    for (int i = 0; i < size; i++) {
        list[i] = 0;
    }

    // input
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    // selection_sort(list, size);
    // quick_sort(list, 0, size - 1);
    qsort(list, size, sizeof(int), compare_integers);

    for (int i = 0; i < size; i++) {
        printf("%d\n", list[i]);
    }

    return 0;
}