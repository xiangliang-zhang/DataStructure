#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// ͼ���ڽӱ�ת�ڽӾ���

typedef char VertexType;
typedef int EdgeType;

// ͼ���ڽӱ��ʾ
#define MaxVertexNum 100
typedef struct ArcNode {  // �߱�
    int adjvex;
    struct ArcNode *next;
} ArcNode;

typedef struct VNode {  // �����
    VertexType data;
    ArcNode *first;
} VNode, AdjList[MaxVertexNum];

typedef struct { // �ڽӱ�
    int vexnum, arcnum;
    AdjList vertices;
} ALGraph;

// ͼ���ڽӾ����ʾ

typedef struct {
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;

void createGraph(ALGraph *graph) {
    printf("�����ڽӱ�洢��\n");
    scanf("%d", &graph->vexnum);
    printf("����ͼ�ı���:");
    scanf("%d", &graph->arcnum);
    getchar();
    printf("���붥����Ϣ:");
    for (int i = 0; i < graph->vexnum; i++) {
        char t;
        scanf("%c", &t);
        getchar();
        VNode v;
        v.data = t;
        v.first = NULL;
        graph->vertices[i] = v;
    }
    printf("�������Ϣ:");
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

// ��������5
// ������5

// ����: 0 1 2 3 4
// ��: 0-1 0-2 0-3 2-3 2-4
//ע���:scanf�Իس�