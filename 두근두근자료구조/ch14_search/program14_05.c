//
// Created by Kevin Liam on 2023/12/07.
//
// program 14.5 반복문을 이용한 보간 탐색

int interpolation_search(int list[], int n, int key)
{
    int j, low = 0, high = n - 1;

    while ((list[low] < key && key <= list[high]))
    {
        j = (int)((float)(key - list[low]) / (list[high] - list[low]) * (high - low) + low);

        if (key > list[j]) low = j + 1;
        else if (key < list[j]) high = j - 1;
        else return j;
    }
    return -1;
}