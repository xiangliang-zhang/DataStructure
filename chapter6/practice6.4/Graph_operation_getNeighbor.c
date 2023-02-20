#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 取x邻接顶点y的下一个顶点

#define MaxVertices 100
int visited[MaxVertices];
typedef struct MGraph {
    int numVertices, numEdges;
    char vertices[MaxVertices];
    int Edge[MaxVertices][MaxVertices];
} MGraph;

void CreateMGraph(MGraph *graph) {
    printf("输入顶点数:");
    scanf("%d", &graph->numVertices);
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            graph->Edge[i][j] = 0;
        }
    }
    printf("输入边数:");
    scanf("%d", &graph->numEdges);
    printf("输入顶点:");
    for (int i = 0; i < graph->numVertices; i++) {
        scanf("%s", &graph->vertices[i]);
    }
    printf("输入边:");
    for (int i = 0; i < graph->numEdges; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph->Edge[a][b] = 1;
        graph->Edge[b][a] = 1;
    }

}

int GetMGraphIndex(MGraph *graph, const char *val) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i] == *val) {
            return i;
        }
    }
    return -1;
}

// 邻接矩阵
void GetNeighborMGraph(MGraph *graph, char *node1, char *node2) {
    int index_1 = GetMGraphIndex(graph, node1);
    int index_2 = GetMGraphIndex(graph, node2);
    int i;
    for (i = index_2 + 1; i < graph->numVertices; i++) {
        if (graph->Edge[index_1][i] == 1) {
            printf("%c\n", graph->vertices[i]);
            break;
        }
    }
}

typedef struct ArcNode {
    int adjarc;
    struct ArcNode *next;
} ArcNode;

typedef struct VNode {
    char data;
    ArcNode *first;
} VNode, AdjList[MaxVertices];

typedef struct AlGraph {
    int numVertices, numEdges;
    AdjList vertices;
} AlGraph;

int GetAlGraphIndex(AlGraph *graph, const char *s) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i].data == *s) {
            return i;
        }
    }
    return -1;
}

void CreateAlGraph(AlGraph *graph) {
    printf("输入顶点数:");
    scanf("%d", &graph->numVertices);
    printf("输入边数:");
    scanf("%d", &graph->numEdges);
    printf("输入顶点:");
    for (int i = 0; i < graph->numVertices; i++) {
        scanf("%s", &graph->vertices[i].data);
        graph->vertices[i].first = NULL;
    }
    printf("输入边:");
    for (int i = 0; i < graph->numEdges; i++) {
        char a[2], b[2];
        scanf("%s%s", a, b);
        int index_1 = GetAlGraphIndex(graph, a);
        int index_2 = GetAlGraphIndex(graph, b);
        ArcNode *node1 = (ArcNode *) malloc(sizeof(ArcNode));
        node1->adjarc = index_2;
        node1->next = graph->vertices[index_1].first;
        graph->vertices[index_1].first = node1;
    }
}

// 邻接表
void GetNeighborAlGraph(AlGraph *graph, char *node1, char *node2) {
    int index_1 = GetAlGraphIndex(graph, node1);
    int index_2 = GetAlGraphIndex(graph, node2);
    ArcNode *index = graph->vertices[index_1].first;
    while (index->adjarc != index_2) {
        index = index->next;
    }
    index = index->next;
    if (index != NULL) {
        printf("%s\n", &graph->vertices[index->adjarc].data);
    }
}

int main() {
//    MGraph *graph_m = (MGraph *) malloc(sizeof(MGraph));
//    CreateMGraph(graph_m);
    char node1 = '0';
    char node2 = '3';
//    GetNeighborMGraph(graph_m, &node1, &node2);

    AlGraph *graph_a = (AlGraph *) malloc(sizeof(AlGraph));
    CreateAlGraph(graph_a);
    GetNeighborAlGraph(graph_a, &node1, &node2);
}