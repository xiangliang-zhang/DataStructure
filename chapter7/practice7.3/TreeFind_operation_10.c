#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 倒序二叉排序树中大于k的值

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
void GetMaxKValRecursion(BiTree tree, int k, int res[], int *i) {
    if (tree) {
        if (tree->data > k) res[(*i)++] = tree->data;
        GetMaxKValRecursion(tree->leftChild, k, res, i);
        GetMaxKValRecursion(tree->rightChild, k, res, i);
    }
}


// 非递归
int GetMaxKVal(BiTree T, int k) {
    BiTNode *pointer = T;
    int res[MaxNodes];
    int i = 0;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    while (pointer || !EmptyStack(s)) {
        if (pointer) {
            Push(s, pointer);
            if (pointer->data > k) res[i++] = pointer->data;
            pointer = pointer->leftChild;
        } else {
            pointer = Pop(s);
            pointer = pointer->rightChild;
        }
    }
    if (res[0] > k) {
        for (int index = 0; index < i; index++) {
            printf("%d\t", res[index]);
        }
    } else {
        for (int index = i; index >= 0; index--) {
            printf("%d\t", res[index]);
        }
    }
    return 0;
}

int main() {
    BiTree tree = (BiTNode *) malloc(sizeof(BiTNode));
    SetValue(tree);
    int res[MaxNodes];
    int i = 0;
    int k = 3;
    GetMaxKValRecursion(tree, k, res, &i);
    if (res[0] > k) {
        for (int index = 0; index < i; index++) {
            printf("%d\t", res[index]);
        }
    } else {
        for (int index = i; index >= 0; index--) {
            printf("%d\t", res[index]);
        }
    }
    printf("\n---------------------------\n");
    GetMaxKVal(tree, k);
}