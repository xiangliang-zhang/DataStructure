#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// BST的非递归查找

typedef struct BiTNode {
    int data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

void InitNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

void SetValue(BiTree T) {
    T->data = 4;

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

    node1->data = 2;
    node2->data = 1;
    node3->data = 3;
    node4->data = 5;
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
    node6->right = node7;
    node7->right = node8;
}

// 递归
BiTNode *FindNodeRecursion(BiTree T, int val) {
    if (val == T->data) {
        return T;
    } else if (val < T->data) {
        FindNodeRecursion(T->left, val);
    } else {
        FindNodeRecursion(T->right, val);
    }
}

// 非递归非遍历

BiTNode *FindNodeBST(BiTree T, int val) {
    BiTNode *pointer = T;
    while (pointer) {
        if (pointer->data == val) {
            return pointer;
        } else if (pointer->data > val) {
            pointer = pointer->left;
        } else {
            pointer = pointer->right;
        }
    }
}


// 非递归遍历
#define MaxNodes 100
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

BiTNode *GetTop(Stack *s) {
    if (!EmptyStack(s)) {
        return s->data[s->head];
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

// 后序非递归
BiTNode *FindNode(BiTree T, int val) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    BiTNode *pointer = T;
    BiTNode *r;
    while (pointer || !EmptyStack(s)) {
        if (pointer) {
            Push(s, pointer);
            pointer = pointer->left;
        } else {
            pointer = GetTop(s);
            if (pointer->right && pointer->right != r) {
                pointer = pointer->right;
            } else {
                pointer = Pop(s);
                if (pointer->data == val) {
                    return pointer;
                }
                r = pointer;
                pointer = NULL;
            }
        }
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitNode(T);
    SetValue(T);
//    FindNodeRecursion(T, 7);
    BiTNode *res1 = FindNodeBST(T, 3);
    printf("%d\n", res1->data);
//    BiTNode *res2 = FindNode(T, 7);
//    printf("%d\n", res2->data);
}