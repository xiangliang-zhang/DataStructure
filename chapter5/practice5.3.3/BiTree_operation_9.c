#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 二叉树左右子树交换
typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *t) {
    t->left = NULL;
    t->right = NULL;
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

    BiTNode *t7 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t7);
    t7->data = 7;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;
    t4->left = t5;
    t4->right = t6;
    t2->left = t7;
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

void ChangeOrder(BiTree T) {
    BiTNode *t = T;
    Queue *q = (Queue *) malloc(sizeof(Queue));
    InitQueue(q);
    EnQueue(q, t);
    while (t && !EmptyQueue(q)) {
        t = DeQueue(q);
        BiTNode *temp = t->left;
        t->left = t->right;
        t->right = temp;
        if (t->left) EnQueue(q, t->left);
        if (t->right) EnQueue(q, t->right);
    }
}

void PreOrder(BiTree T) {
    if (T) {
        printf("%d\n", T->data);
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    ChangeOrder(T);
    PreOrder(T);
}