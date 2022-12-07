#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 单链表删除最小值结点
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

    l1->data = 5;
    l2->data = 4;
    l3->data = 1;
    l4->data = 2;
    l5->data = 3;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = NULL;

    L->next = l1;

}

int DelMin(LinkList *L) {
    LinkList *t = L->next;
    LinkList *p = L;
    LinkList *pMinPre;
    int min = L->next->data;
    while (t != NULL) {
        if (t->data < min) {
            min = t->data;
            pMinPre = p;
        }
        t = t->next;
        p = p->next;
    }
    p = pMinPre->next;
    pMinPre->next = p->next;
    free(p);
    return min;
//    printf("%d", pMinPre->data);
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
    int res = DelMin(L);
    printf("Min element: %d\n", res);
    printVal(L);
    return 0;
}