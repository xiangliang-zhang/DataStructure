#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 计算二叉树双分支结点个数

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
    t3->left = t5;
    t3->right = t6;
}


void GetTwoBranchNum(BiTree T, int *num) {
    if (T) {
        if (T->left && T->right) (*num)++;
        GetTwoBranchNum(T->left, num);
        GetTwoBranchNum(T->right, num);
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    int num = 0;
    GetTwoBranchNum(T, &num);
    printf("%d\n", num);
}