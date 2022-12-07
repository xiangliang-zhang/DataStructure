#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 删除不带头结点的单链表L中值为x的结点

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

LinkList *InitLinkList() {
    LNode *l1 = (LNode *) malloc(sizeof(LNode));
    LNode *l2 = (LNode *) malloc(sizeof(LNode));
    LNode *l3 = (LNode *) malloc(sizeof(LNode));
    LNode *l4 = (LNode *) malloc(sizeof(LNode));
    LNode *l5 = (LNode *) malloc(sizeof(LNode));

    l1->data = 1;
    l2->data = 2;
    l3->data = 1;
    l4->data = 4;
    l5->data = 1;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = NULL;
    return l1;
}

LinkList *DeleteLNode(LinkList *L, int del_val) {
    LinkList *t;
    while (L->data == del_val) {
        t = L;
        L = L->next;
        free(t);
    }
    LinkList *fast = L->next;
    LinkList *slow = L;
    while (fast != NULL) {
        if (fast->data == del_val) {
            slow->next = fast->next;
            free(fast);
            if (slow->next) {
                fast = slow->next;
            } else {
                break;
            }
        } else {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return L;
}

void printVal(LinkList *L) {
    LinkList *t = L;
    while (t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}

int main() {
    LinkList *L = InitLinkList();
    int del_val = 1;
    LinkList *res = DeleteLNode(L, del_val);
    printVal(res);
    return 0;
}