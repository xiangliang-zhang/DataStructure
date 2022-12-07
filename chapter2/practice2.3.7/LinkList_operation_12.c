#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 去除递增链表中重复的元素

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
}

void SetListVal(LinkList *L) {
    LNode *l1 = (LNode *) malloc(sizeof(LNode));
    LNode *l2 = (LNode *) malloc(sizeof(LNode));
    LNode *l3 = (LNode *) malloc(sizeof(LNode));
    LNode *l4 = (LNode *) malloc(sizeof(LNode));
    LNode *l5 = (LNode *) malloc(sizeof(LNode));
    LNode *l6 = (LNode *) malloc(sizeof(LNode));
    LNode *l7 = (LNode *) malloc(sizeof(LNode));
    LNode *l8 = (LNode *) malloc(sizeof(LNode));
    LNode *l9 = (LNode *) malloc(sizeof(LNode));
    LNode *l10 = (LNode *) malloc(sizeof(LNode));

    l1->data = 7;
    l2->data = 10;
    l3->data = 10;
    l4->data = 21;
    l5->data = 30;
    l6->data = 42;
    l7->data = 42;
    l8->data = 42;
    l9->data = 51;
    l10->data = 70;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    l8->next = l9;
    l9->next = l10;
    l10->next = NULL;

    L->next = l1;
}

void RemoveRepeatELe(LinkList *L) {
    LinkList *pPre = L->next;
    LinkList *pFree;
    while (pPre->next != NULL) {
        if (pPre->next->data == pPre->data) {
            pFree = pPre->next;
            if (pPre->next->next) {
                pPre->next = pPre->next->next;
            } else {
                pPre->next = NULL;
            }
            free(pFree);
        } else {
            pPre = pPre->next;
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
    LinkList *L = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L);
    SetListVal(L);
    RemoveRepeatELe(L);
    PrintVal(L);
}