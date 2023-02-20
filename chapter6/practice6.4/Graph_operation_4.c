#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 图的邻接表转邻接矩阵

typedef char VertexType;
typedef int EdgeType;

// 图的邻接表表示
#define MaxVertexNum 100
typedef struct ArcNode {  // 边表
    int adjvex;
    struct ArcNode *next;
} ArcNode;

typedef struct VNode {  // 顶点表
    VertexType data;
    ArcNode *first;
} VNode, AdjList[MaxVertexNum];

typedef struct { // 邻接表
    int vexnum, arcnum;
    AdjList vertices;
} ALGraph;

// 图的邻接矩阵表示

typedef struct {
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;

void createGraph(ALGraph *graph) {
    printf("创建邻接表存储！\n");
    scanf("%d", &graph->vexnum);
    printf("输入图的边数:");
    scanf("%d", &graph->arcnum);
    getchar();
    printf("输入顶点信息:");
    for (int i = 0; i < graph->vexnum; i++) {
        char t;
        scanf("%c", &t);
        getchar();
        VNode v;
        v.data = t;
        v.first = NULL;
        graph->vertices[i] = v;
    }
    printf("输入边信息:");
    for (int i = 0; i < graph->arcnum; i++) {
        int a;
        int b;
        scanf("%d%d", &a, &b);
        ArcNode *node = (ArcNode *) malloc(sizeof(ArcNode));
        node->adjvex = b;
        node->next = graph->vertices[a].first;
        graph->vertices[a].first = node;
    }
}

void convertToTable(ALGraph *graph, MGraph *graph2) {
    graph2->vexnum = graph->vexnum;
    graph2->arcnum = graph->arcnum;
    for (int i = 0; i < graph->vexnum; i++) {
        graph2->Vex[i] = graph->vertices[i].data;
    }
    for (int i = 0; i < graph2->vexnum; i++) {
        for (int j = 0; j < graph2->vexnum; j++) {
            graph2->Edge[i][j] = 0;
        }
    }
    for (int i = 0; i < graph->vexnum; i++) {
        if (graph->vertices[i].first != NULL) {
            ArcNode *temp = graph->vertices[i].first;
            while (temp) {
                graph2->Edge[i][temp->adjvex] = 1;
                temp = temp->next;
            }
        }
    }
}

void PrintData(MGraph *graph) {
    for (int i = 0; i < graph->vexnum; i++) {
        for (int j = 0; j < graph->vexnum; j++) {
            printf("%d   ", graph->Edge[i][j]);
        }
        printf("\n");
    }
}

int main() {
    ALGraph *graph = (ALGraph *) malloc(sizeof(ALGraph));
    createGraph(graph);
    MGraph *graph2 = (MGraph *) malloc(sizeof(MGraph));
    convertToTable(graph, graph2);
    PrintData(graph2);
}

// 顶点数：5
// 边数：5

// 顶点: 0 1 2 3 4
// 边: 0-1 0-2 0-3 2-3 2-4
//注意点:scanf吃回车