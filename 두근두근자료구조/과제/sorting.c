//
// Created by Kevin Liam on 2023/12/08.
//
/*
* 정렬 알고리즘 분석
    - 개요: 정수형 난수를 다음 갯수 만큼 생성하여, 아래 6개 정렬알고리즘에 대한 소요시간에 대한 선그래프를 그림
    - 난수 개수: 10000개, 20000개, 30000개, 40000개, 50000개, 60000개, 70000개, 80000개, 90000개, 100000개
    - 난수의 범위는 기본적으로 0 ~ 999설정하는데, 난수의 범위를 달리 해도 무방함. 단, 동일값을 다수 포함하기 위해서 범위를 너무 크게 설정하지 않기 바람
    - 정렬 알고리즘: Selection sort, Insertion Sort, Bubble sort, Shell sort, Quick sort (leftmost pivot), Quick sort (median-of-three pivot)
    - 제출 내용: 소스코드, 수행결과 (소요시간만 출력, 정렬결과를 보일 필요는 없음), 선그래프 (* 각 정렬알고리즘의 시간복잡도에 따른 형태가 나오도록 분석 수행 바람)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void printArray(int arr[], int n, const char *str)
{
    int i;
    printf("%s = ", str);
    for (i = 0; i < n; i++)
        printf("%3d", arr[i]);
    printf("\n");
}

void printStep(int arr[], int n, int val)
{
    int i;
    printf("    Step %2d = ", val);
    for (i = 0; i < n; i++)
        printf("%3d", arr[i]);
    printf("\n");
}

void selection_sort(int list[], int n)
{
    int i, j, least, tmp;
    for (i = 0; i < n - 1; i++)
    {
        least = i;
        for (j = i + 1; j < n; j++)
            if (list[j] < list[least])
                least = j;
        SWAP(list[i], list[least], tmp);
    }
}

void insertion_sort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
    }
}

void bubble_sort(int list[], int n)
{
    int i, j, bChanged, temp;
    for (i = n - 1; i > 0; i--)
    {
        bChanged = 0;
        for (j = 0; j < i; j++)
        {
            if (list[j] > list[j + 1])
            {
                SWAP(list[j], list[j + 1], temp);
                bChanged = 1;
            }
        }
        if (!bChanged)
            break;
    }
}

static void sortGapInsertion(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap)
    {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n)
{
    int i, gap, count = 0;
    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        if (gap % 2 == 0)
            gap++;
        for (i = 0; i < gap; i++)
            sortGapInsertion(list, i, n - 1, gap);
    }
}

// Function to partition the array for quick sort
int partition(int list[], int left, int right)
{
    int pivot, i, j, temp;
    pivot = list[right];
    i = left - 1;
    for (j = left; j < right; j++)
    {
        if (list[j] <= pivot)
        {
            i++;
            SWAP(list[i], list[j], temp);
        }
    }
    SWAP(list[i + 1], list[right], temp);
    return i + 1;
}

// Quick sort algorithm
void quick_sort(int list[], int left, int right)
{
    int q;
    if (left < right)
    {
        q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}

int main()
{
    const int sizes[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};

    for (int k = 0; k < 10; k++)
    {
        int n = sizes[k];
        int list[n];

        // Seed for random number generation
        srand((unsigned int)time(NULL));

        // Generate random numbers in the range [0, 999] and fill the array
        for (int i = 0; i < n; i++)
        {
            int random_number = rand() % 1000; // Generates a random number in the range [0, 999]
            list[i] = random_number;
        }

        const char *sort_names[] = {"Selection Sort", "Insertion Sort", "Bubble Sort", "Shell Sort", "Quick Sort"};

        printf("\nArray Size: %d\n", n);

        for (int i = 0; i < 5; i++)
        {
            int temp_list[n]; // Create a temporary array for each sort
            for (int j = 0; j < n; j++)
                temp_list[j] = list[j]; // Copy the original array to the temporary array

            // Measure the time taken by the corresponding sorting function
            clock_t start_time = clock();

            switch (i)
            {
                case 0:
                    selection_sort(temp_list, n);
                    break;
                case 1:
                    insertion_sort(temp_list, n);
                    break;
                case 2:
                    bubble_sort(temp_list, n);
                    break;
                case 3:
                    shell_sort(temp_list, n);
                    break;
                case 4:
                    quick_sort(temp_list, 0, n - 1);
                    break;
            }

            clock_t end_time = clock();
            double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

            printf("Elapsed Time (%s): %.6f seconds\n", sort_names[i], elapsed_time);
        }
    }

    return 0;
}
