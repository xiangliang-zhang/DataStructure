#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 统计二叉树的宽度

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

    BiTNode *t8 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t8);
    t8->data = 8;

    T->left = t1;
    t1->left = t2;
    t2->left = t3;
    t3->left = t4;

    t4->right = t5;
    t5->right = t6;
    t6->right = t7;
    t7->right = t8;
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

int GetWidth(BiTree T) {
    int width = 0;
    BiTNode *t = T;
    Queue *q1 = (Queue *) malloc(sizeof(Queue));
    InitQueue(q1);
    Queue *q2 = (Queue *) malloc(sizeof(Queue));
    InitQueue(q2);
    EnQueue(q1, t);
    while (!EmptyQueue(q1) || !EmptyQueue(q2)) {
        int cur_width = 0;
        while (!EmptyQueue(q1)) {
            t = DeQueue(q1);
            cur_width++;
            if (t->left) EnQueue(q2, t->left);
            if (t->right) EnQueue(q2, t->right);
        }
        if (cur_width > width) width = cur_width;
        cur_width = 0;
        while (!EmptyQueue(q2)) {
            t = DeQueue(q2);
            cur_width++;
            if (t->left) EnQueue(q1, t->left);
            if (t->right) EnQueue(q1, t->right);
        }
        if (cur_width > width) width = cur_width;
    }
    return width;
}


// 统计二叉树的高度

typedef struct Stack {
    BiTNode *data[MaxSize];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

void Push(Stack *s, BiTNode *node) {
    if (s->head < MaxSize - 1) {
        s->head++;
        s->data[s->head] = node;
    }
}

BiTNode *Pop(Stack *s) {
    if (s->head > -1) {
        BiTNode *res = s->data[s->head];
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

int max_height = 0;

void GetHeight(BiTree T, int nums) {
    BiTNode *t = T;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    int height = 0;
    while (t || !EmptyStack(s)) {
        if (t) {
            Push(s, t);
            height++;
            t = t->left;
            if (height > max_height) {
                max_height = height;
            }
        } else {
            t = Pop(s);
            if (t->right == NULL) height--;
            t = t->right;
        }
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    int res1 = GetWidth(T);
    printf("最大宽度为:%d\n", res1);
    int nums = 0;
    GetHeight(T, nums);
    printf("最大高度为:%d\n", max_height);
}