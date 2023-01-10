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

    T->left = t1;
    t1->left = t2;
    t2->left = t3;
    t3->right = t4;
    t4->right = t5;
    t5->right = t6;
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

int GetHeight(BiTree T) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    int max_high = 0;
    int now_high = 0;
    BiTNode *t = T;
    while (t || !EmptyStack(s)) {
        if (t) {
            Push(s, t);
            now_high++;
            t = t->left;
            if (now_high > max_high) {
                max_high = now_high;
            }
        } else {
            t = Pop(s);
            t = t->right;
            if (t == NULL) {
                now_high--;
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