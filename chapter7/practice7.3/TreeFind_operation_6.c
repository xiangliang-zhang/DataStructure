#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 判断二叉树是否是二叉排序树

#define MaxNodes 100

typedef struct BiTree {
    int data;
    struct BiTree *leftChild;
    struct BiTree *rightChild;
} BiTNode, *BiTree;

void SetValue(BiTree tree) {
    tree->data = 34;

    BiTNode *node1 = (BiTNode *) malloc(sizeof(BiTNode));
    node1->data = 23;
    node1->leftChild = NULL;
    node1->rightChild = NULL;

    BiTNode *node2 = (BiTNode *) malloc(sizeof(BiTNode));
    node2->data = 15;
    node2->leftChild = NULL;
    node2->rightChild = NULL;

    BiTNode *node3 = (BiTNode *) malloc(sizeof(BiTNode));
    node3->data = 28;
    node3->leftChild = NULL;
    node3->rightChild = NULL;

    BiTNode *node4 = (BiTNode *) malloc(sizeof(BiTNode));
    node4->data = 107;
    node4->leftChild = NULL;
    node4->rightChild = NULL;

    BiTNode *node5 = (BiTNode *) malloc(sizeof(BiTNode));
    node5->data = 98;
    node5->leftChild = NULL;
    node5->rightChild = NULL;

    BiTNode *node6 = (BiTNode *) malloc(sizeof(BiTNode));
    node6->data = 115;
    node6->leftChild = NULL;
    node6->rightChild = NULL;

    tree->leftChild = node1;
    node1->leftChild = node2;
    node1->rightChild = node3;
    tree->rightChild = node4;
    node4->leftChild = node5;
    node4->rightChild = node6;
}

typedef struct Queue {
    BiTNode *data[MaxNodes];
    int head, tail;
} Stack;

void InitQueue(Stack *queue) {
    queue->head = 0;
    queue->tail = -1;
}

bool EmptyQueue(Stack *queue) {
    if (queue->head > queue->tail) {
        return true;
    } else {
        return false;
    }
}

void EnQueue(Stack *queue, BiTNode *node) {
    queue->tail++;
    queue->data[queue->tail] = node;
}

BiTNode *DeQueue(Stack *queue) {
    if (!EmptyQueue(queue)) {
        BiTNode *res = queue->data[queue->head];
        queue->head++;
        return res;
    }
}

bool IsBST(BiTree tree) {
    Stack *queue = (Stack *) malloc(sizeof(Stack));
    InitQueue(queue);
    BiTNode *point;
    EnQueue(queue, tree);
    while (!EmptyQueue(queue)) {
        int flag = 0;
        point = DeQueue(queue);
        if (point->leftChild) {
            if (point->leftChild->data < point->data) {
                EnQueue(queue, point->leftChild);
                flag = 0;
            } else {
                flag = 1;
            }
        }
        if (point->rightChild) {
            if (point->rightChild->data > point->data) {
                EnQueue(queue, point->rightChild);
                flag = 0;
            } else {
                flag = 1;
            }
        }
        if (flag == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    BiTree tree = (BiTNode *) malloc(sizeof(BiTNode));
    SetValue(tree);
    int res = IsBST(tree);
    printf("%d", res);
}