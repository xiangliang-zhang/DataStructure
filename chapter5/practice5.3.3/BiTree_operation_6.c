#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 根据序列的先序和中序构建二叉链表

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTNode(BiTree T) {
    T->left = NULL;
    T->right = NULL;
}

BiTNode *GetBiTree(const int *a, const int *b, int length) {
    if (length == 0) {
        return NULL;
    }
    BiTNode *t1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t1);
    t1->data = a[0];
    if (length == 1) {
        return t1;
    }
    int b_index = 0;
    int leftLength, rightLength;
    while (b[b_index] != a[0] && b_index < length) {   //找出中序遍历中根节点的位置
        b_index++;
    }
    leftLength = b_index;        //左子树结点数
    rightLength = length - leftLength - 1;       //右子树结点数

    t1->left = GetBiTree(&a[1], b, leftLength);
    t1->right = GetBiTree(&a[leftLength + 1], &b[leftLength + 1], rightLength);
    return t1;

}

void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->left);
        PostOrder(T->right);
        printf("%d\n", T->data);
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int b[] = {3, 2, 4, 1, 6, 5, 7};
    int length = sizeof(a) / sizeof(a[0]);
    BiTree T = GetBiTree(a, b, length);
    PostOrder(T);
}