#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 将线性表拆分成两个链表，一个顺序，一个倒序

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
}

void SetValue(LinkList *L) {
    LNode *l1 = (LNode *) malloc(sizeof(LNode));
    LNode *l2 = (LNode *) malloc(sizeof(LNode));
    LNode *l3 = (LNode *) malloc(sizeof(LNode));
    LNode *l4 = (LNode *) malloc(sizeof(LNode));
    LNode *l5 = (LNode *) malloc(sizeof(LNode));
    LNode *l6 = (LNode *) malloc(sizeof(LNode));

    l1->data = 1;
    l2->data = 99;
    l3->data = 2;
    l4->data = 98;
    l5->data = 3;
    l6->data = 97;

    L->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = NULL;
}

void DivideLinkList(LinkList *L, LinkList *L1) {
    LinkList *pTempL = L->next;
    LinkList *pTempL1;
    int cnt = 1;
    while (pTempL != NULL) {
        if (cnt % 1 == 0) {
            pTempL1 = pTempL->next;
            if (pTempL->next->next) {
                pTempL->next = pTempL->next->next;
            } else {
                pTempL->next = NULL;
            }
            pTempL1->next = L1->next;
            L1->next = pTempL1;

        }
        cnt++;
        pTempL = pTempL->next;

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
    LinkList *L = (LinkList *) malloc(sizeof(LNode));
    LinkList *L1 = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L);
    InitLinkList(L1);
    SetValue(L);
    DivideLinkList(L, L1);
    printVal(L);
    printf("------------\n");
    printVal(L1);
}











