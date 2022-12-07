#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 两个递增链表合并成一个递减链表

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
}

// 递增
void InsertHead(LinkList *L, const int num[], int length) {
    for (int i = 0; i < length; i++) {
        LNode *t = (LNode *) malloc(sizeof(LNode));
        t->data = num[i];
        t->next = L->next;
        L->next = t;
    }
}

// 递减
void MergeReverseLinkList(LinkList *L1, LinkList *L2, LinkList *L3) {
    LinkList *pPreL1 = L1;
    LinkList *pPreL2 = L2;
    LinkList *pLastL3 = L3;
    LinkList *temp;
    while (pPreL1->next != NULL && pPreL2->next != NULL) {
        if (pPreL1->next->data <= pPreL2->next->data) {
            temp = pPreL1->next;
            pPreL1->next = pPreL1->next->next;
            temp->next = L3->next;
            L3->next = temp;
        } else {
            temp = pPreL2->next;
            pPreL2->next = pPreL2->next->next;
            temp->next = L3->next;
            L3->next = temp;
        }
    }
    while (pPreL1->next != NULL) {
        temp = pPreL1->next;
        pPreL1->next = pPreL1->next->next;
        temp->next = L3->next;
        L3->next = temp;
    }
    while (pPreL2->next != NULL){
        temp = pPreL2->next;
        pPreL2->next = pPreL2->next->next;
        temp->next = L3->next;
        L3->next = temp;
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
    LinkList *L3 = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L1);
    InitLinkList(L2);
    InitLinkList(L3);

    int num1[] = {6, 4, 2, 1};
    int num2[] = {5, 3, 1};
    int length1 = 4;
    int length2 = 3;

    InsertHead(L1, num1, length1);
    InsertHead(L2, num2, length2);
    MergeReverseLinkList(L1, L2, L3);
    PrintVal(L3);
}