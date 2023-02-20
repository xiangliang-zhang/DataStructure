#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// BST结点的删除

typedef struct BiTNode {
    int data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

void InitNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

void SetValue(BiTree T) {
    T->data = 53;

    BiTNode *node1 = (BiTNode *) malloc(sizeof(BiTNode));
    node1->data = 17;

    BiTNode *node2 = (BiTNode *) malloc(sizeof(BiTNode));
    node2->data = 9;

    BiTNode *node3 = (BiTNode *) malloc(sizeof(BiTNode));
    node3->data = 45;

    BiTNode *node5 = (BiTNode *) malloc(sizeof(BiTNode));
    node5->data = 23;

    BiTNode *node6 = (BiTNode *) malloc(sizeof(BiTNode));
    node6->data = 78;

    BiTNode *node7 = (BiTNode *) malloc(sizeof(BiTNode));
    node7->data = 65;

    BiTNode *node8 = (BiTNode *) malloc(sizeof(BiTNode));
    node8->data = 94;

    BiTNode *node9 = (BiTNode *) malloc(sizeof(BiTNode));
    node9->data = 81;

    BiTNode *node10 = (BiTNode *) malloc(sizeof(BiTNode));
    node10->data = 88;

    InitNode(node1);
    InitNode(node2);
    InitNode(node3);
    InitNode(node5);
    InitNode(node6);
    InitNode(node7);
    InitNode(node8);
    InitNode(node9);
    InitNode(node10);

    T->left = node1;
    node1->left = node2;
    node1->right = node3;
    node3->left = node5;

    T->right = node6;
    node6->left = node7;
    node6->right = node8;
    node8->left = node9;
    node9->right = node10;
}

BiTNode *FindParent(BiTree T, BiTNode *node) {
    BiTNode *pointer = T;
    BiTNode *res;
    while (pointer != node) {
        if (pointer->data < node->data) {
            if (pointer->right == node) {
                res = pointer;
            }
            pointer = pointer->right;
        } else {
            if (pointer->left == node) {
                res = pointer;
            }
            pointer = pointer->left;
        }
    }
    return res;
}

// 删除结点左右均非空时，找到删除结点的下一中序结点补充
BiTNode *FindPostNode(BiTNode *node) {
    BiTNode *pointer = node->right;
    if (pointer->left == NULL) {
        return pointer;
    }
    while (pointer) {
        if (pointer->left == NULL) {
            return pointer;
        } else {
            pointer = pointer->left;
        }
    }
    return pointer;
}


void Delete(BiTree T, BiTNode *delNode) {
    if (delNode->left == NULL && delNode->right == NULL) {
        BiTNode *temp = FindParent(T, delNode);
        if (temp->left == delNode) temp->left = NULL;
        else temp->right = NULL;
        free(delNode);
    } else if (delNode->left == NULL && delNode->right != NULL) {
        BiTNode *temp = FindParent(T, delNode);
        if (temp->left == delNode) temp->left = delNode->right;
        if (temp->right == delNode) temp->right = delNode->right;
        free(delNode);
    } else if (delNode->left != NULL && delNode->right == NULL) {
        BiTNode *temp = FindParent(T, delNode);
        if (temp->left == delNode) temp->left = delNode->left;
        if (temp->right == delNode) temp->right = delNode->left;
        free(delNode);
    } else {
        BiTNode *temp = FindPostNode(delNode);
        delNode->data = temp->data;
        if (temp->right) {
            temp->data = temp->right->data;
            temp->right = NULL;
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
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitNode(T);
    SetValue(T);
    Delete(T, T->left);
    PrintVal(T);
}
