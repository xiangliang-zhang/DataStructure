#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 二叉树的先序遍历（递归 + 非递归）


typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTNode(BiTree T) {
    T->left = NULL;
    T->right = NULL;
}

void SetValue(BiTree T) {
    T->data = 1;

    BiTNode *t1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t1);
    t1->data = 2;

    BiTNode *t2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t2);
    t2->data = 3;

    BiTNode *t3 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t3);
    t3->data = 4;

    BiTNode *t4 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t4);
    t4->data = 5;

    BiTNode *t5 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t5);
    t5->data = 6;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;
}

// 递归先序
void PreOrder(BiTree T) {
    if (T != NULL) {
        printf("%d\n", T->data);
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

// 非递归先序
#define MaxSize 100

typedef struct Stack {
    BiTNode *data[MaxSize];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

void Push(Stack *s, BiTNode *v) {
    if (s->head < MaxSize - 1) {
        s->head++;
        s->data[s->head] = v;
    }
}

BiTNode *Pop(Stack *s) {
    if (s->head > -1) {
        BiTNode *t = s->data[s->head];
        s->head--;
        return t;
    }
    return NULL;
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

void PreOrderNonRecursion(BiTree T) {
    BiTNode *temp = T;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    while (temp != NULL) {
        while (temp != NULL) {
            printf("%d\n", temp->data);
            Push(s, temp);
            temp = temp->left;
        }
        temp = Pop(s);
        if (temp->right == NULL) {
            while (temp->right == NULL && !EmptyStack(s)) {
                temp = Pop(s);
            }
        }
        temp = temp->right;
    }
}

void PreOrderOfficial(BiTree T) {
    BiTNode *t = T;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    while (t || !EmptyStack(s)) {
        if (t) {
            printf("%d\n", t->data);
            Push(s, t);
            t = t->left;
        } else {
            t = Pop(s);
            t = t->right;
        }
    }
}

int main() {
    BiTree T = (BiTree) malloc(sizeof(BiTree));
    InitBiTNode(T);
    SetValue(T);
    PreOrder(T);
    printf("----------\n");
    PreOrderNonRecursion(T);
    printf("----------\n");
    PreOrderOfficial(T);
    return 0;
}