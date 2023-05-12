#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 判断带头结点的循环双链表是否对称
typedef struct LNode {
    int data;
    struct LNode *prior;
    struct LNode *next;
} LNode, DLinkList;

void InitDLinkList(DLinkList *L) {
    L->prior = L;
    L->next = L;
}

void SetVal(DLinkList *L) {
    LNode *temp1 = (LNode *) malloc(sizeof(LNode));
    LNode *temp2 = (LNode *) malloc(sizeof(LNode));
    LNode *temp3 = (LNode *) malloc(sizeof(LNode));
    LNode *temp4 = (LNode *) malloc(sizeof(LNode));
    LNode *temp5 = (LNode *) malloc(sizeof(LNode));
    LNode *temp6 = (LNode *) malloc(sizeof(LNode));


    temp1->data = 1;
    temp2->data = 2;
    temp3->data = 3;
    temp4->data = 1;
    temp5->data = 2;
    temp6->data = 3;

    L->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    temp1->prior = L;
    temp2->prior = temp1;
    temp3->prior = temp2;

    L->prior = temp4;
    temp4->prior = temp5;
    temp5->prior = temp6;

    temp6->next = temp5;
    temp5->next = temp4;
    temp4->next = L;

    temp3->next = temp6;
    temp6->prior = temp3;

}

bool IsSymmetric(DLinkList *L) {
    DLinkList *p = L->prior;
    DLinkList *n = L->next;
    while (p != n) {
        if (p->data != n->data) {
            return false;
        } else {
            p = p->prior;
            n = n->next;
        }
    }
    return true;
}

int main() {
    DLinkList *L = (DLinkList *) malloc(sizeof(LNode));
    InitDLinkList(L);
    SetVal(L);
    int res = IsSymmetric(L);
    printf("%d\n", res);
}