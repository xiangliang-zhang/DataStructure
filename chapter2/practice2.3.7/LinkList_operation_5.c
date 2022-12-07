#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 单链表原地逆置
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

void reverseLNode(LinkList *L) {
    LinkList *head = L;
    LinkList *current = L->next;
    LinkList *pNext = L->next->next;
    current->next = NULL;
    while (pNext != NULL) {
        current = pNext;
        pNext = pNext->next;
        current->next = head->next;
        head->next = current;
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
    reverseLNode(L);
    printVal(L);
}