//
// Created by Kevin Liam on 2023/12/08.
//
// 프로그램 13.2 삽입 정렬 함수
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