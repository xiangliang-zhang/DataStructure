#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// �ж�����ͼ�Ƿ�����: n��������ͨͼ������Ϊn-1
// ����ͼ + �ڽӾ���洢 +  ��ȱ���


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
    for (int j = 0; j < graph->numEdges; j++) {
        scanf("%s%s", s1, s2);
        int a = getIndex(graph, s1);
        int b = getIndex(graph, s2);
        graph->Edge[a][b] = 1;
        graph->Edge[b][a] = 1;
    }
}


typedef struct Stack {
    char data[MaxVertices];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    }
    return false;
}

void Push(Stack *s, char c) {
    if (s->head < MaxVertices) {
        s->head++;
        s->data[s->head] = c;
    }
}

char Pop(Stack *s) {
    if (!EmptyStack(s)) {
        char res = s->data[s->head];
        s->head--;
        return res;
    }
}

char GetTop(Stack *s) {
    if (!EmptyStack(s)) {
        return s->data[s->head];
    }
}

int DFS(MGraph *graph, int *numCalEdges, int *numCalVertices) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    Push(s, graph->VerticesList[0]);
    visited[0] = 1;
    (*numCalVertices)++;
    // ���㶥����
    while (!EmptyStack(s)) {
        char t = GetTop(s);
        int t_index = getIndex(graph, &t);
        int i;
        for (i = t_index; i < graph->numVertices; i++) {
            if (graph->Edge[t_index][i] == 1 && visited[i] == 0) {
                Push(s, graph->VerticesList[i]);
                (*numCalVertices)++;
                visited[i] = 1;
                break;
            }
        }
        if (i == graph->numVertices) {
            Pop(s);
        }
    }
    // �������
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = i + 1; j < graph->numVertices; j++) {
            if (graph->Edge[i][j] == 1) {
                (*numCalEdges)++;
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
    DFS(graph, &numCalEdges, &numCalVertices);
    if ((numCalVertices == graph->numVertices) && (numCalEdges == graph->numVertices - 1)) {
        return true;
    } else {
        return false;
    }
}


int main() {
//    system("chcp 65001");  // ����ҳ�ַ�����Ϊutf-8
    setbuf(stdout, NULL);
    MGraph *graph = (MGraph *) malloc(sizeof(MGraph));
    CreatGraph(graph);
    int res = IsTree(graph);
    if (res == 0) {
        printf("��");
    } else {
        printf("��");
    }
}
