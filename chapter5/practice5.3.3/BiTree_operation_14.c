#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 求非空二叉树的宽度

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

    BiTNode *t6 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t6);
    t6->data = 6;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;
    t4->left = t5;
    t4->right = t6;
}

#define MaxSize 100
typedef struct Queue {
    BiTNode *data[MaxSize];
    int head, tail;
} Queue;

void InitQueue(Queue *q) {
    q->tail = -1;
    q->head = 0;
}

void EnQueue(Queue *q, BiTNode *node) {
    if (q->tail < MaxSize - 1) {
        q->tail++;
        q->data[q->tail] = node;
    }
}

BiTNode *DeQueue(Queue *q) {
    if (q->head <= q->tail) {
        BiTNode *t = q->data[q->head];
        q->head++;
        return t;
    }
}

bool EmptyQueue(Queue *q) {
    if (q->head <= q->tail) {
        return false;
    } else {
        return true;
    }
}

int GetWidth(BiTree T) {
    BiTNode *t = T;
    int max_width = 1;
    Queue *q1 = (Queue *) malloc(sizeof(Queue));
    InitQueue(q1);
    EnQueue(q1, t);

    Queue *q2 = (Queue *) malloc(sizeof(Queue));
    InitQueue(q2);
    int cur_width = 0;
    while (t && !EmptyQueue(q1)) {
        while (!EmptyQueue(q1)) {
            t = DeQueue(q1);
            cur_width++;
            if (t->left) {
                EnQueue(q2, t->left);
            }
            if (t->right) {
                EnQueue(q2, t->right);
            }
        }
        if (cur_width > max_width) max_width = cur_width;
        cur_width = 0;
        while (!EmptyQueue(q2)) {
            t = DeQueue(q2);
            if (t->left) {
                EnQueue(q1, t->left);
            }
            if (t->right) {
                EnQueue(q1, t->right);
            }
        }
        if (cur_width > max_width) max_width = cur_width;
        cur_width = 0;
    }
    return max_width;
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    int res = GetWidth(T);
    printf("%d\n", res);
}