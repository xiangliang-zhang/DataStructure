#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// �ж�����ͼ�Ƿ�����: n��������ͨͼ������Ϊn-1
// �ڽӾ���洢 +  ��ȱ���
// �ڽӱ�洢 + ��ȱ���
// �ڽӱ�洢 + ��ȱ���

// �ڽӾ���洢 + ��ȱ���
#define MaxVertices 100
int visited[MaxVertices];

typedef struct {
    int numVertices, numEdges;
    char VerticesList[MaxVertices];
    int Edge[MaxVertices][MaxVertices];
} MGraph;

int getIndex(MGraph *graph, const char *s) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->VerticesList[i] == *s) {
            return i;
        }
    }
    return -1;
}

void CreatGraph(MGraph *graph) {
    printf("���붥����:");
    scanf("%d", &graph->numVertices);
    printf("�������:");
    scanf("%d", &graph->numEdges);

    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            graph->Edge[i][j] = 0;
        }
    }
    printf("���붥��ֵ:");
    for (int i = 0; i < graph->numVertices; i++) {
        scanf("%s", &graph->VerticesList[i]);
    }
    printf("����ߵ����˶���:");
    char s1[2];
    char s2[2];
    getchar();
    for (int j = 0; j < graph->numEdges; j++) {
        scanf("%s%s", s1, s2);
        int a = getIndex(graph, s1);
        int b = getIndex(graph, s2);
        graph->Edge[a][b] = 1;
        graph->Edge[b][a] = 1;
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
    if (q->tail < q->head) {
        return true;
    }
    return false;
}

void EnQueue(Queue *q, char s) {
    if (q->tail < MaxVertices - 1) {
        q->tail++;
        q->data[q->tail] = s;
    }
}

char DeQueue(Queue *q) {
    if (!EmptyQueue(q)) {
        char t = q->data[q->head];
        q->head++;
        return t;
    }
}


int BFS(MGraph *graph, int *numCalEdges, int *numCalVertices) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    InitQueue(q);
    EnQueue(q, graph->VerticesList[0]);
    visited[0] = 1;
    while (!EmptyQueue(q)) {
        char temp = DeQueue(q);
        (*numCalVertices)++;
        int index = getIndex(graph, &temp);
        for (int i = index + 1; i < graph->numVertices; i++) {
            if (graph->Edge[index][i] == 1) {
                if (visited[i] == 1) {
                    return -1;
                } else {
                    visited[i] = 1;
                    EnQueue(q, graph->VerticesList[i]);
                    (*numCalEdges)++;
                }
            }
        }
    }
    return 0;
}


bool IsTree(MGraph *graph) {
    int numCalVertices = 0;
    int numCalEdges = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    int res = BFS(graph, &numCalEdges, &numCalVertices);
    if (res == -1) {
        return false;
    }
    if ((numCalVertices == graph->numVertices) && (numCalEdges == graph->numVertices - 1)) {
        return true;
    } else {
        return false;
    }
}


int main() {
    MGraph *graph = (MGraph *) malloc(sizeof(MGraph));
    CreatGraph(graph);
    int res = IsTree(graph);
    if (res == 0) {
        printf("��");
    } else {
        printf("��");
    }
}

// �ڽ��������ʱ�����ʹ��%c��������̿ո��س�����������ʹ��%s,����Ҫ����\0λ�õĴ�ţ������1��Ԫ�أ�������Ҫ�����ռ�