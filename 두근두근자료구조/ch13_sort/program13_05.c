//
// Created by Kevin Liam on 2023/12/08.
//
// 프로그램 13.5 셸 정렬 함수

// gap 만큼 떨어진 요소들을 삽입 정렬, 정렬의 범위는 first부터 last
static void sortGapInsertion(int list [], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

// 셸 정렬 알고리즘을 이용해 int 배열을 오름차순으로 정렬하는 함수
void shell_sort(int list [], int n)
{
    int i, gap, count = 0;
    for (gap = n/2; gap > 0; gap = gap / 2) {
        if (gap % 2 == 0) gap++;
        for (i = 0; i < gap; i++)
            sortGapInsertion(list, i, n - 1, gap);
        printStep(list, n, ++count);
    }
}