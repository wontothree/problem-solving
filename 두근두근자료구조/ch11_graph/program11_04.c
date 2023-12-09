//
// Created by Kevin Liam on 2023/11/10.
//
// 인접 리스트를 이용한 그래프의 데이터와 기본 연산
#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 256

void error(char str[])
{
    printf("%s", str);
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