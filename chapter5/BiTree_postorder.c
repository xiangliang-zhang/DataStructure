0#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 二叉树的后序遍历 递归 + 非递归

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTree(BiTree T) {
    T->left = NULL;
    T->right = NULL;
}

void SetValue(BiTree T) {
    T->data = 0;

    BiTNode *t1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(t1);
    t1->data = 1;

    BiTNode *t2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(t2);
    t2->data = 2;

    BiTNode *t3 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(t3);
    t3->data = 3;

    BiTNode *t4 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(t4);
    t4->data = 4;

    BiTNode *t5 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(t5);
    t5->data = 5;

    BiTNode *t6 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(t6);
    t6->data = 6;

    T->left = t1;
    t1->left = t2;
    t2->left = t3;
    t3->right = t4;
    t4->left = t5;
    t4->right = t6;
}

// 递归后续遍历
void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->left);
        PostOrder(T->right);
        printf("%d\n", T->data);
    }
}

// 后序遍历非递归
#define MaxSize 100

typedef struct Stack {
    BiTNode *data[MaxSize];
    int head;
} Stack;

void InitStack(Stack *s) {
    s->head = -1;
}

void Push(Stack *s, BiTNode *node) {
    s->head++;
    s->data[s->head] = node;
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

BiTNode *Pop(Stack *s) {
    BiTNode *temp = s->data[s->head];
    s->head--;
    return temp;
}

BiTNode *GetTop(Stack *s) {
    if (EmptyStack(s)) {
        return NULL;
    }
    return s->data[s->head];
}

void PostOrderNoRecursion(BiTree T) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    BiTNode *temp = T;
    BiTNode *r = NULL; // 记录刚刚访问的元素，也就是刚出栈访问的元素
    while (temp != NULL || !EmptyStack(s)) {
        if (temp) {
            Push(s, temp);
            temp = temp->left;
        } else {
            temp = GetTop(s);
            if (temp->right && temp->right != r) {
                temp = temp->right;
            } else {
                temp = Pop(s);
                printf("%d\n", temp->data);
                r = temp;
                temp = NULL;  // 控制不会再次访问出栈结点的左孩子
            }
        }
    }
}

int main() {
    BiTree T = (BiTree) malloc(sizeof(BiTree));
    InitBiTree(T);
    SetValue(T);
    PostOrder(T);
    printf("\n---------------------\n");
    PostOrderNoRecursion(T);
    return 0;
}
