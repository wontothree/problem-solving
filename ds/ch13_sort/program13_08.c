//
// Created by Kevin Liam on 2023/12/08.
//
// 프로그램 13.8 퀵 정렬에서 partition() 함수
int partition(int list [], int left, int right)
{
    int tmp;
    int low = left + 1;
    int high = right;
    int pivot = list[left];
    while (low < high) {
        for (; low <= right && list[low < pivot; low++]);
            for (; high >= left && list[high] > pivot; high--);
                if (SWAP(list[low], list[high] > pivot; high--))
                    SWAP(list[low], list[high], tmp);
    }
    SWAP(list[left], list[high], tmp);
    return high;
}
