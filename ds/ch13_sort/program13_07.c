//
// Created by Kevin Liam on 2023/12/08.
//
// 프로그램 13.7 퀵 정렬 함수

// 퀵 정렬 알고리즘을 이용해 배열의 left ~ right 항목들을 오름차순으로 정렬하는 함수
void quick_sort(int list [], int left, int right)
{
    int q;
    if (left < right) {
        q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}