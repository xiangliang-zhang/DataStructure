#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 计算第k小的元素

typedef struct BiTNode {
    int data;
    struct BiTNode *left, *right;
    int count; // 存储以该结点为根的子树上的结点个数
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

void SetValue(BiTree T) {
    T->data = 4;
    T->count = 8;

    BiTNode *node1 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node2 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node3 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node5 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node6 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node7 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node8 = (BiTNode *) malloc(sizeof(BiTNode));

    InitBiTNode(node1);
    InitBiTNode(node2);
    InitBiTNode(node3);
    InitBiTNode(node5);
    InitBiTNode(node6);
    InitBiTNode(node7);
    InitBiTNode(node8);

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node5->data = 5;
    node6->data = 6;
    node7->data = 7;
    node8->data = 8;

    node1->count = 1;
    node2->count = 3;
    node3->count = 1;
    node5->count = 1;
    node6->count = 4;
    node7->count = 2;
    node8->count = 1;

    T->left = node2;
    node2->left = node1;
    node2->right = node3;

    T->right = node6;
    node6->left = node5;
    node6->right = node7;
    node7->right = node8;

}

BiTNode *GetTarget(BiTree T, int k) {
    if (T->left == NULL) {
        if (k == 1) return T;
        else {
            return GetTarget(T->right, k - 1);
        }
    } else {
        if (k == T->left->count + 1) return T;
        if (k > T->left->count + 1) return GetTarget(T->right, k - (T->left->count + 1));  // 需要注意的情况
        if (k < T->left->count + 1) return GetTarget(T->left, k);
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    BiTNode *res = GetTarget(T, 8);
    printf("%d\n", res->data);
}