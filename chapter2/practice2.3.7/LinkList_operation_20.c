#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 非循环双向链表,添加访问频率结点,根据频率排序
typedef struct DLNode {
    int data;
    struct DLNode *pred;
    struct DLNode *next;
    int freq;
} DLNode, DLinkList;

void InitDLinkList(DLinkList *L) {
    L->data = 0;
    L->freq = 0;
    L->pred = NULL;
    L->next = NULL;
}

void SetValue(DLinkList *L, const int num[], int length) {
    DLinkList *pT = L;
    for (int i = 0; i < length; i++) {
        DLNode *temp = (DLNode *) malloc(sizeof(DLNode));
        InitDLinkList(temp);
        temp->data = num[i];
        temp->pred = pT;
        pT->next = temp;
        temp->next = NULL;
        pT = temp;
    }
}

DLNode *Locate(DLinkList *L, int x) {
    DLinkList *pPre = L;
    DLinkList *pNext = L->next;
    while (pNext != NULL) {
        if (pNext->data != x) {
            pPre = pPre->next;
            pNext = pNext->next;
        } else {
            break;
        }
    }
    pNext->freq++;
    int tFreq = pNext->freq;
    DLinkList *pInsertPre = L;
    while (pInsertPre->next->freq > tFreq) {
        pInsertPre = pInsertPre->next;
    }
    if (pNext->next) {
        pNext->next->pred = pNext->pred;
    }
    pNext->pred->next = pNext->next;
    pNext->next = pInsertPre->next;
    pInsertPre->next->pred = pNext;
    pNext->pred = pInsertPre;
    pInsertPre->next = pNext;
    return pNext;
}

void printVal(DLinkList *L) {
    DLinkList *t = L->next;
    while (t != NULL) {
        printf("%d\t%d\n", t->data, t->freq);
        t = t->next;
    }
}

int main() {
    DLinkList *L = (DLinkList *) malloc(sizeof(DLNode));
    InitDLinkList(L);
    int num[] = {1, 2, 3, 4, 5};
    int length = 5;
    SetValue(L, num, length);
    Locate(L, 5);
    printVal(L);
    printf("-----------------\n");
    Locate(L, 4);
    printVal(L);
    printf("-----------------\n");
    Locate(L, 5);
    printVal(L);
    printf("-----------------\n");
    Locate(L, 3);
    printVal(L);
    printf("-----------------\n");
    Locate(L, 2);
    printVal(L);
    printf("-----------------\n");
}