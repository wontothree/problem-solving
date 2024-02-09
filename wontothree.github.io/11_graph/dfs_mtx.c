//
// Created by CDSL on 2024-02-04.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 256

void error(char str[])
{
    printf("%s", str);
    exit(1);
}

typedef char VtxData;           // 그래프 정점에 저장할 데이터의 자료형
int adj[MAX_VTXS][MAX_VTXS];    // 인접 행렬
int vsize;                      // 전체 정점의 개수
VtxData vdata[MAX_VTXS];        // 정점에 저장할 데이터 배열

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
void insert_edge(int u, int v, int val) // 방향 그래프
{
    adj[u][v] = val;
}
void insert_edge2(int u, int v, int val) // 무방향 그래프
{
    adj[u][v] = adj[v][u] = val;
}
void load_graph(char *filename)
{
    int i, j, val, n;
    char str[80];
    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        init_graph();
        fscanf(fp, "%d", &n);
        for (i = 0; i < n; i++) {
            fscanf(fp, "%s", str);
            insert_vertex(str[0]);
            for (j = 0; j < n; j++) {
                fscanf(fp, "%d", &val);
                if (val != 0)
                    insert_edge(i, j, val);
            }
        }
    }
    fclose(fp);
}

int visited[MAX_VTXS];  // 방문 여부를 기록하는 배열
void reset_visited()    // 방문 여부를 기록하는 배열을 초기화하는 함수
{
    int i;
    for (i = 0; i < vsize; i++) {
        visited[i] = 0;
    }
}
void DFS(int v)
{
    int w;
    visited[v] = 1;
    printf("%c ", vdata[v]);
    for (w = 0; w < vsize; w++)
        if (adj[v][w] != 0 && visited[w] == 0)
            DFS(w);
}
void main()
{
    load_graph("graph.txt");
    reset_visited();
    printf("DFS ===> ");
    DFS(0);
    printf("\n");
}