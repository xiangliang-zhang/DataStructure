#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

// �ڽӱ�洢,�����һ���㵽��һ�������еļ�·��

#define MaxVertices 100
int visited[MaxVertices];

typedef struct ArcNode {
    int adjvex;
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


int GetIndex(AlGraph *graph, const char s[]) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i].data == *s) {
            return i;
        }
    }
    return -1;
}

int CreateGraph(AlGraph *graph) {
    printf("���붥����:");
    scanf("%d", &graph->numVertices);
    printf("�������:");
    scanf("%d", &graph->numEdges);
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    printf("���붥��:");
    for (int i = 0; i < graph->numVertices; i++) {
        scanf("%s", &graph->vertices[i].data);
        graph->vertices[i].first = NULL;
    }
    printf("�����:");
    for (int i = 0; i < graph->numEdges; i++) {
        char a[2], b[2];
        scanf("%s%s", a, b);
        int index_a = GetIndex(graph, a);
        int index_b = GetIndex(graph, b);
        ArcNode *node = (ArcNode *) malloc(sizeof(ArcNode));
        node->adjvex = index_b;
        node->next = graph->vertices[index_a].first;
        graph->vertices[index_a].first = node;

//        ����ͼ
        ArcNode *node2 = (ArcNode *) malloc(sizeof(ArcNode));
        node2->adjvex = index_a;
        node2->next = graph->vertices[index_b].first;
        graph->vertices[index_b].first = node2;
    }
    return 0;
}

// �����������, �ݹ�
void GetPath(AlGraph *graph, VNode *node1, VNode *node2, VNode *path[], int d) {
    // ���ҵ���ǰ����ʱ�Ĳ���
    d++;
    visited[GetIndex(graph, &node1->data)] = 1;
    path[d] = node1;
    if (node1 == node2) {
        for (int i = 0; i <= d; i++) {
            printf("%c\t", path[i]->data);
        }
    }

    // �Ӹö���ĵ�һ��first��Ȳ��ң�����next;
    ArcNode *a = node1->first;
    while (a != NULL) {
        int w = a->adjvex;
        if (visited[w] == 0) {
            GetPath(graph, &graph->vertices[w], node2, path, d);
        }
        a = a->next;
    }

    // �ݹ�����󣬷�����0
    visited[GetIndex(graph, &node1->data)] = 0;

}

int main() {
    AlGraph *graph = (AlGraph *) malloc(sizeof(AlGraph));
    CreateGraph(graph);
    VNode *path[MaxVertices];
    int d = -1;
    GetPath(graph, &graph->vertices[0], &graph->vertices[8], path, d);
}