#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 求二叉树的带权路径长度

typedef struct BiTNode {
    int weight;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

void SetValue(BiTree T) {
    T->weight = 1;

    BiTNode *t1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t1);
    t1->weight = 2;

    BiTNode *t2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t2);
    t2->weight = 2;

    BiTNode *t3 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t3);
    t3->weight = 3;

    BiTNode *t4 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t4);
    t4->weight = 3;

    BiTNode *t5 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t5);
    t5->weight = 3;

    BiTNode *t6 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t6);
    t6->weight = 3;

    T->left = t1;
    T->right = t2;

    t1->left = t3;
    t1->right = t4;

    t2->left = t5;
    t2->right = t6;
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
        BiTNode *temp = s->data[s->head];
        s->head--;
        return temp;
    }
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}


void GetWPLRecursion(BiTree root, int *sum) {
    if (root) {
        if (root->left) {
            root->left->weight += root->weight;
        }
        if (root->right) {
            root->right->weight += root->weight;
        }
        if (root->left == NULL && root->right == NULL) {
            (*sum) += root->weight;
        }
        GetWPLRecursion(root->left, sum);
        GetWPLRecursion(root->right, sum);
    }
}

int GetWPL(BiTree root) {
    int sum = 0;
    BiTNode *t = root;
    Stack *s = (Stack *) malloc(sizeof(Stack));
    InitStack(s);
    while (t || !EmptyStack(s)) {
        if (t) {
            if (t->left) t->left->weight += t->weight;
            if (t->right) t->right->weight += t->weight;
            if (t->left == NULL && t->right == NULL) {
                sum += t->weight;
            }
            Push(s, t);
            t = t->left;
        } else {
            t = Pop(s);
            t = t->right;
        }
    }
    return sum;
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);

    int res = GetWPL(T);
    printf("%d\n", res);

    int sum = 0;
    GetWPLRecursion(T, &sum);
    printf("%d\n", sum);

}