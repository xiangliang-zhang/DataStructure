#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 树的孩子表示法

#define MaxSize 100

typedef struct LinkNode {
    int id;
    struct LinkNode *next;
} LinkNode;

typedef struct ChildNode {
    int id;
    int data;
    struct LinkNode *next;
} ChildNode;

typedef struct ChildTree {
    ChildNode *nodes[MaxSize];
    int n;
} ChildTree;

int main() {
    ChildTree *T = (ChildTree *) malloc(sizeof(ChildTree));
    T->n = 2;

    ChildNode *t1 = (ChildNode *) malloc(sizeof(ChildNode));
    t1->id = 1;
    t1->data = 1;

    ChildNode *t2 = (ChildNode *) malloc(sizeof(ChildNode));
    t2->id = 2;
    t2->data = 2;

    T->nodes[0] = t1;
    T->nodes[1] = t2;

    LinkNode *l1 = (LinkNode *) malloc(sizeof(LinkNode));
    l1->next = NULL;
    l1->id = t2->id;

    t1->next = l1;
}