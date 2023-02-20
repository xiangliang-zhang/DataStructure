#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 非递归方法求二叉树的高度

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

    BiTNode *t7 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t7);
    t7->data = 7;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;
    t4->left = t5;
    t4->right = t6;
//    t6->right = t7;
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

bool EmptyQueue(Queue *q) {
    if (q->head > q->tail) {
        return true;
    } else {
        return false;
    }
}

void EnQueue(Queue *q, BiTNode *node) {
    if (q->tail < MaxSize - 1) {
        q->tail++;
        q->data[q->tail] = node;
    }
}

BiTNode *DeQueue(Queue *q) {
    if (!EmptyQueue(q)) {
        BiTNode *t = q->data[q->head];
        q->head++;
        return t;
    }
}


int GetHeight(BiTree T) {
    Queue *q1 = (Queue *) malloc(sizeof(Queue));
    Queue *q2 = (Queue *) malloc(sizeof(Queue));
    InitQueue(q1);
    InitQueue(q2);

    int max_high = 0;
    BiTNode *pointer = T;
    EnQueue(q1, pointer);

    while (!EmptyQueue(q1) || !EmptyQueue(q2)) {
        if (!EmptyQueue(q1)) max_high++;
        while (!EmptyQueue(q1)) {
            pointer = DeQueue(q1);
            if (pointer->left) {
                EnQueue(q2, pointer->left);
            }
            if (pointer->right) {
                EnQueue(q2, pointer->right);
            }
        }

        if (!EmptyQueue(q2)) max_high++;
        while (!EmptyQueue(q2)) {
            pointer = DeQueue(q2);
            if (pointer->left) {
                EnQueue(q1, pointer->left);
            }
            if (pointer->right) {
                EnQueue(q1, pointer->right);
            }
        }
    }

    return max_high;
}

int main() {
    BiTNode *T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    int res = GetHeight(T);
    printf("%d\n", res);
}