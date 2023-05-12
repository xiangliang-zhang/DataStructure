#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct ThreadNode {
    int data;
    struct ThreadNode *left;
    struct ThreadNode *right;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void InitThreadNode(ThreadNode *T) {
    T->left = NULL;
    T->right = NULL;
    T->ltag = 0;
    T->rtag = 0;
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
    t4->left = t5;
}

ThreadNode *pre = NULL;

void PostThread(ThreadTree T) {
    if (T != NULL) {
        PostThread(T->left);
        PostThread(T->right);

        if (T->left == NULL) {
            T->left = pre;
            T->ltag = 1;
        }

        if (pre != NULL && pre->right == NULL) {
            pre->right = T;
            pre->rtag = 1;
        }
        pre = T;
    }
}

ThreadNode *GetFirstNode(ThreadTree T) {
    ThreadNode *temp = T;
    if (T->right == NULL) {
        return T;
    }
    while (true) {
        while (temp->left) {
            temp = temp->left;
        }
        if (temp->right && temp->rtag == 0) {
            temp = temp->right;
        }
        if (temp->ltag == 1 && temp->rtag == 1) {
            break;
        }
    }
    return temp;
}

ThreadNode *GetNextNode(ThreadTree T, ThreadNode *node) {
    ThreadNode *temp = node;
    if (node == T) {
        temp = NULL;
    } else if (node->rtag == 1) {
        temp = node->right;
    } else {
        ThreadNode *t = T;
        while (true) {
            if ((t->left == node && t->ltag == 0 && t->right == NULL) ||
                (t->right == node && t->rtag == 0)) {  // 双亲的左孩子，且双亲无右孩子 或者 双亲的右孩子即为node
                temp = t;
                break;
            } else if (t->left == node && t->ltag == 0 && t->right != NULL && t->rtag == 0) { // 双亲的左孩子，且双亲有右子树
                t = t->right;
                while (true) {
                    if (t->left && t->ltag == 0) {
                        t = t->left;
                    }
                    if (t->right && t->rtag == 0) {
                        t = t->right;
                    }
                    if (t->ltag == 1 && t->rtag == 1) {
                        temp = t;
                        return temp;
                    }
                }
            }
        }
    }
    return temp;
}

ThreadNode *GetLastNode(ThreadTree T) {
    return T;
}

ThreadNode *GetPreNode(ThreadTree T, ThreadNode *node) {
    ThreadNode *t = node;
    if (t->ltag == 1) {
        return t->left;
    } else {
        if (t->ltag == 0 && t->rtag == 0) {
            return t->right;
        } else if (t->left != NULL && t->ltag == 0) { // 有左子树
            return t->left;
        } else if (t->left == NULL && t->ltag == 1 && t->right != NULL && t->rtag == 0) { //无左子树，有右子树
            if (node->right) return node->right;
            else return NULL;
        }
    }
}

void PostorderReverse(ThreadTree T) {
    ThreadNode *temp = T;
    ThreadNode *t = GetFirstNode(temp);
    while (t) {
        printf("%d\n", t->data);
        t = GetNextNode(T, t);
    }
}

int main() {
    ThreadTree T = (ThreadNode *) malloc(sizeof(ThreadNode));
    InitThreadNode(T);
    SetValue(T);
    PostThread(T);

    // 后序线索二叉树中后序序列下的第一个节点
    ThreadNode *res1 = GetFirstNode(T);
    printf("%d\n", res1->data);

    // 后序线索二叉树中结点p在后序序列下的后继
    printf("\n---------------\n");
    ThreadNode *res2 = GetNextNode(T, T->left->right);
    printf("%d\n", res2->data);

    // 求后序线索二叉树后序序列下的最后一个结点
    printf("\n---------------\n");
    ThreadNode *res3 = GetLastNode(T);
    printf("%d\n", res3->data);

    // 求后序线索二叉树后序序列下结点的前驱
    printf("\n---------------\n");
    ThreadNode *res4 = GetPreNode(T, T->left);
    printf("%d\n", res4->data);

    // 后序线索二叉树的遍历
    printf("\n---------------\n");
    PostorderReverse(T);

    return 0;
}

