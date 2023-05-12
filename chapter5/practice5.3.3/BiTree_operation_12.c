#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 打印值为x的结点的祖先值

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

void SetValue(BiTree T) {
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

    BiTNode *t5 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t5);
    t5->data = 5;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;
    t4->right = t5;
}

#define MaxSize 100

typedef struct Stack {
    BiTNode *data[MaxSize];
    int tag[MaxSize];
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

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

BiTNode *GetTopStack(Stack *s) {
    return s->data[s->head];
}

int GetParent(BiTree T, int num) {
    BiTNode *t = T;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);

    while (t != NULL || !EmptyStack(s)) {
        while (t != NULL && t->data != num) {
            Push(s, t);
            s->tag[s->head] = 0;
            t = t->left;
        }
        if (t != NULL && t->data == num) {
            while (!EmptyStack(s)) {
                printf("%d\t", Pop(s)->data);
            }
            return 0;
        }
        while (!EmptyStack(s) && s->tag[s->head] == 1) {
            Pop(s);
        }
        if (!EmptyStack(s)) {
            s->tag[s->head] = 1;
            t = s->data[s->head]->right;
        }
    }
}

void GetPath(BiTree T, int x) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    BiTNode *t = T;
    BiTNode *pre = NULL;
    while (t || !EmptyStack(s)) {
        if (t != NULL && t->data == x) break;
        if (t != NULL) {
            Push(s, t);
            t = t->left;
        } else {
            t = GetTopStack(s);
            if (t->right && t->right != pre) {
                t = t->right;
            } else {
                t = Pop(s);
                pre = t;
                t = NULL;
            }
        }
    }
    while (!EmptyStack(s)) {
        printf("%d\t", Pop(s)->data);
    }
}

int main() {
    BiTree T = (BiTree) malloc(sizeof(BiTree));
    InitBiTNode(T);
    SetValue(T);
    GetParent(T, 5);
    printf("\n--------\n");
    GetPath(T, 5);
}
