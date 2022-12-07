#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 找到两个链表的公共结点

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
}

// 尾插建链表
void CreateLinkList(LinkList *L, const int num[], int length) {
    LinkList *t = L;
    for (int i = 0; i < length; i++) {
        LNode *l = (LNode *) malloc(sizeof(LNode));
        l->data = num[i];
        l->next = NULL;
        t->next = l;
        t = t->next;
    }
}

// 手动建链表
void SetListVal(LinkList *L1, LinkList *L2) {
    LNode *l1 = (LNode *) malloc(sizeof(LNode));
    LNode *l2 = (LNode *) malloc(sizeof(LNode));
    LNode *l3 = (LNode *) malloc(sizeof(LNode));
    LNode *l4 = (LNode *) malloc(sizeof(LNode));
    LNode *l5 = (LNode *) malloc(sizeof(LNode));
    LNode *l6 = (LNode *) malloc(sizeof(LNode));
    LNode *l7 = (LNode *) malloc(sizeof(LNode));
    LNode *l8 = (LNode *) malloc(sizeof(LNode));
    LNode *l9 = (LNode *) malloc(sizeof(LNode));

    l1->data = 1;
    l2->data = 2;
    l3->data = 3;
    l4->data = 4;
    l5->data = 5;
    l6->data = 6;
    l7->data = 7;
    l8->data = 8;
    l9->data = 9;

    l1->next = l2;
    l2->next = l4;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    l8->next = l9;
    l9->next = NULL;

    L1->next = l1;
    L2->next = l3;
}


void FindCommonLNode(LinkList *L1, LinkList *L2) {
    LinkList *t1 = L1;
    LinkList *t2 = L2;
    int cnt1 = 0, cnt2 = 0;
    while (t1 != NULL) {
        cnt1++;
        t1 = t1->next;
    }
    while (t2 != NULL) {
        cnt2++;
        t2 = t2->next;
    }

    t1 = L1;
    t2 = L2;
    if (cnt1 > cnt2) {
        for (int i = cnt1; i != cnt2; i--) {
            t1 = t1->next;
        }
    } else {
        for (int i = cnt2; i != cnt1; i--) {
            t2 = t2->next;
        }
    }

    while (t1 != NULL && t2 != NULL) {
        if (t1 == t2) {
            printf("Common node value: %d\n", t1->data);
        }
        t1 = t1->next;
        t2 = t2->next;
    }
}

int main() {
    LinkList *L1 = (LinkList *) malloc(sizeof(LNode));
    LinkList *L2 = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L1);
    InitLinkList(L2);
    SetListVal(L1, L2);
    FindCommonLNode(L1, L2);
    return 0;
}