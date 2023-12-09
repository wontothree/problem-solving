//
// Created by Kevin Liam on 2023/12/07.
//
// program 14.1 순차탐색
int sequential_search(int list[], int key, int low, int high)
{
    int i;
    for (i = low; i <= high; i++)
        if (list[i] == key) return i;
    return -1;
}