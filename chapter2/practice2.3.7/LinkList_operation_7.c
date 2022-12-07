#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

// 删除单链表中元素位于a-b之间的结点

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

    l1->data = 1;
    l2->data = 2;
    l3->data = 3;
    l4->data = 4;
    l5->data = 5;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = NULL;

    L->next = l1;
}

void DelRangeEle(LinkList *L, int a, int b) {
    LinkList *pCur = L->next;
    LinkList *pPre = L;
    while (pCur != NULL) {
        if (pCur->data >= a && pCur->data <= b) {
            pPre->next = pCur->next;
            free(pCur);
            if (pPre->next) {
                pCur = pPre->next;
            } else {
                break;
            }
        } else {
            pCur = pCur->next;
            pPre = pPre->next;
        }
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
    InitLinkList(L);
    SetListVal(L);
    int a = 4, b = 4;
    DelRangeEle(L, a, b);
    printVal(L);
    return 0;
}