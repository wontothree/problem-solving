//
// Created by Kevin Liam on 2023/11/17.
//
// Prim의 최소비용 신장트리 프로그램
#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 256

void error(char str[]) {
    printf("%s\n", str);
    exit(1);
}

typedef char VtxData;
int adj[MAX_VTXS][MAX_VTXS];
int vsize;
VtxData vdata[MAX_VTXS];

int is_empty_graph() { return (vsize == 0); }
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
        error("Error: 그래프 정점의 개수 초과\n");
    else
        vdata[vsize++] = name;
}
void insert_edge(int u, int v, int val)
{
    adj[u][v] = val;
}
void insert_edge2(int u, int v, int val)
{
    adj[u][v] = adj[v][u] = val;
}
#define INF 9999
void load_wgraph(char *filename)
{
    int i, j, val, n;
    char str[80];
    FILE *fp = fopen(filename, "r");
    if(fp != NULL) {
        init_graph();
        fscanf(fp, "%d", &n);
        for(i = 0; i < n; i++) {
            fscanf(fp, "%s", str);
            insert_vertex(str[0]);
            for(j = 0; j < n; j++) {
                fscanf(fp, "%d", &val);
                if(i != j && val == 0)
                    adj[i][j] = INF;
                else adj[i][j] = val;
            }
        }
        fclose(fp);
    }
}

int selected[MAX_VTXS];
int dist[MAX_VTXS];

int getMinVertex()
{
    int v, minv = 0, mindist = INF;
    for (v = 0; v < vsize; v++)
        if (!selected[v] && dist[v] < mindist) {
            mindist = dist[v];
            minv = v;
        }
    return minv;
}


void Prim()
{
    int i, u, v;
    for(i = 0; i < vsize; i++) {
        dist[i] = INF;
        selected[i] = 0;
    }
    dist[0] = 0;

    for(i = 0; i < vsize; i++) {
        u = getMinVertex();
        selected[u] = 1;
        if(dist[u] == INF) return;
        printf("%c ", vdata[u]);

        for(v = 0; v < vsize; v++)
            if(adj[u][v] != INF)
                if(!selected[v] && adj[u][v] < dist[v])
                    dist[v] = adj[u][v];
    }
    printf("\n");
}
int main()
{
    load_wgraph("wgraph.txt");
    printf("MST by Prim's Algorithm\n");
    Prim();
}