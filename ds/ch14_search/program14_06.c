//
// Created by Kevin Liam on 2023/12/07.
//
// program 14.6 문자열 탐색키의 정수 변환 및 해시 함수 예

// 해싱 테이블의 크기 13(소수)
#define TABLE_SIZE 13

// 문자열로 된 탐색키를 숫자로 변환 : 간단한 덧셈 방식
int transform(char *key)
{
    int number = 0;
    while (*key != '\0') number += (*key++);
    return number;
}

// 해싱 함수 : 제산 함수 사용
int hash_function(char *key)
{
    return transform(key) % TABLE_SIZE;
}