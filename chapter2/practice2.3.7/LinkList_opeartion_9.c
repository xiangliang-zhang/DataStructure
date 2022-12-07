#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 递增输出结点的数据元素, 不允许使用数组作为辅助空间

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
}

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

void ReversePrint(LinkList *L) {
    LinkList *pCur = L;
    LinkList *pTemp = L;
    int cnt = 0;
    while (pCur->next != NULL) {
        int maxData = pCur->next->data;
        while (pCur->next != NULL) {
            if (pCur->next->data >= maxData) {
                maxData = pCur->next->data;
                pTemp = pCur;
            }
            pCur = pCur->next;
        }
        LinkList *insertLNode = (LinkList *) malloc(sizeof(LNode));
        insertLNode = pTemp->next;
        if (insertLNode->next) {
            pTemp->next = insertLNode->next;
        } else {
            pTemp->next = NULL;
        }
        insertLNode->next = L->next;
        L->next = insertLNode;
        cnt++;
        pCur = L;
        for (int i = 0; i < cnt; i++) {
            pCur = pCur->next;
        }
    }

    pCur = L;
    while (pCur->next != NULL) {
        printf("%d\n", pCur->next->data);
        pTemp = pCur->next;
        pCur->next = pTemp->next;
        free(pTemp);
    }

}

int main() {
    LinkList *L = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L);
    int num[] = {3, 5, 7, 4, 2, 1};
    int length = 6;
    CreateLinkList(L, num, length);
    ReversePrint(L);
    return 0;
}