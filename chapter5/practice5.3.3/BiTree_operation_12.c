#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 打印值为x的结点的祖先值

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

void SetValue(BiTree T) {
    T->data = 0;

    BiTNode *t1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t1);
    t1->data = 1;

    BiTNode *t2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t2);
    t2->data = 2;

    BiTNode *t3 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t3);
    t3->data = 3;

    BiTNode *t4 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t4);
    t4->data = 4;

    BiTNode *t5 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t5);
    t5->data = 5;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;
    t4->right = t5;
}

#define MaxSize 100

typedef struct Queue {
    BiTNode *data[MaxSize];
    int head, tail;
} Queue;

void InitQueue(Queue *q) {
    q->head = 0;
    q->tail = -1;
}

void EnQueue(Queue *q, BiTNode *node) {
    if (q->tail < MaxSize - 1) {
        q->tail++;
        q->data[q->tail] = node;
    }
}

BiTNode *DeQueue(Queue *q) {
    if (q->head <= q->tail) {
        BiTNode *temp = q->data[q->head];
        q->head++;
        return temp;
    }
}

bool EmptyQueue(Queue *q) {
    if (q->head <= q->tail) {
        return false;
    } else {
        return true;
    }
}

int GetParent(BiTree T, int num) {
    BiTNode *t = T;
    Queue *q = (Queue *) malloc(sizeof(Queue));
    InitQueue(q);
    EnQueue(q, t);
    while (t && !EmptyQueue(q)) {
        t = DeQueue(q);
        if ((t->left && t->left->data == num) || (t->right && t->right->data == num)) {
            return t->data;
        } else {
            if (t->left) {
                EnQueue(q, t->left);
            }
            if (t->right) {
                EnQueue(q, t->right);
            }
        }
    }
    return -1;
}

int main() {
    BiTree T = (BiTree) malloc(sizeof(BiTree));
    InitBiTNode(T);
    SetValue(T);
    int res = GetParent(T, 5);
    printf("%d\n", res);
}
