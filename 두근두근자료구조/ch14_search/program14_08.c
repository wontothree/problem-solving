//
// Created by Kevin Liam on 2023/12/07.
//
// Program 14.8 체이닝을 이용한 해시 맵 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 13

int transform(char* key)
{
    int number = 0;
    while (*key != '\0') number += (*key++);
    return number;
}

int hash_function(char *key)
{
    return transform(key) % TABLE_SIZE;
}

typedef struct RecordNode {
    char key[128];
    char value[128];
    struct RecordNode* link;
} Node;

Node* ht[TABLE_SIZE];

void init_map()
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        ht[i] = NULL;
    }
}

void print_map()
{
    int i;
    Node* p;
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("[%2d] ", i);
        for (p = ht[i]; p != NULL; p = p -> link)
            printf("%10s", p -> key);
        printf("\n");
    }
}

void add_record(char* key, char* val)
{
    Node* p;

    int hashValue = hash_function(key);
    for (p = ht[hashValue]; p != NULL; p = p -> link)
    {
        if (strcmp(p -> key, key) == 0) {
            printf("이미 탐색 키가 저장되어 있음\n");
            return;
        }
    }
    p = (Node*) malloc(sizeof(Node));
    strcpy(p -> key, key);
    strcpy(p -> value, val);
    p -> link = ht[hashValue];
    ht[hashValue] = p;
}

void search_record(char *key)
{
    Node* p;

    int hashValue = hash_function(key);
    for (p = ht[hashValue]; p != NULL; p = p -> link) {
        if (strcmp(p -> key, key) == 0) {
            printf("[%8s] 탐색 성공", key);
            printf("[%2d] %20s = %s\n", hashValue, p -> key, p -> value);
            return;
        }
    }
    printf("[%8s] 탐색 실패 : 찾는 값이 테이블에 없음\n", key);
}

int main()
{
    init_map();
    add_record("do", "반복");
    add_record("for", "반복");
    add_record("if", "분기");
    add_record("case", "분기");
    add_record("else", "분기");
    add_record("return", "반환");
    add_record("function", "함수");
    print_map();
    search_record("return");
    search_record("function");
    search_record("class");

    return 0;
}