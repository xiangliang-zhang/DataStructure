#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 单链表拆分成奇偶两个链表
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

    l1->data = 1;
    l2->data = 2;
    l3->data = 3;
    l4->data = 4;
    l5->data = 5;
    l6->data = 6;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = NULL;

    L->next = l1;
}

void DivideLinkList(LinkList *L, LinkList *L2) {
    LinkList *pCur = L;
    LinkList *pCur2 = L2;
    int cnt = 1;
    while (pCur->next != NULL) {
        if (cnt % 2 == 0) {
            LinkList *temp = pCur->next;
            pCur2->next = temp;
            if (pCur->next->next) {
                pCur->next = pCur->next->next;
            } else {
                pCur->next = NULL;
            }
            temp->next = NULL;
            pCur2 = temp;
            cnt++;
        } else {
            pCur = pCur->next;
            cnt++;
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
    LinkList *L2 = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L);
    InitLinkList(L2);
    SetListVal(L);
    DivideLinkList(L, L2);
    printVal(L);
    printf("------------\n");
    printVal(L2);
    return 0;
}