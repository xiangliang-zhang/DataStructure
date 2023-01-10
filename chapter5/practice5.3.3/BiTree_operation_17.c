#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"

// 判断二叉树是否相似

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

void SetValue(BiTree T, BiTree T2) {
    T->data = 0;

    BiTNode *t1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t1);
    t1->data = 1;

    BiTNode *t2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t2);
    t2->data = 2;

    BiTNode *t3 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t3);
    t3->data = 3;

    BiTNode *t4 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t4);
    t4->data = 4;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;

    T2->data = 9;
    BiTNode *temp1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(temp1);
    temp1->data = 8;

    BiTNode *temp2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(temp2);
    temp2->data = 7;

    BiTNode *temp3 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(temp3);
    temp3->data = 6;

    BiTNode *temp4 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(temp4);
    temp4->data = 5;

    BiTNode *temp5 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(temp5);
    temp5->data = 4;

    T2->left = temp1;
    temp1->left = temp2;
    temp1->right = temp3;
    T2->right = temp4;
    temp2->left = temp5;
}

#define MaxSize 100

typedef struct Stack {
    BiTNode *data[MaxSize];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

void Push(Stack *s, BiTNode *node) {
    if (s->head < MaxSize - 1) {
        s->head++;
        s->data[s->head] = node;
    }
}

BiTNode *Pop(Stack *s) {
    if (s->head > -1) {
        BiTNode *res = s->data[s->head];
        s->head--;
        return res;
    }
}

bool Empty(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

bool IsSymmetrical(BiTree T1, BiTree T2) {
    if (((T1->left == NULL && T1->right != NULL) && (T2->left == NULL && T2->right != NULL))
        || ((T1->left != NULL && T1->right == NULL) && (T2->left != NULL && T2->right == NULL))
        || (T1 == NULL && T2 == NULL)) {
        return true;
    }
    Stack *s1 = (Stack *) malloc(sizeof(Stack));
    InitStack(s1);

    Stack *s2 = (Stack *) malloc(sizeof(Stack));
    InitStack(s2);

    BiTNode *t1 = T1;
    BiTNode *t2 = T2;
    while (t1 || !Empty(s1) || t2 || !Empty(s2)) {
        if (t1 && t2) {
            Push(s1, t1);
            Push(s2, t2);
            t1 = t1->left;
            t2 = t2->left;
        } else if ((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL)) {
            return false;
        } else {
            t1 = Pop(s1);
            t2 = Pop(s2);
            t1 = t1->right;
            t2 = t2->right;
        }
    }
    return true;
}

int main() {
    BiTree T1 = (BiTNode *) malloc(sizeof(BiTNode));
    BiTree T2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T1);
    InitBiTNode(T2);
    SetValue(T1, T2);
    int res = IsSymmetrical(T1, T2);
    printf("%d\n", res);
}