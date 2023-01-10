#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 中序线索二叉树里结点的后序序列的前驱

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
    int ltag, rtag;
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
    node->ltag = 0;
    node->rtag = 0;
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

BiTNode *pre = NULL;

void InThread(BiTree T) {
    if (T) {
        InThread(T->left);
        if (T->ltag == 0) {
            if (T->left == NULL) {
                T->left = pre;
                T->ltag = 1;
            }
            if (pre && pre->right == NULL) {
                pre->right = T;
                pre->rtag = 1;
            }
            pre = T;
        }
        InThread(T->right);
    }
}

BiTNode *GetPostOrderPre(BiTree T, BiTNode *node) {
    if (node->rtag == 0) {  // 目标结点有右子树（此时无需管有无左子树），它的前驱就是自己的右孩子
        return node->right;
    } else if (node->ltag == 0) { // 目标节点没有右子树，有左子树, 前驱就是自己的左孩子
        return node->left;
    } else if (node->left == NULL) {  // 目标节点是中序第一个结点
        return NULL;
    } else {
        while (node->ltag == 1 && node->left != NULL) {  // 一直想上找目标结点的祖先直至祖先有左孩子
            node = node->left;
        }
        if (node->ltag == 0) {
            return node->left;
        } else {
            return NULL;
        }
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);

    // 构建中序线索树
    InThread(T);
    pre->right = NULL;
    pre->rtag = 1;

    BiTNode *res = GetPostOrderPre(T, T->right->left);
    if (res != NULL) {
        printf("%d\n", res->data);
    }
}