//
// Created by Kevin Liam on 2023/12/08.
//
// 프로그램 13.2 삽입 정렬 함수
#include <stdio.h>

void printArray(int arr [], int n, int *str)
{
    int i;
    printf("%s = ", str);
    for (i = 0; i < n; i++) printf("%3d", arr[i]);
    printf("\n");
}

void printStep(int arr [], int n, int val)
{
    int i;
    printf("    Step %2d = ", val);
    for (i = 0; i < n; i++) printf("%3d", arr[i]);
    printf("\n");
}

void insertion_sort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
        printStep(list, n, i);
    }
}

int main()
{
    int n = 9;
    int list[9] = {5, 3, 8, 4, 9, 1, 6, 2, 7};
    printArray(list, 9, "Original ");
    insertion_sort(list, n);
    printArray(list, n, "Insertion");
}