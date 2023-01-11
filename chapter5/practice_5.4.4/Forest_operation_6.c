#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 根据树的层次序列和结点的度构建树的孩子-兄弟链表

typedef struct Node {
    int data;
    struct Node *leftChild;
    struct Node *rightBrother;
} TNode_Child_Brother, *Tree_Child_Brother;

void InitNode(TNode_Child_Brother *node) {
    node->leftChild = NULL;
    node->rightBrother = NULL;
}

TNode_Child_Brother *CreateTree(TNode_Child_Brother *data[], const int degree[], int length) {
    int cur_index = 0;
    int iteration_index = 0;
    TNode_Child_Brother *root = data[0];
    TNode_Child_Brother *temp;
    while (iteration_index < length) {
        temp = data[iteration_index];
        int cur_degree = degree[iteration_index];
        int real_degree = 0;
        if (cur_degree > 0) {
            temp->leftChild = data[++cur_index];
            real_degree++;
            temp = temp->leftChild;
            while (real_degree < degree[iteration_index]) {
                temp->rightBrother = data[++cur_index];
                real_degree++;
                temp = temp->rightBrother;
            }
        }
        iteration_index++;
    }
    return root;
}

void PreOrder(Tree_Child_Brother T) {
    if (T) {
        printf("%d\n", T->data);
        PreOrder(T->leftChild);
        PreOrder(T->rightBrother);
    }
}

int main() {
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
    node8->data = 8;

    TNode_Child_Brother *data[] = {node1, node2, node3, node4, node5, node6, node7, node8};
    int degree[] = {3, 2, 1, 1, 0, 0, 0, 0};
    int length = sizeof(degree) / sizeof(degree[0]);
    Tree_Child_Brother Tree = CreateTree(data, degree, length);
    PreOrder(Tree);
}