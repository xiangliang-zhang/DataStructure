#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 找到两个链表的第一个公共结点
typedef struct LNode {
    char data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->data = 0;
    L->next = NULL;
}

void SetVal(LinkList *L1, LinkList *L2) {
    LNode *l1 = (LNode *) malloc(sizeof(LNode));
    LNode *l2 = (LNode *) malloc(sizeof(LNode));
    LNode *l3 = (LNode *) malloc(sizeof(LNode));
    LNode *l4 = (LNode *) malloc(sizeof(LNode));
    LNode *l5 = (LNode *) malloc(sizeof(LNode));
    LNode *l6 = (LNode *) malloc(sizeof(LNode));
    LNode *l7 = (LNode *) malloc(sizeof(LNode));
    LNode *l8 = (LNode *) malloc(sizeof(LNode));
    LNode *l9 = (LNode *) malloc(sizeof(LNode));

    l1->data = 'l';
    l2->data = 'o';
    l3->data = 'a';
    l4->data = 'd';
    l5->data = 'i';
    l6->data = 'n';
    l7->data = 'g';
    l8->data = 'b';
    l9->data = 'e';

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = NULL;
    l8->next = l9;
    l9->next = l5;

    L1->next = l1;
    L2->next = l8;
}

LNode *FindFirstCommon(LinkList *L1, LinkList *L2) {
    int length1 = 0;
    int length2 = 0;
    LinkList *t1 = L1->next;
    LinkList *t2 = L2->next;
    while (t1 != NULL) {
        length1++;
        t1 = t1->next;
    }

    while (t2 != NULL) {
        length2++;
        t2 = t2->next;
    }

    t1 = L1->next;
    t2 = L2->next;
    if (length1 > length2) {
        for (int i = 0; i < length1 - length2; i++) {
            t1 = t1->next;
        }
    } else {
        for (int i = 0; i < length2 - length1; i++) {
            t2 = t2->next;
        }
    }

    while (t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;
    }

    return t1;
}

int main() {
    LinkList *L1 = (LinkList *) malloc(sizeof(LNode));
    LinkList *L2 = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L1);
    InitLinkList(L2);

    SetVal(L1, L2);
    LinkList *res = FindFirstCommon(L1, L2);
    printf("%c\n", res->data);
}

// 时间复杂度O(m + n),两个链表的长度