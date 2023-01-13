#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 先序输出结点的值和所在的层次

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

    BiTNode *t9 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t9);
    t9->data = 9;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    T->right = t5;
    t5->left = t6;
    t5->right = t7;
    t6->left = t8;
    t7->right = t9;
}

void PrintValLevel(BiTree T, int height) {
    if (T) {
        printf("%d\t%d\n", T->data, height++);
        PrintValLevel(T->left, height);
        PrintValLevel(T->right, height);
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    int height = 1;
    PrintValLevel(T, height);
}