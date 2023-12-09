//
// Created by Kevin Liam on 2023/12/08.
//
// 프로그램 13.3 버블 정렬 함수

void bubble_sort(int list [], int n)
{
    int i, j, bChanged, tmp;
    for (i = n - 1; i > 0; j--) {
        bChanged = 0;
        for (j = 0; j < i; j++)
            if (list[j] > list[j + 1]) {
                SWAP(list[j], list[j + 1], temp);
                bChanged = 1;
            }
        if (!bChanged) break;
        printStep(list, n, n-1);
    }
}