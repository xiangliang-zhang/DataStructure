#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 求两个链表的交集
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
}

void InsertHead(LinkList *L, const int num[], int length) {
    LinkList *temp = L;
    for (int i = 0; i < length; i++) {
        LNode *l = (LNode *) malloc(sizeof(LNode));
        l->data = num[i];
        l->next = NULL;
        temp->next = l;
        temp = temp->next;
    }
}

void FindIntersectNode(LinkList *L1, LinkList *L2) {
    LinkList *pT1 = L1;
    LinkList *t1 = L1->next;
    LinkList *t2 = L2->next;
    while (t2->next != NULL) {
        t2 = t2->next;
    }
    t2->next = t1;
    L1->next = NULL;

    t2 = L2->next;
    while (t1 != NULL && t2 != t1) {
        while (t1->data < t2->data) {
            t1 = t1->next;
        }
        while (t1->data > t2->data) {
            t2 = t2->next;
        }
        if (t1->data == t2->data) {
            LNode *pTemp = (LNode *) malloc(sizeof(LNode));
            pTemp->data = t1->data;
            pTemp->next = NULL;
            pT1->next = pTemp;
            pT1 = pTemp;
            t1 = t1->next;
            t2 = t2->next;
        }

    }
}

void PrintVal(LinkList *L) {
    LinkList *t = L->next;
    while (t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}

int main() {
    LinkList *L1 = (LinkList *) malloc(sizeof(LNode));
    LinkList *L2 = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L1);
    InitLinkList(L2);
    int num1[] = {0, 2, 3, 4};
    int num2[] = {1, 2, 3, 4, 5};
    int length1 = 4;
    int length2 = 5;

    InsertHead(L1, num1, length1);
    InsertHead(L2, num2, length2);

    FindIntersectNode(L1, L2);
    PrintVal(L1);
}