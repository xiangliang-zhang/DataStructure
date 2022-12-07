#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 两个链表的交集

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
}

void InsertHead(LinkList *L, const int num[], int length) {
    for (int i = 0; i < length; i++) {
        LNode *l = (LNode *) malloc(sizeof(LNode));
        l->data = num[i];
        l->next = L->next;
        L->next = l;
    }
}

void FindIntersectNode(LinkList *L1, LinkList *L2, LinkList *L3) {
    LinkList *t1 = L1->next;
    LinkList *t2 = L2->next;
    LinkList *t3 = L3;
    while (t1 != NULL && t2 != NULL) {
        while (t1->data < t2->data) {
            t1 = t1->next;
        }
        while (t1->data > t2->data) {
            t2 = t2->next;
        }
        if (t1->data == t2->data) {
            LNode *temp = (LNode *) malloc(sizeof(LNode));
            temp->data = t1->data;
            temp->next = NULL;
            t3->next = temp;
            t3 = temp;
            t1 = t1->next;
            t2 = t2->next;
        }
//        t1 = t1->next;
//        t2 = t2->next;
    }
}

void printVal(LinkList *L) {
    LinkList *t = L->next;
    while (t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}

int main() {
    LinkList *L1 = (LinkList *) malloc(sizeof(LNode));
    LinkList *L2 = (LinkList *) malloc(sizeof(LNode));
    LinkList *L3 = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L1);
    InitLinkList(L2);
    InitLinkList(L3);
    int num1[] = {5, 4, 2, 1};
    int num2[] = {5, 4, 3, 0};
    int length1 = 4;
    int length2 = 4;
    InsertHead(L1, num1, length1);
    InsertHead(L2, num2, length2);
    FindIntersectNode(L1, L2, L3);
    printVal(L3);
    return 0;
}