#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 使单链表中的元素递增
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
    L->data = 0;
}

void SetListVal(LinkList *L) {
    LNode *l1 = (LNode *) malloc(sizeof(LNode));
    LNode *l2 = (LNode *) malloc(sizeof(LNode));
    LNode *l3 = (LNode *) malloc(sizeof(LNode));
    LNode *l4 = (LNode *) malloc(sizeof(LNode));
    LNode *l5 = (LNode *) malloc(sizeof(LNode));

    l1->data = 5;
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
}


int partition(int num[], int m, int n) {
    int flag = num[m];
    int i = m, j = n;
    while (i < j) {
        if (num[j] < flag) {
            num[i] = num[j];
            i++;
        } else {
            while (num[j] > flag) j--;
        }
        if (num[i] > flag) {
            num[j] = num[i];
            j--;
        } else {
            while (num[i] < flag) i++;
        }
    }
    num[j] = flag;
    return j;
}

// 对元素排序， 快排
void SortEle(int number[], int left, int right) {
    if (left < right) {
        int t = partition(number, left, right);
        SortEle(number, left, t - 1);
        SortEle(number, t + 1, right);
    }
}

void SortLinkList(LinkList *L) {
    int num = 0;
    LinkList *t = L->next;
    while (t != NULL) {
        num++;
        t = t->next;
    }

    int number[num];
    t = L->next;
    int index = 0;
    while (t != NULL) {
        number[index] = t->data;
        t = t->next;
        index++;
    }
    SortEle(number, 0, index - 1);

    t = L->next;
    index = 0;
    while (t != NULL) {
        t->data = number[index];
        t = t->next;
        index++;
    }
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
    SortLinkList(L);
    printVal(L);
    return 0;
}

