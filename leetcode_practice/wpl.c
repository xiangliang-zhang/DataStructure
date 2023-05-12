#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

// 求二叉树的wpl

#define MaxNodes 100


typedef struct BiTNode {
    int data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

void InitNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
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
    if (s->head < MaxNodes - 1) {
        s->head++;
        s->data[s->head] = node;
    }
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

void SetValue(BiTree T) {
    T->data = 0;

    BiTNode *node1 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node2 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node3 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node4 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node5 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node6 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node7 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTNode *node8 = (BiTNode *) malloc(sizeof(BiTNode));

    InitNode(node1);
    InitNode(node2);
    InitNode(node3);
    InitNode(node4);
    InitNode(node5);
    InitNode(node6);
    InitNode(node7);
    InitNode(node8);

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;
    node6->data = 6;
    node7->data = 7;
    node8->data = 8;


    T->left = node1;
    node1->left = node2;
    node1->right = node3;
    T->right = node4;
    node4->left = node5;
    node4->right = node6;
//    node6->right = node7;
//    node5->left = node8;
}

int getWPL(BiTree T) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    BiTNode *temp = T;
    BiTNode *pre = NULL;
    int res = 0;
    while (!EmptyStack(s) || temp != NULL) {
        if (temp) {
            Push(s, temp);
            temp = temp->left;
        } else {
            temp = GetTop(s);
            if (temp->right != NULL && temp->right != pre) {
                temp = temp->right;
            } else {
                temp = Pop(s);
                if (temp->left == NULL && temp->right == NULL)
                    res = res + (s->head + 1) * temp->data;
                pre = temp;
                temp = NULL;
            }
        }
    }
    return res;
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitNode(T);
    SetValue(T);
    int res = getWPL(T);
    printf("%d\n", res);
}