#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 将给定的二叉树转换成对应的表达式

typedef struct node {
    char data[10];
    struct node *left, *right;
} BTree;

void InitNode(BTree *T) {
    T->left = NULL;
    T->right = NULL;
}

void SetValue(BTree *T) {
    T->data[0] = '*';

    BTree *t1 = (BTree *) malloc(sizeof(BTree));
    InitNode(t1);
    t1->data[0] = '+';

    BTree *t2 = (BTree *) malloc(sizeof(BTree));
    InitNode(t2);
    t2->data[0] = '*';

    BTree *t3 = (BTree *) malloc(sizeof(BTree));
    InitNode(t3);
    t3->data[0] = 'a';

    BTree *t4 = (BTree *) malloc(sizeof(BTree));
    InitNode(t4);
    t4->data[0] = 'b';

    BTree *t5 = (BTree *) malloc(sizeof(BTree));
    InitNode(t5);
    t5->data[0] = 'c';

    BTree *t6 = (BTree *) malloc(sizeof(BTree));
    InitNode(t6);
    t6->data[0] = '-';

    BTree *t7 = (BTree *) malloc(sizeof(BTree));
    InitNode(t7);
    t7->data[0] = 'd';

    T->left = t1;
    T->right = t2;

    t1->left = t3;
    t1->right = t4;

    t2->left = t5;
    t2->right = t6;

    t6->right = t7;
}

void SetValue2(BTree *T) {
    T->data[0] = '+';

    BTree *t1 = (BTree *) malloc(sizeof(BTree));
    InitNode(t1);
    t1->data[0] = '*';

    BTree *t2 = (BTree *) malloc(sizeof(BTree));
    InitNode(t2);
    t2->data[0] = '-';

    BTree *t3 = (BTree *) malloc(sizeof(BTree));
    InitNode(t3);
    t3->data[0] = 'a';

    BTree *t4 = (BTree *) malloc(sizeof(BTree));
    InitNode(t4);
    t4->data[0] = 'b';

    BTree *t5 = (BTree *) malloc(sizeof(BTree));
    InitNode(t5);
    t5->data[0] = '-';

    BTree *t6 = (BTree *) malloc(sizeof(BTree));
    InitNode(t6);
    t6->data[0] = 'c';

    BTree *t7 = (BTree *) malloc(sizeof(BTree));
    InitNode(t7);
    t7->data[0] = 'd';

    T->left = t1;
    T->right = t2;

    t1->left = t3;
    t1->right = t4;

    t2->right = t5;
    t5->left = t6;

    t5->right = t7;
}

void PrintExpression(BTree *T) {
    if (T) {
        if (T->left != NULL || T->right != NULL) {
            printf("(");
        }
        PrintExpression(T->left);
        printf("%c", T->data[0]);
        PrintExpression(T->right);
        if (T->left != NULL && T->right != NULL) {
            printf(")");
        }
    }
}


int main() {
    BTree *T = (BTree *) malloc(sizeof(BTree));
    InitNode(T);
    SetValue(T);
    PrintExpression(T);
    printf("\n---------------\n");
    SetValue2(T);
    PrintExpression(T);
}