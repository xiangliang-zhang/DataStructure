#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

// 判断无向图是否是树
// 邻接表 + 深度

#define MaxVertices 100
int visited[MaxVertices];

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

int GetIndex(AlGraph *graph, const char *s) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i].data == *s) {
            return i;
        }
    }
    return -1;
}

void CreateGraph(AlGraph *graph) {
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
        int index_a = GetIndex(graph, a);
        int index_b = GetIndex(graph, b);

        ArcNode *node1 = (ArcNode *) malloc(sizeof(ArcNode));
        node1->adjarc = index_b;
        node1->next = graph->vertices[index_a].first;
        graph->vertices[index_a].first = node1;

        ArcNode *node2 = (ArcNode *) malloc(sizeof(ArcNode));
        node2->adjarc = index_a;
        node2->next = graph->vertices[index_b].first;
        graph->vertices[index_b].first = node2;
    }
}

typedef struct Stack {
    VNode *data[MaxVertices];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

void Push(Stack *s, VNode *node) {
    if (s->head < MaxVertices - 1) {
        s->head++;
        s->data[s->head] = node;
    }
}

VNode *Pop(Stack *s) {
    if (!EmptyStack(s)) {
        VNode *res = s->data[s->head];
        s->head--;
        return res;
    }
}

VNode *GetTop(Stack *s) {
    if (!EmptyStack(s)) {
        return s->data[s->head];
    }
}

void DFS(AlGraph *graph, VNode *node, int *numCalVertices, int *numCalEdges) {
    int index = GetIndex(graph, &node->data);
    visited[index] = 1;
    (*numCalVertices)++;

    ArcNode *a_node = node->first;
    while (a_node) {
        (*numCalEdges)++;
        if (visited[a_node->adjarc] == 0) {
            visited[a_node->adjarc] = 1;
            DFS(graph, &graph->vertices[a_node->adjarc], numCalVertices, numCalEdges);
        }
        a_node = a_node->next;
    }
}

bool IsTree(AlGraph *graph) {
    int numCalVertices = 0;
    int numCalEdges = 0;
    DFS(graph, &graph->vertices[0], &numCalVertices, &numCalEdges);
    if (graph->numVertices == numCalVertices && numCalEdges / 2 == graph->numVertices - 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    AlGraph *graph = (AlGraph *) malloc(sizeof(AlGraph));
    CreateGraph(graph);
    int res = IsTree(graph);
    if (res == 0) {
        printf("false");
    } else {
        printf("true");
    }
}