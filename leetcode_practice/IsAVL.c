#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 判断二叉树是否是平衡二叉树

#define MaxNodes 100

typedef struct BiTNode {
    int data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

typedef struct Stack {
    BiTNode *data[MaxNodes];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

void Push(Stack *s, BiTNode *node) {
    if (s->head < MaxNodes - 1) {
        s->head++;
        s->data[s->head] = node;
    }
}

BiTNode *Pop(Stack *s) {
    if (!EmptyStack(s)) {
        BiTNode *res = s->data[s->head];
        s->head--;
        return res;
    }
}

BiTNode *GetTop(Stack *s) {
    if (!EmptyStack(s)) {
        return s->data[s->head];
    }
}

void InitNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

void SetValue(BiTree T) {
    T->data = 0;

    BiTNode *node1 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node2 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node3 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node4 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node5 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node6 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node7 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node8 = (BiTNode *) malloc(sizeof(BiTNode));

    InitNode(node1);
    InitNode(node2);
    InitNode(node3);
    InitNode(node4);
    InitNode(node5);
    InitNode(node6);
    InitNode(node7);
    InitNode(node8);

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;
    node6->data = 6;
    node7->data = 7;
    node8->data = 8;


    T->left = node1;
    node1->left = node2;
    node1->right = node3;
    T->right = node4;
    node4->left = node5;
    node4->right = node6;
    node6->right = node7;
    node5->left = node8;
}

void IsAVL(BiTree T, int *balance, int *h) {
    int balanceLeft = 0, balanceRight = 0, heightLeft = 0, heightRight = 0;
    if (T == NULL) {
        *h = 0;
        *balance = 1;
    } else if (T->left == NULL && T->right == NULL) {
        *h = 1;
        *balance = 1;
    } else {
        IsAVL(T->left, &balanceLeft, &heightLeft);
        IsAVL(T->right, &balanceRight, &heightRight);
        // 以下代码存储分支结点的高度和是否平衡
        *h = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
        if (abs(heightLeft - heightRight) < 2) {
            *balance = balanceLeft && balanceRight;
        } else {
            *balance = 0;
        }
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitNode(T);
    SetValue(T);
    int balance = 0;
    int height = 0;
    IsAVL(T, &balance, &height);
    if (balance == 0) {
        printf("not");
    } else {
        printf("yes");
    }
}