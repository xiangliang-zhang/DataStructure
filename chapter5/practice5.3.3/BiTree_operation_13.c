#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 找结点p和结点q的最近公共祖先结点r, 后序遍历

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTree;

void InitBiTNode(BiTNode *node) {
    node->left = NULL;
    node->right = NULL;
}

void SetValue(BiTree T) {
    T->data = 0;

    BiTNode *t1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t1);
    t1->data = 1;

    BiTNode *t2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t2);
    t2->data = 2;

    BiTNode *t3 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t3);
    t3->data = 3;

    BiTNode *t4 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t4);
    t4->data = 4;

    BiTNode *t5 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t5);
    t5->data = 5;

    T->left = t1;
    t1->left = t2;
    t1->right = t3;
    T->right = t4;
    t4->left = t5;
}


#define  MaxSize 100

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
    return s->data[s->head];
}

bool Empty(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}


// 获取父子结点之间的路径
void GetPath(BiTNode *Root, BiTNode *target, Stack *s) {
    BiTNode *t = Root;
    BiTNode *r = NULL;
    while (t != target) {
        if (t) {
            Push(s, t);
            t = t->left;
        } else {
            t = GetTop(s);
            if (t->right && t->right != r) t = t->right;
            else {
                t = Pop(s);
                r = t;
                t = NULL;
            }
        }
    }
}

BiTNode *ANCESTOR(BiTree ROOT, BiTNode *p, BiTNode *q, BiTNode *r) {
    if (p == q) {
        return p;
    }
    Stack *s1 = (Stack *) malloc(sizeof(Stack));
    InitStack(s1);

    Stack *s2 = (Stack *) malloc(sizeof(Stack));
    InitStack(s2);

    // 二叉树后序遍历
    GetPath(ROOT, p, s1);
    GetPath(ROOT, q, s2);

    if (s1->head > s2->head) {
        int change = s1->head - s2->head;
        for (int i = 0; i < change; i++) {
            Pop(s1);
        }
    } else if (s1->head < s2->head) {
        int change = s2->head - s1->head;
        for (int i = 0; i < change; i++) {
            Pop(s2);
        }
    }
    BiTNode *t1 = GetTop(s1);
    BiTNode *t2 = GetTop(s2);
    while (t1 != t2) {
        t1 = Pop(s1);
        t2 = Pop(s2);
    }
    return t1;
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTree));
    InitBiTNode(T);
    SetValue(T);
    BiTNode *res = ANCESTOR(T, T->left->right, T->left->left, NULL);
    if (res != NULL) {
        printf("%d\n", res->data);
    }
}



