#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 先序线索二叉树的构造


typedef struct ThreadNode {
    int data;
    struct ThreadNode *left;
    struct ThreadNode *right;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void InitThreadTNode(ThreadNode *T) {
    T->left = NULL;
    T->right = NULL;
    T->ltag = 0;
    T->rtag = 0;
}

void SetValue(ThreadTree T) {
    T->data = 0;

    ThreadNode *t1 = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadTNode(t1);
    t1->data = 1;

    ThreadNode *t2 = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadTNode(t2);
    t2->data = 2;

    ThreadNode *t3 = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadTNode(t3);
    t3->data = 3;

    ThreadNode *t4 = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadTNode(t4);
    t4->data = 4;

    ThreadNode *t5 = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadTNode(t5);
    t5->data = 5;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;
    t4->left = t5;
}

ThreadTree pre = NULL;

void PreThread(ThreadTree T) {
    if (T != NULL) {
        if (T->left == NULL) {
            T->left = pre;
            T->ltag = 1;
        }
        if (pre != NULL && pre->right == NULL) {
            pre->right = T;
            pre->rtag = 1;
        }
        pre = T;
        if (T->ltag != 1) PreThread(T->left);
        if (T->rtag != 1) PreThread(T->right);
    }
}

ThreadNode *GetFirstNode(ThreadTree T) {
    if (T) return T;
    else return NULL;
}

ThreadNode *GetLastNode(ThreadTree T) {
    ThreadNode *temp = T;
    while (true) {
        while (temp->right && temp->rtag == 0) {
            temp = temp->right;
        }
        if (temp->left && temp->ltag == 0) {
            temp = temp->left;
        }
        if (temp->ltag == 1 && temp->rtag == 1) {
            break;
        }
    }
    return temp;
}

ThreadNode *GetNextNode(ThreadTree T, ThreadNode *node) {
    ThreadNode *temp = node;
    if (temp->right && temp->rtag == 1) {
        temp = temp->right;
    } else if (temp->left && temp->ltag == 0) {
        temp = temp->left;
    } else if (temp->right && temp->rtag == 0) {
        temp = temp->right;
    } else {
        return NULL;
    }
    return temp;
}

ThreadNode *GetParent(ThreadTree T, ThreadNode *node) {
    if ((T->ltag == 0 && T->left == node) || (T->rtag == 0 && T->right == node)) {
        return T;
    } else {
        if (T->ltag == 0) GetParent(T->left, node);
        if (T->rtag == 0) GetParent(T->right, node);
    }
}

ThreadNode *GetPreNode(ThreadTree T, ThreadNode *node) {
    if (T == node) {
        return NULL;
    }
    ThreadNode *temp = node;
    if (temp->ltag == 1) {
        temp = temp->left;
    } else {
        ThreadNode *par = GetParent(T, node);
        if (par->right == node && par->ltag == 0) {
            par = par->left;
            while (true) {
                if (par->rtag == 0) {
                    par = par->right;
                } else if (par->ltag == 0) {
                    par = par->left;
                } else if (par->ltag == 1 || par->rtag == 1) {
                    temp = par;
                    break;
                }
            }
        } else if (par->left == node) {
            temp = par;
        }
    }
    return temp;
}

void PreOrderReverse(ThreadTree T) {
    ThreadNode *temp = T;
    ThreadNode *t = GetFirstNode(temp);
    while (t) {
        printf("%d\n", t->data);
        t = GetNextNode(T, t);
    }
}

int main() {
    ThreadTree T = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadTNode(T);
    SetValue(T);
    PreThread(T);
    pre->right = NULL;
    pre->rtag = 1;

    // 先序线索二叉树中先序序列下的第一个结点
    printf("\n-------------\n");
    ThreadNode *res1 = GetFirstNode(T);
    printf("%d\n", res1->data);

    // 先序线索二叉树中先序序列下结点p的下一个结点
    printf("\n-------------\n");
    ThreadNode *res2 = GetNextNode(T, T->left);
    printf("%d\n", res2->data);


    // 先序线索二叉树中先序序列下的最后一个结点
    printf("\n-------------\n");
    ThreadNode *res3 = GetLastNode(T);
    printf("%d\n", res3->data);

    // 先序线索二叉树中先序序列下结点p的前一个结点
    printf("\n-------------\n");
    ThreadNode *res4 = GetPreNode(T, T->right->left);
    printf("%d\n", res4->data);

    // 先序线索二叉树的先序遍历
    printf("\n-------------\n");
    PreOrderReverse(T);

    return 0;
}