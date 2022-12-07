#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 删除不带头结点的单链表L中值为x的结点

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

bool InitLinkList(LinkList *L) {

    L = (LinkList *) malloc(sizeof(LNode));
    L->next = NULL;
    return true;
}

bool SetListVal(LinkList *L) {
    LNode *l1 = (LNode *) malloc(sizeof(LNode));
    LNode *l2 = (LNode *) malloc(sizeof(LNode));
    LNode *l3 = (LNode *) malloc(sizeof(LNode));
    LNode *l4 = (LNode *) malloc(sizeof(LNode));
    LNode *l5 = (LNode *) malloc(sizeof(LNode));

    l1->data = 1;
    l2->data = 2;
    l3->data = 3;
    l4->data = 4;
    l5->data = 1;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = NULL;

    L->next = l1;
    return true;
}

bool DelLNode(LinkList *L, int val) {
    LinkList *fast = L->next;
    LinkList *slow = L;
    while (fast != NULL) {
        if (fast->data == val) {
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
    return true;
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
    int val = 1; // 需要删除的元素
    DelLNode(L, val);
    printVal(L);
    return 0;
}