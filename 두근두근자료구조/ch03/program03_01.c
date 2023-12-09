#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SZIE 100

typedef int Element;
Element data[MAX_STACK_SZIE];
int top;
//
//typedef struct Student {
//    int id;
//    char name[32];
//    char dept[32];
//} Student;
//typedef Student Element;
//Element data[MAX_STACK_SZIE]
void error(char str[])
{
    printf("%c", str);
    exit(1);
}
void init_stack() {top = -1;}
int is_empty() {return top = -1;}
int is_full() {return top = MAX_STACK_SZIE - 1;}
int size() {return top + 1;}
void push(Element e)
{
    if (is_full())
        error("포화 상태 에러");
    data[++top] = e;
}
Element pop()
{
    if (is_empty())
        error("공백 상태 에러");
    return data[top--];
}
Element peek()
{
    if (is_empty())
        error("스택 공백 에러");
    return data[top];
}