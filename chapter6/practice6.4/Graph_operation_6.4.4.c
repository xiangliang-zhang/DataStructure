#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"


// 深度和广度在邻接表中判断是否存在顶点a到顶点b的路径

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


typedef struct Queue {
    VNode *data[MaxVertices];
    int head, tail;
} Queue;

void InitQueue(Queue *q) {
    q->head = 0;
    q->tail = -1;
}

void EnQueue(Queue *q, VNode *node) {
    if (q->tail < MaxVertices - 1) {
        q->tail++;
        q->data[q->tail] = node;
    }
}

VNode *DeQueue(Queue *q) {
    if (q->head <= q->tail) {
        VNode *res = q->data[q->head];
        q->head++;
        return res;
    }
}

bool EmptyQueue(Queue *q) {
    if (q->head > q->tail) {
        return true;
    } else {
        return false;
    }
}

int GetIndex(AlGraph *graph, char *val) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i].data == *val) {
            return i;
        }
    }
    return -1;
}

bool BFS(AlGraph *graph, VNode *node1, VNode *node2) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    InitQueue(q);
    int begin_index = GetIndex(graph, &node1->data);
    EnQueue(q, &graph->vertices[begin_index]);
    visited[begin_index] = 1;
    while (!EmptyQueue(q)) {
        VNode *n = DeQueue(q);
        if (n == node2) return true;
        ArcNode *temp = n->first;
        while (temp && visited[temp->adjarc] == 0) {
            EnQueue(q, &graph->vertices[temp->adjarc]);
            visited[temp->adjarc] = 1;
            temp = temp->next;
        }
    }
    return false;
}

typedef struct Stack {
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
    if (s->head > -1) {
        VNode *res = s->data[s->head];
        s->head--;
        return res;
    }
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

VNode *GetTop(Stack *s) {
    if (s->head > -1) {
        return s->data[s->head];
    }
}

bool DFS(AlGraph *graph, VNode *node1, VNode *node2) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    Push(s, node1);
    visited[GetIndex(graph, &node1->data)] = 1;
    while (!EmptyStack(s)) {
        VNode *v = GetTop(s);
        if (v == node2) return true;
        ArcNode *a = v->first;
        while (a && visited[a->adjarc] == 1) {  // 邻接表中的前几个顶点均已被访问
            a = a->next;
        }
        if (a) {
            if (visited[a->adjarc] == 0) {
                Push(s, &graph->vertices[a->adjarc]);
                visited[a->adjarc] = 1;
            }
        } else {
            Pop(s);
        }
    }
    return false;
}

int CreateGraph(AlGraph *graph) {
    printf("输入顶点数:");
    scanf("%d", &graph->numVertices);
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
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
        ArcNode *node = (ArcNode *) malloc(sizeof(ArcNode));
        int index_a = GetIndex(graph, a);
        int index_b = GetIndex(graph, b);
        node->adjarc = index_b;
        node->next = graph->vertices[index_a].first;
        graph->vertices[index_a].first = node;
    }
    return 0;
}

int main() {
    AlGraph *graph = (AlGraph *) malloc(sizeof(AlGraph));
    CreateGraph(graph);
//    int res1 = BFS(graph, &graph->vertices[2], &graph->vertices[0]);
//    printf("%d\n", res1);
    int res2 = DFS(graph, &graph->vertices[2], &graph->vertices[1]);
    printf("%d\n", res2);
}