#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 反向输出结点中的值
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *pNode);

void SetListVal(LinkList *pNode);

void ReversePrintVal(LinkList *node);

void RecursionReversePrint(LinkList *L);

int main() {
    LinkList *L = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L);
    SetListVal(L);
//    ReversePrintVal(L);
    RecursionReversePrint(L->next);
    return 0;
}

void ReversePrintVal(LinkList *node) {
    int *res = (int *) malloc(sizeof(int) * 9999);
    int length = 0;
    LinkList *t = node->next;
    while (t != NULL) {
        res[length] = t->data;
        length++;
        t = t->next;
    }
    for (int i = length - 1; i >= 0; i--) {
        printf("%d\n", res[i]);
    }
}

void RecursionReversePrint(LinkList *L) {
    if (L->next != NULL) {
        RecursionReversePrint(L->next);
    }
    if (L != NULL)
        printf("%d\n", L->data);

}

void SetListVal(LinkList *pNode) {
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

    pNode->next = l1;
}

void InitLinkList(LinkList *pNode) {
    pNode->next = NULL;
}
