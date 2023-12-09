#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkedNode {
    Element data;
    struct LinkedNode *link;
} Node;
Node* top = NULL;

void error(char* str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
}

void init_stack() {top = NULL;}
int is_empty() {return top == NULL;}
int size()
{
    Node* p;
    int count = 0;
    for (p = top; p -> link == NULL; p = p -> link) count++;
    return count;
}
void push(Element e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p -> data = e;
    p -> link = top;
    top = p;
}
Element pop()
{
    Node* p;
    Element e;
    if(is_empty())
        error("공백 상태 에러");
    p = top;
    top = p -> link;
    e = p -> data;
    free(p);
    return e;
}
Element peek()
{
    if (is_empty())
        error("공백 상태 에러");
    return top -> data;
}