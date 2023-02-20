#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 二叉排序树的创建

typedef struct BiTNode {
    int data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

void InitNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

BiTNode *FindInsertLocation(BiTree T, int data) {
    BiTNode *pointer = T;
    BiTNode *res;
    while (pointer) {
        if (data < pointer->data) {
            if (pointer->left == NULL) {
                res = pointer;
            }
            pointer = pointer->left;
        } else if (data > pointer->data) {
            if(pointer->right == NULL){
                res = pointer;
            }
            pointer = pointer->right;
        }
    }
    return res;
}

void CreateBST(BiTree T, const int *data, int length) {
    T->data = data[0];

    for (int i = 1; i < length; i++) {
        BiTNode *temp = (BiTNode *) malloc(sizeof(BiTNode));
        InitNode(temp);
        temp->data = data[i];
        BiTNode *insertPointer = FindInsertLocation(T, data[i]);
        if (data[i] < insertPointer->data) {
            insertPointer->left = temp;
        } else {
            insertPointer->right = temp;
        }
    }
}

void PrintVal(BiTree T) {
    if (T) {
        PrintVal(T->left);
        printf("%d\t", T->data);
        PrintVal(T->right);
    }
}

int main() {
    int data[] = {5, 7, 3, 9, 2, 1, 6};
    int length = sizeof(data) / sizeof(data[0]);
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitNode(T);
    CreateBST(T, data, length);
    PrintVal(T);
}