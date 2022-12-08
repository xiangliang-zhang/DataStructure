#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 修改链表的结构, 原地逆置加选取
typedef struct node {
    int data;
    struct node *next;
} NODE;

void InitLinkList(NODE *L) {
    L->next = NULL;
    L->data = 0;
}

void SetVal(NODE *L, const int num[], int length) {
    NODE *t = L;
    for (int i = 0; i < length; i++) {
        NODE *temp = (NODE *) malloc(sizeof(NODE));
        InitLinkList(temp);
        temp->data = num[i];
        t->next = temp;
        t = temp;
    }
}

void ReorderList(NODE *L) {
    int cnt = 0;
    NODE *t = L->next;
    while (t != NULL) {
        cnt++;
        t = t->next;
    }
    int mid;
    if (cnt % 2 == 0) {
        mid = cnt / 2;
    } else {
        mid = cnt / 2 + 1;
    }
    t = L->next;
    int index = 1;
    while (index < mid) {
        index++;
        t = t->next;
    }


    NODE *pMid = t->next;
    t->next = NULL;
    NODE *pNext = pMid->next;
    NODE *pNextNext = pNext->next;
    pMid->next = NULL;
    while (pNextNext != NULL) {
        pNextNext = pNext->next;
        pNext->next = pMid;
        pMid = pNext;
        pNext = pNextNext;
    }

    t = L->next;
    int i = 2;
    while (t != NULL && pMid != NULL) {
        if (i % 2 == 0) {
            pNext = pMid;
            pMid = pMid->next;
            pNext->next = t->next;
            t->next = pNext;
            t = pNext;
            i++;
        } else {
            i++;
            t = t->next;
        }
    }
}

void printVal(NODE *L) {
    NODE *t = L->next;
    while (t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}

int main() {
    NODE *L = (NODE *) malloc(sizeof(NODE));
    InitLinkList(L);
    int num[] = {1, 2, 3, 97, 98, 99};
    int length = 6;
    SetVal(L, num, length);
    ReorderList(L);
    printVal(L);
}

// 时间复杂度O(n)
// 空间复杂度O(1)