#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 二叉树的非递归遍历

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
    int ltag, rtag;
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *t) {
    t->left = NULL;
    t->right = NULL;
    t->ltag = 0;
    t->rtag = 0;
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
    BiTNode *data[MaxSize];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

void Push(Stack *s, BiTNode *node) {
    s->head++;
    s->data[s->head] = node;
}

BiTNode *Pop(Stack *s) {
    BiTNode *t = s->data[s->head];
    s->head--;
    return t;
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

BiTNode *GetTopNode(Stack *s) {
    return s->data[s->head];
}

void PostOrderNoRecursion(BiTree T) {
    BiTNode *t = T;
    BiTNode *r = NULL;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    while (t || !EmptyStack(s)) {
        if (t) {
            Push(s, t);
            t = t->left;
        } else {
            t = GetTopNode(s);
            if (t->right && t->right != r) {
                t = t->right;
            } else {
                t = Pop(s);
                r = t;
                printf("%d\n", t->data);
                t = NULL;  // 点睛之笔
            }
        }
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    PostOrderNoRecursion(T);
    return 0;
}