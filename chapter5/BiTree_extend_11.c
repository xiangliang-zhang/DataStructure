#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 求二叉树路径长度和为x的路径

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
    T->data = 10;

    BiTNode *t1 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t1);
    t1->data = 5;

    BiTNode *t2 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t2);
    t2->data = 12;

    BiTNode *t3 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t3);
    t3->data = 4;

    BiTNode *t4 = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(t4);
    t4->data = 7;

    T->left = t1;
    T->right = t2;
    t1->left = t3;
    t1->right = t4;
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
    if (s->head < MaxSize - 1) {
        BiTNode *res = s->data[s->head];
        s->head--;
        return res;
    }
}

bool EmptyStack(Stack *s) {
    if (s->head == -1) {
        return true;
    } else {
        return false;
    }
}

BiTNode *GetTop(Stack *s) {
    if (s->head > -1) {
        return s->data[s->head];
    }
}


void PrintRoute(BiTree T, int num) {
    int route[MaxSize]; // 存储路径
    int index = 0;  // 遍历路径
    int sum = 0;  // 记录到当前结点为止的和
    Stack *s = (Stack *) malloc(sizeof(Stack));  // 遍历二叉树
    InitStack(s);
    BiTNode *t = T;
    BiTNode *r = NULL;
    while (t || !EmptyStack(s)) {
        if (t) {
            Push(s, t);
            route[index] = t->data;
            index++;
            sum += t->data;
            if (sum == num) {
                for (int i = 0; i < index; i++) {
                    printf("%d\t", route[i]);
                }
                printf("\n");
            }
            t = t->left;
        } else {
            t = GetTop(s); // 某子树的左子树访问完后，不能直接出栈祖先结点，需要判断祖先的右结点
            if (t->right != NULL && t->right != r) {
                t = t->right;
            } else {
                sum -= t->data;
                index--;
                r = Pop(s);
                t = NULL;
            }
        }
    }
}

int main() {
    BiTree T = (BiTNode *) malloc(sizeof(BiTNode));
    InitBiTNode(T);
    SetValue(T);
    int num = 22;
    PrintRoute(T, num);
}