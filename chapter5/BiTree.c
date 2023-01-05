#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 二叉树的初始化

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTree(BiTree T) {
    T->left = NULL;
    T->right = NULL;
}

void AddEle(BiTree T) {
    T->data = 1;

    BiTNode *temp = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(temp);
    temp->data = 2;
    T->left = temp;

    BiTNode *temp2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(temp2);
    temp2->data = 3;
    temp->right = temp2;
}

int main() {
    BiTree T = (BiTree) malloc(sizeof(BiTNode));
    InitBiTree(T);
    AddEle(T);
}