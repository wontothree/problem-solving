//
// Created by Kevin Liam on 2023/10/24.
//

// 8. 순환을 사용하여 배열 요소를 역순으로 화면에 출력하는 프로그램을 작성하라.

//요소 #3: 2
//요소 #2: 4
//요소 #1: 6
//요소 #0: 8

#include <stdio.h>

void reversePrint(int arr[], int length, int index) {
    if (index < 0) {
        return;
    }
    printf("요소 #%d: %d\n", length - 1 - index, arr[index]);
    reversePrint(arr, length, index - 1);
}

int main() {
    int arr[] = {8, 6, 4, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    reversePrint(arr, length, length - 1);
    return 0;
}

