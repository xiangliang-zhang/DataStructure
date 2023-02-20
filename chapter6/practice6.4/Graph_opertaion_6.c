#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 计算图中顶点的度为奇数的个数

#define MAXV 100

typedef struct {
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
} MGraph;

void SetValue(MGraph *graph) {
    graph->numVertices = 5;
    graph->numEdges = 6;
    graph->VerticesList[0] = '0';
    graph->VerticesList[1] = '1';
    graph->VerticesList[2] = '2';
    graph->VerticesList[3] = '3';
    graph->VerticesList[4] = '4';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            graph->Edge[i][j] = 0;
        }
    }
    graph->Edge[0][1] = 1;
    graph->Edge[1][0] = 1;

    graph->Edge[0][2] = 1;
    graph->Edge[2][0] = 1;

    graph->Edge[0][3] = 1;
    graph->Edge[3][0] = 1;

    graph->Edge[2][3] = 1;
    graph->Edge[3][2] = 1;

    graph->Edge[2][4] = 1;
    graph->Edge[4][2] = 1;

    graph->Edge[1][2] = 1;
    graph->Edge[2][1] = 1;

}

int IsExistEL(MGraph *G) {
    int res = 0;
    for (int i = 0; i < G->numVertices; i++) {
        int cnt = 0;
        for (int j = 0; j < G->numVertices; j++) {
            if (G->Edge[i][j] == 1) {
                cnt++;
            }
        }
        if (cnt % 2 != 0) res++;
    }
    if (res == 0 || res == 2) return 1;
    else return 0;
}

int main() {
    MGraph *graph = (MGraph *) malloc(sizeof(MGraph));
    SetValue(graph);
    int res = IsExistEL(graph);
    printf("%d\n", res);
}