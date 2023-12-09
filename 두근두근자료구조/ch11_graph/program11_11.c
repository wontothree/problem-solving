//
// Created by Kevin Liam on 2023/11/10.
//
// 그래프 위상 정렬 프로그램
#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 256

void error(char str[])
{
    printf("%c", str);
    exit(1);
}

typedef struct GraphNode {
    int id;
    struct GraphNode* link;
} GNode;

typedef char VtxData;
GNode* adj[MAX_VTXS];
int vsize;
VtxData vdata[MAX_VTXS];

int is_empty_graph() {return vsize == 0;}
int is_full_graph() {return (vsize >= MAX_VTXS);}
void init_graph()
{
    int i;
    vsize = 0;
    for (i = 0; i < MAX_VTXS; i++)
        adj[i] = NULL;
}
void reset_graph()
{
    int i;
    GNode* n;
    for (i = 0; i < vsize; i++)
        while( adj[i] != NULL) {
            n = adj[i];
            adj[i] = n -> link;
            free(n);
        }
    vsize = 0;
}
void insert_vertex(char name)
{
    if (is_full_graph())
        error("Error : 그래프 정점의 개수 초과\n");
    else
        vdata[vsize++] = name;
}
void insert_edge(int u, int v)
{
    GNode* n = (GNode*)malloc(sizeof(GNode));
    n -> link = adj[u];
    n -> id = v;
    adj[u] = n;
}

//
#define MAX_STACK_SZIE 100

typedef int Element;
Element data[MAX_STACK_SZIE];
int top;

void init_stack() {top = -1;}
int is_empty() {return top == -1;}
int is_full() {return top == MAX_STACK_SZIE - 1;}
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

//
void topological_sort()
{
    GNode* p;
    int i, u, w, inDeg[MAX_VTXS];

    for(i = 0; i < vsize; i++) inDeg[i] = 0;
    for(i = 0; i < vsize; i++) {
        p = adj[i];
        while(p != NULL) {
            inDeg[p -> id]++;
            p = p -> link;
        }
    }
    init_stack();
    for(i = 0; i < vsize; i++)
        if(inDeg[i] == 0) push(i);

    while(!is_empty()) {
        w = pop();
        printf(" %c", vdata[w]);
        for(p = adj[w]; p != NULL; p = p -> link) {
            u = p -> id;
            inDeg[u]--;
            if(inDeg[u] == 0) push(u);
        }
    }
    printf("\n");
}

int main()
{
    int i;
    init_graph();

    for (i = 0; i < 6; i++)
        insert_vertex('A' + i);
    insert_edge(0, 2);
    insert_edge(0, 3);
    insert_edge(1, 3);
    insert_edge(1, 4);
    insert_edge(2, 3);
    insert_edge(2, 5);
    insert_edge(3, 5);
    insert_edge(4, 5);

    printf("Topological Sort:\n");
    topological_sort();
    return 0;
}