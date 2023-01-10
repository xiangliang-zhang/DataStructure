#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

// 判断二叉树是否是完全二叉树
typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *T) {
    T->left = NULL;
    T->right = NULL;
}

void SetValue(BiTNode *T) {
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
    T->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = t5;
//    t2->right = t6;
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
        BiTNode *temp = q->data[q->head];
        q->head++;
        return temp;
    }
}

bool EmptyQueue(Queue *q) {
    if (q->tail < q->head) {
        return true;
    } else {
        return false;
    }
}

bool CompleteBiTree(BiTree T) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    InitQueue(q);
    int flag = 0;
    BiTNode *t = T;
    EnQueue(q, t);
    while (t && !EmptyQueue(q)) {
        t = DeQueue(q);
        if (t->left) {
            EnQueue(q, t->left);
            if (flag == 1) {
                return false;
            }
        } else {
            flag = 1;
        }
        if (t->right) {
            if (flag == 1) {
                return false;
            }
            EnQueue(q, t->right);
        } else {
            flag = 1;
        }
    }
    return true;
}

int main() {
    BiTree T = (BiTree) malloc(sizeof(BiTree));
    InitBiTNode(T);
    SetValue(T);
    int res = CompleteBiTree(T);
    printf("%d\n", res);
}