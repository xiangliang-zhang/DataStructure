#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 二叉树自下向上、自右到左层次遍历

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

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;
    t4->left = t5;
    t4->right = t6;
}

#define MaxSize 100

typedef struct Stack {
    int data[MaxSize];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

void Push(Stack *s, int val) {
    if (s->head < MaxSize - 1) {
        s->head++;
        s->data[s->head] = val;
    }
}

int Pop(Stack *s) {
    if (s->head > -1) {
        int t = s->data[s->head];
        s->head--;
        return t;
    }
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

typedef struct Queue {
    BiTNode *data[MaxSize];
    int head, tail;
} Queue;

void InitQueue(Queue *q) {
    q->head = 0;
    q->tail = -1;
}

void EnQueue(Queue *q, BiTNode *val) {
    if (q->tail + 1 < MaxSize) {
        q->tail++;
        q->data[q->tail] = val;
    }
}

BiTNode *DeQueue(Queue *q) {
    if (q->head <= q->tail) {
        BiTNode *t = q->data[q->head];
        q->head++;
        return t;
    }
}

bool EmptyQueue(Queue *s) {
    if (s->head > s->tail) {
        return true;
    } else {
        return false;
    }
}

void LevelOrder(BiTree T) {
    BiTNode *t = T;
    Queue *q = (Queue *) malloc(sizeof(Queue));
    InitQueue(q);
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    EnQueue(q, t);
    while (t && !EmptyQueue(q)) {
        t = DeQueue(q);
        Push(s, t->data);
        if (t->left) EnQueue(q, t->left);
        if (t->right) EnQueue(q, t->right);
    }
    while (!EmptyStack(s)) {
        int res = Pop(s);
        printf("%d\n", res);
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    LevelOrder(T);
}