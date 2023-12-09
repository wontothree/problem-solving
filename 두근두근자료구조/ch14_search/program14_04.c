//
// Created by Kevin Liam on 2023/12/07.
//
// program 14.4 색인 순차 탐색 프로그램

int sequential_search(int list[], int key, int low, int high)
{
    int i;
    for (i = low; i <= high; i++)
        if (list[i] == key) return i;
    return -1;
}

// 인덱스 테이블 항목의 구조체
typedef struct Index {
    int key;
    int index;
} Index;

// 색인 순차 탐색 함수
int indexed_sea(int list [], int nList, Index *tbl, int nTbl, int key)
{
    int i;
    if (key < list[0] || key > list[nList-1]) return -1; // 키 값이 리스트 범위 밖
    for (i = 0; i < nTbl - 1; i++) {
        if (tbl[i].key <= key && tbl[i+1].key > key)
            return sequential_search(list, key, tbl[i].index, tbl[i+1].index);
    }
    return sequential_search(list, key, tbl[nTbl - 1].index, nList);
}


#include <stdio.h>
#define LIST_SIZE 9
#define INDEX_SIZE 3
int main()
{
    int list[LIST_SIZE] = {3, 9, 15, 22, 31, 55, 67, 88, 91};
    Index index[INDEX_SIZE] = {{3, 0}, {15, 3}, {67, 6}};

    int number, ret;
    printf("탐색할 숫자를 입력하시오: ");
    scanf("%d", &number);
    ret = indexed_sea(list, LIST_SIZE, index, INDEX_SIZE, number);

    if (ret >= 0) printf("탐색 성공 : 숫자(%d) 위치=%d\n", number, ret);
    else printf("숫자(%d) 탐색 실패\n", number);

    return 0;
}