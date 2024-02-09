//
// Created by Kevin Liam on 2024/02/09.
//
// 알고리즘 수업 - 깊이 우선 탐색 1
#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 100000

void error(char str[])
{
    printf("%s", str);
    exit(1);
}
typedef int VtxData;
int adj[MAX_VTXS][MAX_VTXS];
int vsize;
VtxData vdata[MAX_VTXS];

int is_empty_graph() { return vsize == 0; }
int is_full_graph() { return vsize >= MAX_VTXS; }
void init_graph()
{
    int i, j;
    vsize = 0;
    for (i = 0; i < MAX_VTXS; i++)
        for (j = 0; j < MAX_VTXS; j++)
            adj[i][j] = 0;
}
void insert_vertex(VtxData name)
{
    if (is_full_graph())
        error("Error : 그래프 정점의 개수 초과\n");
    else
        vdata[vsize++] = name;
}
//void insert_edge(int u, int v, int val)
//{
//    adj[u][v] = val;
//}
//int visited[MAX_VTXS];
//void reset_visited()
//{
//    int i;
//    for (i = 0; i < vsize; i++)
//        visited[i] = 0;
//}
//void DFS(int v)
//{
//    int w;
//    visited[v] = 1;
//    printf("%d\n", vdata[v]);
//    for (w = 0; w < vsize; w++)
//        if (adj[v][w] != 0 && visited[w] == 0)
//            DFS(w);
//}
int main()
{
    init_graph();
    int n, m, r, i, u, v;

    scanf("%d %d %d", &n, &m, &r);

//    for (i = 0; i < n; i++) {
//        scanf("%d %d", &u, &v);
//        insert_vertex(u);
//        insert_vertex(v);
//        insert_edge(u, v, 1);
//    }

//    reset_visited();
//    DFS(r);
    return 0;
}