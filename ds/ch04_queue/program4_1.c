//
// Created by Kevin Liam on 2023/10/27.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int Element;
Element data[MAX_QUEUE_SIZE];
int front, rear;

void error(char* str)
{
    printf("%c\n", str);
    exit(1);
}

void init_queue() {front = rear = 0;}
int is_empty() {return front == rear;}
int is_full() {return front == (rear + 1) % MAX_QUEUE_SIZE;}
int size() {return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;}
void enqueue(Element val)
{
    if (is_empty())
        error("포화 상태 에러");
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    data[rear] = val;
}
Element dequeue()
{
    if (is_empty())
        error("공백 상태 에러");
    front = (front + 1) % MAX_QUEUE_SIZE;
    return data[front];
}
Element peek()
{
    if(is_empty())
        error("공백 상태 에러");
    return data[(front + 1) % MAX_QUEUE_SIZE];
}

void init_deque() {return init_queue();}
void add_rear(Element val) { enque(val);}
Element delete_front() {return dequeue();}
Element get_front() {return peek();}

void add_front(Element val)
{
    if (is_full())
        error("포화 상태 에러");
    front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    data[front] = val;
}

Element delete_rear()
{
    if (is_empty())
        error("공백 상태 에러");
    rear = (rear + 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;

}

Element get_rear()
{
    if (is_empty())
        error("포화 상태 에러");
    return data[rear];
}