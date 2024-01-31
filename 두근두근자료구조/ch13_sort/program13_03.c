//
// Created by Kevin Liam on 2023/12/08.
//
// 프로그램 13.3 버블 정렬 함수
#include <stdio.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

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

void bubble_sort(int list [], int n)
{
    int i, j, bChanged, tmp;
    for (i = n - 1; i > 0; i--) {
        bChanged = 0;
        for (j = 0; j < i; j++)
            if (list[j] > list[j + 1]) {
                SWAP(list[j], list[j + 1], tmp);
                bChanged = 1;
            }
        if (!bChanged) break;
        printStep(list, n, n - i);
    }
}

int main()
{
    int n = 9;
    int list[9] = {5, 3, 8, 4, 9, 1, 6, 2, 7};
    printArray(list, 9, "Original ");
    bubble_sort(list, n);
    printArray(list, n, "Bubble ");
}