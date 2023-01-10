#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 先序遍历序列中第k个结点的值

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

#define MaxSize 100

typedef struct Stack {
    BiTNode *data[MaxSize];
    int head;
} Stack;

void InitBiTNode(BiTNode *t) {
    t->left = NULL;
    t->right = NULL;
}

void InitStack(Stack *s) {
    s->head = -1;
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
    t4->left = t5;
}

void Push(Stack *s, BiTNode *node) {
    if (s->head < MaxSize - 1) {
        s->head++;
        s->data[s->head] = node;
    }
}

BiTNode *Pop(Stack *s) {
    if (s->head > -1) {
        BiTNode *t = s->data[s->head];
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

int GetEleVal(BiTree T, int num) {
    int number = 0;
    BiTNode *t = T;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    while (t || !EmptyStack(s)) {
        if (t) {
            number++;
            if (num == number) {
                return t->data;
            }
            Push(s, t);
            t = t->left;
        } else {
            t = Pop(s);
            t = t->right;
        }
    }
    return -1;
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    int num = 6;
    int res = GetEleVal(T, num);
    printf("%d\n", res);
}