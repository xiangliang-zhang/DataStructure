#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 输出链表的倒数第k个结点的值
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
    L->data = 0;
}

void SetVal(LinkList *L, const int num[], int length) {
    LinkList *t = L;
    for (int i = 0; i < length; i++) {
        LNode *l = (LNode *) malloc(sizeof(LNode));
        l->data = num[i];
        l->next = NULL;
        t->next = l;
        t = l;
    }
}

void PrintReverseK(LinkList *L, int k) {
    int length = 0;
    LinkList *t = L->next;
    while (t != NULL) {
        length++;
        t = t->next;
    }
    t = L;
    int i = length - k + 1;
    int cnt = 0;
    while (cnt < i) {
        t = t->next;
        cnt++;
    }
    printf("%d\n", t->data);
}

// 更好的思路:双指针p/q,相差k个位置后, 同步向前

void TwoPointer(LinkList *L, int k) {
    LinkList *slow = (LinkList *) malloc(sizeof(LinkList));
    LinkList *fast = (LinkList *) malloc(sizeof(LinkList));
    InitLinkList(slow);
    InitLinkList(fast);
    slow = L;
    fast = L;
    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    printf("%d\n", slow->data);
}

int main() {
    LinkList *L = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L);
    int num[] = {1, 2, 3, 4, 5};
    int length = 5;
    SetVal(L, num, length);
    PrintReverseK(L, 2);
    TwoPointer(L, 2);
}

