//
// Created by Kevin Liam on 2023/11/17.
//
// week 12 실습
// prim, dijksta, floyd
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

// Dijkstra
int path[MAX_VTXS];
int dist[MAX_VTXS];
int found[MAX_VTXS];
void print_step(int step)
{
    int i;
    printf(" Step%2d : ", step);
    for(i = 0; i < vsize; i++) {
        if(dist[i] == INF) printf("  INF");
        else printf("%5d", dist[i]);
    }
    printf("\n");
}
void print_shortest_path(int start, int end)
{
    printf("[최단경로: %c---%c] %c", vdata[end], vdata[start], vdata[end]);
    while(path[end] != start) {
        printf("-%c", vdata[path[end]]);
        end = path[end];
    }
    printf("-%c\n", vdata[path[end]]);
}
int choose_vertex()
{
    int i, min = INF, minpos = -1;

    for (i = 0; i < vsize; i++)
        if(dist[i] < min && !found[i]) {
            min = dist[i];
            minpos = i;
        }
    return minpos;
}

void shortest_path_dijkstra(int start)
{
    int i, u, w;
    for(i = 0; i < vsize; i++) {
        dist[i] = adj[start][i];
        path[i] = start;
        found[i] = 0;
    }
    found[start] = 1;
    dist[start] = 0;

    for(i = 0; i < vsize; i++) {
        print_step(i + 1);
        u = choose_vertex();
        found[u] = 1;

        for(w = 0; w < vsize; w++) {
            if (found[w] == 0) {
                if (dist[u] + adj[u][w] < dist[w]) {
                    dist[w] = dist[u] + adj[u][w];
                    path[w] = u;
                }
            }
        }
    }
}

// floyd

void print_wgraph(char* msg)
{
    int i, j, val;
    printf("%s%d\n", msg, vsize);
    for(i = 0; i < vsize; i++) {
        printf("%c  ", vdata[i]);
        for(j = 0; j < vsize; j++) {
            val = adj[i][j];
            if (i == j) printf("  0 ");
            else if (val >= INF) printf("  - ");
            else printf("%3d ", val);
        }
        printf("\n");
    }
}

int A[MAX_VTXS][MAX_VTXS];
void printA()
{
    int i, j;
    printf("======================================\n");
    for(i = 0; i < vsize; i++) {
        for(j = 0; j < vsize; j++) {
            if(A[i][j] == INF) printf("INF");
            else printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}

void shortest_path_floyd()
{
    int i, j, k;

    for(i = 0; i < vsize; i++)
        for(j = 0; j < vsize; j++)
            A[i][j] = adj[i][j];

    for(k = 0; k < vsize; k++) {
        for(i = 0; i < vsize; i++)
            for (j = 0; j < vsize; j++) {
                if(A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
            }
        printA();
    }
}


int main()
{
    load_wgraph("wgraph.txt");

    //
    printf("MST by Prim's Algorithm\n");
    Prim();
    printf("\n");

    //
    int i;
    printf("Shortest Path by Dijkstra Algorithm\n");
    shortest_path_dijkstra(0);
    for (i = 1; i < vsize; i++)
        print_shortest_path(0, i);
    printf("\n");

    //
    print_wgraph("최단거리(wgraph_sp.txt)\n");
    printf("Shortest Path by Floyd Algorithm\n");
    shortest_path_floyd();
    printf("\n");
    return 0;
}