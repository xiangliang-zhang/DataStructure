#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"

// 已知满二叉树的先序序列，求后序序列

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

BiTNode *SetValue(const int PreOrder[], int length) {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    BiTNode *PreOrderNode[length + 1];
    for (int i = 1; i <= length; i++) {
        PreOrderNode[i] = (BiTNode *) malloc(sizeof(BiTNode));
        InitBiTNode(PreOrderNode[i]);
        PreOrderNode[i]->data = PreOrder[i - 1];
    }
    for (int i = 1; i <= length / 2; i++) {
        PreOrderNode[i]->left = PreOrderNode[2 * i];
        PreOrderNode[i]->right = PreOrderNode[2 * i + 1];
    }
    T = PreOrderNode[1];
    return T;
}

void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->left);
        PostOrder(T->right);
        printf("%d\n", T->data);
    }
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

BiTNode *GetTop(Stack *s) {
    if (s->head != -1) {
        return s->data[s->head];
    }
}

void PostOrderNoRecursion(BiTree T) {
    BiTNode *t = T;
    BiTNode *pre = NULL;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    while (t || !EmptyStack(s)) {
        if (t) {
            Push(s, t);
            t = t->left;
        } else {
            t = GetTop(s);
            if (t->right && t->right != pre) {
                t = t->right;
            } else {
                t = Pop(s);
                printf("%d\n", t->data);
                pre = t;
                t = NULL;
            }
        }
    }
}


int main() {
    int PreOrder[] = {0, 1, 2, 3, 4, 5, 6};
    int length = sizeof(PreOrder) / sizeof(PreOrder[0]);
    BiTNode *root = SetValue(PreOrder, length);
    PostOrder(root);
    printf("\n------------\n");
    PostOrderNoRecursion(root);

}