#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 二叉树中度为0/1/2的结点个数

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBITNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

void SetValue(BiTree T) {
    T->data = 0;

    BiTNode *n1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBITNode(n1);
    n1->data = 1;

    BiTNode *n2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBITNode(n2);
    n2->data = 2;

    BiTNode *n3 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBITNode(n3);
    n3->data = 3;

    BiTNode *n4 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBITNode(n4);
    n4->data = 4;

    BiTNode *n5 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBITNode(n5);
    n5->data = 5;

    BiTNode *n6 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBITNode(n6);
    n6->data = 6;

    BiTNode *n7 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBITNode(n7);
    n7->data = 7;

    T->left = n1;
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    T->right = n5;
    n5->left = n6;
    n6->right = n7;
}


// 递归先序获得二叉树中度为0的结点数
void GetNumsDegree0(BiTree T, int *nums) {
    if (T) {
        if (T->left == NULL && T->right == NULL) (*nums)++;
        GetNumsDegree0(T->left, nums);
        GetNumsDegree0(T->right, nums);
    }
}

// 非递归获得二叉树中度为1的结点数

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

BiTNode *GetTop(Stack *s) {
    if (s->head > -1) {
        return s->data[s->head];
    }
}

bool EmptyStack(Stack *s) {
    if (s->head > -1) {
        return false;
    } else {
        return true;
    }
}

int GetNumsDegree1(BiTree T) {
    int num = 0;
    BiTNode *t = T;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    while (t || !EmptyStack(s)) {
        if (t) {
            Push(s, t);
            t = t->left;
        } else {
            t = Pop(s);
            if ((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL)) num++;
            t = t->right;
        }
    }
    return num;
}

// 非递归获得二叉树中度为2的结点数
int GetNumsDegree2(BiTree T) {
    int num = 0;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    BiTNode *t = T;
    BiTNode *r = NULL;
    while (t || !EmptyStack(s)) {
        if (t) {
            Push(s, t);
            t = t->left;
        } else {
            t = GetTop(s);
            if (t->right && t->right != r) t = t->right;
            else {
                t = Pop(s);
                if (t->left != NULL && t->right != NULL) num++;
                r = t;
                t = NULL;
            }
        }
    }
    return num;
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBITNode(T);
    SetValue(T);
    int nums1 = 0;
    GetNumsDegree0(T, &nums1);
    printf("度为0的结点个数:%d\n", nums1);
    printf("--------------\n");
    int res = GetNumsDegree1(T);
    printf("度为1的结点个数:%d\n", res);
    printf("-------------\n");
    int res2 = GetNumsDegree2(T);
    printf("度为2的结点个数:%d\n", res2);
}