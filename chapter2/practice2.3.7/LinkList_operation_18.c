#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 循环单链表的链接

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
}

void InsertHead(LinkList *L, const int num[], int length) {
    LinkList *t = L;
    for (int i = 0; i < length; i++) {
        LNode *l = (LNode *) malloc(sizeof(LNode));
        l->data = num[i];
        l->next = NULL;
        t->next = l;
        t = l;
    }
    t->next = L;
}

bool AttachLinkList(LinkList *L1, LinkList *L2) {
    LinkList *t1 = L1;
    LinkList *t2 = L2;
    while (t1->next != L1) {
        t1 = t1->next;
    }
    t1->next = t2->next;
    while (t2->next != L2) {
        t2 = t2->next;
    }
    t2->next = L1;
    return true;
}

void PrintVal(LinkList *L) {
    LinkList *t = L->next;
    while (t != L) {
        printf("%d\n", t->data);
        t = t->next;
    }
}

int main() {
    LinkList *L1 = (LinkList *) malloc(sizeof(LNode));
    LinkList *L2 = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L1);
    InitLinkList(L2);
    int num1[] = {1, 2};
    int num2[] = {4, 5, 6};
    int length1 = 2;
    int length2 = 3;
    InsertHead(L1, num1, length1);
    InsertHead(L2, num2, length2);
    AttachLinkList(L1, L2);
    PrintVal(L1);
}

