#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

// 判断单链表是否存在环

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
    L->data = 0;
}

void SetVal(LinkList *L, const int num[], int length) {
    LinkList *pPre = L;
    for (int i = 0; i < length; i++) {
        LNode *l = (LNode *) malloc(sizeof(LNode));
        l->data = num[i];
        l->next = NULL;
        pPre->next = l;
        pPre = l;
    }
    pPre->next = L;
}

bool HasCycle(LinkList *L) {
    LinkList *slow = L;
    LinkList *fast = L;
    while (fast != NULL) {
        slow = slow->next;
        if (fast->next) {
            fast = fast->next->next;
        } else {
            break;
        }
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    LinkList *L = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L);
    int num[] = {1, 2, 3, 4, 5};
    int length = 6;
    SetVal(L, num, length);
    int res = HasCycle(L);
    printf("Has cycle: %d", res);
}
