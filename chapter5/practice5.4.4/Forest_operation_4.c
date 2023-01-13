#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 以孩子兄弟表示法存储的森林的叶子结点数

typedef struct Node {
    int data;
    struct Node *leftChild;
    struct Node *rightBrother;
} TNode_Child_Brother, *Tree_Child_Brother;

void InitNode(TNode_Child_Brother *T) {
    T->leftChild = NULL;
    T->rightBrother = NULL;
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

#define MaxSize 100

typedef struct Stack {
    TNode_Child_Brother *data[MaxSize];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

void Push(Stack *s, TNode_Child_Brother *node) {
    if (s->head < MaxSize - 1) {
        s->head++;
        s->data[s->head] = node;
    }
}

TNode_Child_Brother *Pop(Stack *s) {
    if (s->head > -1) {
        TNode_Child_Brother *t = s->data[s->head];
        s->head--;
        return t;
    }
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

int GetNodes(Tree_Child_Brother T) {
    int num = 0;
    TNode_Child_Brother *t = T;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    while (t || !EmptyStack(s)) {
        if (t) {
            if (t->leftChild == NULL) {
                num++;
            }
            Push(s, t);
            t = t->leftChild;
        } else {
            t = Pop(s);
            t = t->rightBrother;
        }
    }
    return num;
}

int main() {
    Tree_Child_Brother T = (TNode_Child_Brother *) malloc(sizeof(TNode_Child_Brother));
    InitNode(T);
    SetValue(T);
    int res = GetNodes(T);
    printf("%d\n", res);
}
