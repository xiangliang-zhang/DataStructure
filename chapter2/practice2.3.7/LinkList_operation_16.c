#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 判断B链表是否是A的连续子序列
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
}

void InsertHead(LinkList *L, const int num[], int length) {
    LinkList *temp = L;
    for (int i = 0; i < length; i++) {
        LNode *l = (LNode *) malloc(sizeof(LNode));
        l->data = num[i];
        l->next = NULL;
        temp->next = l;
        temp = l;
    }
}

bool IsSubSequence(LinkList *L1, LinkList *L2) {
    LinkList *t1 = L1->next;
    LinkList *t2 = L2->next;
    while (t1 != NULL) {
        while (t2->data != t1->data) {
            t1 = t1->next;
            if (t1 == NULL) {
                return false;
            }
        }
        if (t2->data == t1->data) {
            LinkList *pT1 = t1;
            LinkList *pT2 = t2;
            while (pT1 != NULL && pT2 != NULL && pT1->data == pT2->data) {
                pT1 = pT1->next;
                pT2 = pT2->next;
            }
            if (pT2 == NULL) {
                return true;
            }
        }
        if (t1->next) {
            t1 = t1->next;
        } else {
            break;
        }
    }
    return false;
}

void printVal(LinkList L) {
    LinkList *t = L.next;
    while (t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}

int main() {
    LinkList *L1 = (LinkList *) malloc(sizeof(LNode));
    LinkList *L2 = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L1);
    InitLinkList(L2);
    int num1[] = {1, 2, 3};
    int num2[] = {3};
    int length1 = 3;
    int length2 = 1;
    InsertHead(L1, num1, length1);
    InsertHead(L2, num2, length2);

    int res = IsSubSequence(L1, L2);
    printf("%d\n", res);
}