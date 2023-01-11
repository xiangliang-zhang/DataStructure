#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 根据孩子兄弟链表递归求对应树的深度

typedef struct Node {
    int data;
    struct Node *leftChild;
    struct Node *rightBrother;
} TNode_Child_Brother, *Tree_Child_Brother;

void InitNode(TNode_Child_Brother *node) {
    node->leftChild = NULL;
    node->rightBrother = NULL;
}

void SetValue(Tree_Child_Brother T) {
    T->data = 0;

    TNode_Child_Brother *node1 = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(node1);
    node1->data = 1;

    TNode_Child_Brother *node2 = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(node2);
    node2->data = 2;

    TNode_Child_Brother *node3 = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(node3);
    node3->data = 3;

    TNode_Child_Brother *node4 = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(node4);
    node4->data = 4;

    TNode_Child_Brother *node5 = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(node5);
    node5->data = 5;

    TNode_Child_Brother *node6 = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(node6);
    node6->data = 6;

    TNode_Child_Brother *node7 = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(node7);
    node7->data = 7;

    TNode_Child_Brother *node8 = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(node8);
    node1->data = 8;

    TNode_Child_Brother *node9 = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(node9);
    node9->data = 9;

    T->leftChild = node1;
    node1->rightBrother = node2;

    T->rightBrother = node3;
    node3->leftChild = node4;
    node4->leftChild = node5;

    node3->rightBrother = node6;
    node6->leftChild = node7;
    node7->leftChild = node8;
    node8->rightBrother = node9;
}

void GetHeight(Tree_Child_Brother T, int cur_height, int *max_height) {
    if (T) {
        (cur_height)++;
        GetHeight(T->leftChild, cur_height, max_height);
        GetHeight(T->rightBrother, cur_height, max_height);
    }
    if (cur_height > *max_height) *max_height = cur_height;
}

int main() {
    Tree_Child_Brother T = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(T);
    SetValue(T);
    int cur_height = 0;
    int max_height = 0;
    GetHeight(T, cur_height, &max_height);
    printf("%d\n", max_height);
}