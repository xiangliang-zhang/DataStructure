#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 中序线索二叉树的构造

typedef struct ThreadNode {
    int data;
    struct ThreadNode *left;
    struct ThreadNode *right;
    int ltag, rtag;
} ThreadNode, *ThreadTree;


void InitThreadNode(ThreadNode *t) {
    t->left = NULL;
    t->right = NULL;
    t->ltag = 0;
    t->rtag = 0;
}

void SetValue(ThreadTree T) {
    T->data = 0;

    ThreadNode *t1 = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadNode(t1);
    t1->data = 1;

    ThreadNode *t2 = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadNode(t2);
    t2->data = 2;

    ThreadNode *t3 = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadNode(t3);
    t3->data = 3;

    ThreadNode *t4 = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadNode(t4);
    t4->data = 4;

    ThreadNode *t5 = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadNode(t5);
    t5->data = 5;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;
    t4->right = t5;
}

ThreadNode *pre = NULL;

void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->left);
        if (T->left == NULL) {
            T->left = pre;
            T->ltag = 1;
        }
        if (pre != NULL && pre->right == NULL) {
            pre->right = T;
            pre->rtag = 1;
        }
        pre = T;
        InThread(T->right);
    }
}

ThreadNode *GetFirstNode(ThreadTree T) {
    while (T->left != NULL || T->ltag != 1) {
        T = T->left;
    }
    return T;
}


ThreadNode *GetNextNode(ThreadTree T, ThreadNode *node) {
    ThreadNode *temp = node;
    if (temp->rtag == 1) {
        temp = temp->right;
        return temp;
    } else {
        temp = temp->right;
        while (temp->left && temp->ltag != 1) {
            temp = temp->left;
        }
        return temp;
    }
}

ThreadNode *GetLastNode(ThreadTree T) {
    ThreadNode *temp = T;
    while (temp->right && temp->rtag == 0) {
        temp = temp->right;
    }
    return temp;
}

ThreadNode *GetPreNode(ThreadTree T, ThreadNode *node) {
    ThreadNode *temp = node;
    if (temp->ltag == 1) {
        temp = temp->left;
    } else {
        temp = temp->left;
        while (temp->rtag == 0) {
            temp = temp->right;
        }
    }
    return temp;
}

void InOrderTraverse(ThreadTree T) {
    ThreadNode *temp = T;
    ThreadNode *t = GetFirstNode(temp);
    while (t != NULL) {
        printf("%d\n", t->data);
        t = GetNextNode(T, t);
    }
}

int main() {
    ThreadTree T = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadNode(T);
    SetValue(T);
    InThread(T);
    pre->rtag = 1;
    pre->right = NULL;

    // 求中序线索二叉树中中序序列下的第一个结点
    ThreadNode *res1 = GetFirstNode(T);
    printf("%d\n", res1->data);

    // 结点p在中序序列下的后继
    printf("\n-------------\n");
    ThreadNode *res2 = GetNextNode(T, T->left);
    printf("%d\n", res2->data);

    // 求中序线索二叉树中序序列下的最后一个结点
    printf("\n-------------\n");
    ThreadNode *res3 = GetLastNode(T);
    printf("%d\n", res3->data);

    // 求中序线索二叉树中序序列下结点p的前驱
    printf("\n-------------\n");
    ThreadNode *res4 = GetPreNode(T, T->left);
    printf("%d\n", res4->data);


    // 中序线索二叉树的中序遍历
    printf("\n-------------\n");
    InOrderTraverse(T);
    return 0;
}

