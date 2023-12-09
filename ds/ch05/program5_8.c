#include <stdio.h>
#include <stdlib.h>
typedef int Element;
typedef struct LinkedNode
{
    Element data;
    struct LinkedNode* link;
} Node;
Node* front = NULL;
Node* rear = NULL;

void error(char str[])
{
    printf("%c", str);
    exit(1);
}
void init_queue() {front = rear = 0;}
int is_empty() {return front == rear;}
int size()
{
    Node *p;
    int count = 0;
    for (p = front; p != NULL; p = p -> link) count++;
    return count;
}
void enqueue(Element e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p -> data = e;
    p -> link = NULL;

    if (is_empty()) front = rear = p;
    else {
        rear -> link = p;
        rear = p;
    }
}
Element deque()
{
    Node* p;
    Element e;
    if (is_empty())
        error("공백 상태 에러");

    p = front;
    front = front -> link;

    if(front == NULL) rear = NULL;
    e = p -> data;
    free(p);
    return e;
}
Element peek()
{
    if (is_empty())
        error("공백 상태 에러");
    return front -> data;
}
void destory_queue()
{
    while (is_empty() == 0)
        deque();
}