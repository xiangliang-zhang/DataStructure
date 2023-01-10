#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 删除树中以元素值为x的结点为根的子树

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
    t5->data = 2;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t5;
    t5->left = t4;
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
        BiTNode *res = q->data[q->head];
        q->head++;
        return res;
    }
}

bool EmptyQueue(Queue *q) {
    if (q->head <= q->tail) {
        return false;
    } else {
        return true;
    }
}

void freeSpace(BiTNode *node) {
    if (node) {
        freeSpace(node->left);
        freeSpace(node->right);
        free(node);
    }
}

void DeleteELe(BiTree T, BiTNode *target) {
    BiTNode *t = T;
    Queue *q = (Queue *) malloc(sizeof(Queue));
    InitQueue(q);
    EnQueue(q, t);
    BiTNode *point;
    if (t == target) {
        freeSpace(t);
    } else {
        while (t && !EmptyQueue(q)) {
            t = DeQueue(q);
            if (t->left) {
                if (t->left->data == target->data) {
                    point = t->left;
                    t->left = NULL;
                    freeSpace(point);
                } else {
                    EnQueue(q, t->left);
                }
            }
            if (t->right) {
                if (t->right->data == target->data) {
                    point = t->right;
                    t->right = NULL;
                    freeSpace(point);
                } else {
                    EnQueue(q, t->right);
                }
            }
        }
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
    BiTNode *t = (BiTNode *) malloc(sizeof(BiTNode));
    t->data = 2;
    DeleteELe(T, t);
    PreOrder(T);
}