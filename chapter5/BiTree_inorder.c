#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 二叉树的中序遍历 递归+非递归

#define MaxSize 100


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

    BiTNode *temp1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(temp1);
    temp1->data = 1;

    BiTNode *temp2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(temp2);
    temp2->data = 2;

    BiTNode *temp3 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(temp3);
    temp3->data = 3;

    BiTNode *temp4 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(temp4);
    temp4->data = 4;

    BiTNode *temp5 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTree(temp5);
    temp5->data = 5;

    T->left = temp1;
    temp1->left = temp2;
    temp2->left = temp3;

    temp3->right = temp4;
    temp4->right = temp5;
}

// 递归中序
void InOrder(BiTree T) {
    if (T) {
        InOrder(T->left);
        printf("%d\n", T->data);
        InOrder(T->right);
    }
}

// 非递归中序
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

BiTNode *Pop(Stack *s) {
    BiTNode *temp = s->data[s->head];
    s->head--;
    return temp;
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

void InOrderNoRecursion(BiTree T) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    BiTNode *temp = T;
    while (temp != NULL || !EmptyStack(s)) {
        if (temp) {
            Push(s, temp);
            temp = temp->left;
        } else {
            temp = Pop(s);
            printf("%d\n", temp->data);
            temp = temp->right;
        }
    }
}

int main() {
    BiTree T = (BiTree) malloc(sizeof(BiTree));
    InitBiTree(T);
    SetValue(T);
    InOrder(T);
    printf("\n-----------\n");
    InOrderNoRecursion(T);
}