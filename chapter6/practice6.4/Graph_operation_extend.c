#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 判断某顶点是否为割点
#define MaxVertices 100

typedef struct MGraph {
    int numVertices, numEdges;
    char verticesList[MaxVertices];
    int edges[MaxVertices][MaxVertices];
} MGraph;

int GetIndex(MGraph *graph, const char *s) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->verticesList[i] == *s) {
            return i;
        }
    }
    return -1;
}


void CreateGraph(MGraph *graph) {
    printf("输入顶点数:");
    scanf("%d", &graph->numVertices);
    printf("输入边数:");
    scanf("%d", &graph->numEdges);
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            graph->edges[i][j] = 0;
        }
    }
    printf("输入顶点:");
    for (int i = 0; i < graph->numVertices; i++) {
        scanf("%s", &graph->verticesList[i]);
    }
    printf("输入边的两端顶点:");
    for (int i = 0; i < graph->numEdges; i++) {
        char a[2], b[2];
        scanf("%s %s", a, b);
        int index_a = GetIndex(graph, a);
        int index_b = GetIndex(graph, b);

        graph->edges[index_a][index_b] = 1;
    }
}

typedef struct Queue {
    char data[MaxVertices];
    int head, tail;
} Queue;

void InitQueue(Queue *q) {
    q->head = 0;
    q->tail = -1;
}

bool EmptyQueue(Queue *q) {
    if (q->head > q->tail) {
        return true;
    } else {
        return false;
    }
}

void EnQueue(Queue *q, const char *s) {
    if (q->head < MaxVertices - 1) {
        q->tail++;
        q->data[q->tail] = *s;
    }
}

char DeQueue(Queue *q) {
    if (q->head <= q->tail) {
        char res = q->data[q->head];
        q->head++;
        return res;
    }
}


void BFS(MGraph *graph, int *numCalVertices, int indexDelete) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    InitQueue(q);
    if (indexDelete > 0) {
        EnQueue(q, &graph->verticesList[0]);
    } else {
        EnQueue(q, &graph->verticesList[1]);
    }
    (*numCalVertices)++;
    while (!EmptyQueue(q)) {
        char temp = DeQueue(q);
        int index = GetIndex(graph, &temp);
        for (int i = index + 1; i < graph->numVertices; i++) {
            if (graph->edges[index][i] == 1) {
                EnQueue(q, &graph->verticesList[i]);
                (*numCalVertices)++;
            }
        }
    }
}

bool IsCutVertex(MGraph *graph, char *s) {
    int indexDelete = GetIndex(graph, s);
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->edges[indexDelete][i] == 1) {
            graph->edges[indexDelete][i] = -1;
        }
        if (graph->edges[i][indexDelete] == 1) {
            graph->edges[i][indexDelete] = -1;
        }
    }

    int numCalVertices = 0;
    BFS(graph, &numCalVertices, indexDelete);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->edges[indexDelete][i] == -1) {
            graph->edges[indexDelete][i] = 1;
        }
        if (graph->edges[i][indexDelete] == -1) {
            graph->edges[i][indexDelete] = 1;
        }
    }

    if (numCalVertices == graph->numVertices - 1) {
        return false;
    } else {
        return true;
    }
}

int GetCutVertexNumber(MGraph *graph) {
    int cnt = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int res0 = IsCutVertex(graph, &graph->verticesList[i]);
        if (res0 == 0) cnt++;
    }
    return cnt;
}

int main() {
    MGraph *graph = (MGraph *) malloc(sizeof(MGraph));
    CreateGraph(graph);
//    int res = IsCutVertex(graph, &graph->verticesList[0]);
//    if (res == 0) {
//        printf("是连通图");
//    } else {
//        printf("不是连通图");
//    }

    int res = GetCutVertexNumber(graph);
    printf("有%d个连通图", res);
}