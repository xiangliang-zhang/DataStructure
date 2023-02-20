#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// BST结点的插入

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
    node4->data = 6;
    node5->data = 5;
    node6->data = 7;
    node7->data = 8;
//    node8->data = 8;


    T->left = node1;
    node1->left = node2;
    node1->right = node3;
    T->right = node4;
    node4->left = node5;
    node4->right = node6;
    node6->right = node7;
//    node7->right = node8;
}

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

// 中序非递归
void InsertEle(BiTree T, int val) {
    BiTNode *pointer = T;
    BiTNode *target;
    while (pointer) {
        if (val < pointer->data) {
            pointer = pointer->left;
        }
        if (pointer == NULL) {
            break;
        }
        if (val > pointer->data) {
            pointer = pointer->right;
        }
        if (pointer == NULL) {
            break;
        }
        if (pointer->left == NULL && pointer->right == NULL) {
            target = pointer;
        }
    }

    BiTNode *node = (BiTNode *) malloc(sizeof(BiTNode));
    InitNode(node);
    node->data = val;

    if (target->data < val) {
        target->right = node;
    } else {
        target->left = node;
    }
}

void PrintVal(BiTree T) {
    if (T) {
        PrintVal(T->left);
        printf("%d\t", T->data);
        PrintVal(T->right);
    }

}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitNode(T);
    SetValue(T);
    InsertEle(T, 9);
    PrintVal(T);
}