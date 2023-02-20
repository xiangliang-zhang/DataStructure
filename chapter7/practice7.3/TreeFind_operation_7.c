#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 求指定结点在二叉排序树中的层次

#define MaxNodes 100

typedef struct BiTree {
    int data;
    struct BiTree *leftChild;
    struct BiTree *rightChild;
} BiTNode, *BiTree;

void SetValue(BiTree tree) {
    tree->data = 3;

    BiTNode *node1 = (BiTNode *) malloc(sizeof(BiTNode));
    node1->data = 2;
    node1->leftChild = NULL;
    node1->rightChild = NULL;

    BiTNode *node2 = (BiTNode *) malloc(sizeof(BiTNode));
    node2->data = 1;
    node2->leftChild = NULL;
    node2->rightChild = NULL;

    BiTNode *node3 = (BiTNode *) malloc(sizeof(BiTNode));
    node3->data = 5;
    node3->leftChild = NULL;
    node3->rightChild = NULL;

    BiTNode *node4 = (BiTNode *) malloc(sizeof(BiTNode));
    node4->data = 4;
    node4->leftChild = NULL;
    node4->rightChild = NULL;

    BiTNode *node5 = (BiTNode *) malloc(sizeof(BiTNode));
    node5->data = 6;
    node5->leftChild = NULL;
    node5->rightChild = NULL;

    BiTNode *node6 = (BiTNode *) malloc(sizeof(BiTNode));
    node6->data = 7;
    node6->leftChild = NULL;
    node6->rightChild = NULL;

    tree->leftChild = node1;
    node1->leftChild = node2;
    tree->rightChild = node3;
    node3->leftChild = node4;
    node3->rightChild = node5;
    node5->rightChild = node6;
}

typedef struct Stack {
    BiTNode *data[MaxNodes];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

void Push(Stack *s, BiTNode *node) {
    s->head++;
    s->data[s->head] = node;
}

BiTNode *Pop(Stack *s) {
    if (!EmptyStack(s)) {
        BiTNode *res = s->data[s->head];
        s->head--;
        return res;
    }
}

BiTNode *GetTop(Stack *s) {
    if (!EmptyStack(s)) {
        return s->data[s->head];
    }
}


// 递归
void GetHeightRecursion(BiTree tree, BiTNode *target, int now_height, int *targetHeight) {
    if (tree) {
        if (target == tree) {
            *targetHeight = now_height;
        }
        now_height++;
        GetHeightRecursion(tree->leftChild, target, now_height, targetHeight);
        GetHeightRecursion(tree->rightChild, target, now_height, targetHeight);
    }
}


// 非递归
int GetHeight(BiTree T, BiTNode *node) {
    BiTNode *pointer = T;
    int n = 1;
    while (pointer != node) {
        if (pointer->data > node->data) {
            pointer = pointer->leftChild;
        }
        if (pointer->data < node->data) {
            pointer = pointer->rightChild;
        }
        if (pointer == T) {
            return -1;
        }
        n++;
    }
    return n;
}

int main() {
    BiTree tree = (BiTNode *) malloc(sizeof(BiTNode));
    SetValue(tree);
    int now_height = 1;
    int targetHeight = 0;
    GetHeightRecursion(tree, tree->rightChild->rightChild, now_height, &targetHeight);
    printf("%d\n", targetHeight);
    int n = GetHeight(tree, tree->rightChild->rightChild);
    printf("%d", n);
}