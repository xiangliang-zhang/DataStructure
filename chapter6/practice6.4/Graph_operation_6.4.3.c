#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

// 图的深度遍历非递归

// 邻接表存储

#define MaxVertices 10
int visited[MaxVertices];

typedef struct ArcNode {
    int adjvex;
    struct ArcNode *next;
} ArcNode;

typedef struct VNode {
    char data;
    ArcNode *first;
} VNode, AdjList[MaxVertices];

typedef struct {
    int numVertices, numEdges;
    AdjList vertices;
} AlGraph;

int getIndex(AlGraph *graph, const char s) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (s == graph->vertices[i].data) {
            return i;
        }
    }
    return -1;
}

int createGraph(AlGraph *graph) {
    printf("输入顶点数:");
    scanf("%d", &graph->numVertices);
    printf("输入边数:");
    scanf("%d", &graph->numEdges);
    printf("输入顶点:");
    for (int i = 0; i < graph->numVertices; i++) {
        scanf("%s", &graph->vertices[i].data);
        getchar();
        graph->vertices[i].first = NULL;
    }
    printf("输入边:");
    for (int i = 0; i < graph->numEdges; i++) {
        char a[2], b[2];
        scanf("%s%s", a, b);
        int index_1 = getIndex(graph, *a);
        int index_2 = getIndex(graph, *b);
        ArcNode *node = (ArcNode *) malloc(sizeof(ArcNode));
        node->adjvex = index_2;
        node->next = graph->vertices[index_1].first;
        graph->vertices[index_1].first = node;
    }
    return 0;
}

typedef struct stack {
    VNode *data[MaxVertices];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

void Push(Stack *s, VNode *node) {
    if (s->head < MaxVertices - 1) {
        s->head++;
        s->data[s->head] = node;
    }
}

VNode *Pop(Stack *s) {
    if (s->head >= 0) {
        VNode *res = s->data[s->head];
        s->head--;
        return res;
    }
}

VNode getTop(Stack *s) {
    if (s->head > -1) {
        return *s->data[s->head];
    }
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    }
    return false;
}

void DFS(AlGraph *graph) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);

    // 初始顶点处理
    Push(s, &graph->vertices[0]);
    printf("%c\n", getTop(s).data);
    visited[0] = 1;

    while (!EmptyStack(s)) {
        if (getTop(s).first != NULL) {
            ArcNode *node = getTop(s).first;
            if (visited[node->adjvex] == 0) {
                Push(s, &graph->vertices[node->adjvex]);
                printf("%c\n", getTop(s).data);
                visited[node->adjvex] = 1;
            } else {
                while (node != NULL && visited[node->adjvex] == 1) {
                    node = node->next;
                    if (node == NULL) {
                        Pop(s);
                    }
                }
                if (node != NULL) {
                    Push(s, &graph->vertices[node->adjvex]);
                    visited[node->adjvex] = 1;
                    printf("%c\n", getTop(s).data);
                }
            }
        } else {
            Pop(s);
        }
    }
}

int main() {
    AlGraph *graph = (AlGraph *) malloc(sizeof(AlGraph));
    createGraph(graph);
    DFS(graph);
}