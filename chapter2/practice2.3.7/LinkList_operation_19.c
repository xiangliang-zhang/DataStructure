#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 依次删除单链表中最小的值，并释放结点

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->next = NULL;
}

void InsertHead(LinkList *L, const int nums[], int length) {
    LinkList *t = L;
    for (int i = 0; i < length; i++) {
        LNode *l = (LNode *) malloc(sizeof(LNode));
        l->data = nums[i];
        l->next = NULL;
        t->next = l;
        t = l;
    }
}

int Partition(int num[], int left, int right) {
    int flag = num[left];
    while (left < right) {
        while (num[right] > flag) {
            right--;
        }
        if (left >= right) {
            break;
        }
        if (num[right] < flag) {
            num[left] = num[right];
            left++;
        }
        while (num[left] < flag) {
            left++;
        }
        if (left >= right) {
            break;
        }
        if (num[left] > flag) {
            num[right] = num[left];
            right--;
        }
    }
    num[right] = flag;
    return right;
}

// 快排
void SortVal(int num[], int left, int right) {
    if (left < right) {
        int t = Partition(num, left, right);
        SortVal(num, left, t - 1);
        SortVal(num, t + 1, right);
    }
}


void SortCleanNode(LinkList *L) {
    int cnt = 0;
    LinkList *t = L->next;
    while (t != NULL) {
        cnt++;
        t = t->next;
    }
    int num[cnt];
    t = L;
    for (int i = 0; i < cnt; i++) {
        t = t->next;
        num[i] = t->data;
    }

    SortVal(num, 0, cnt - 1);

    t = L;
    for (int i = 0; i < cnt; i++) {
        t = t->next;
        t->data = num[i];
    }

    t = L;
    while (t->next != NULL) {
        printf("%d\n", t->next->data);
        LinkList *temp = t->next;
        t->next = t->next->next;
        free(temp);
    }
    free(L);
}

int main() {
    int num[] = {6, 9, 5, 4, 8, 1};
    int length = 6;
    LinkList *L = (LinkList *) malloc(sizeof(LNode));
    InitLinkList(L);
    InsertHead(L, num, length);
    SortCleanNode(L);
    return 0;
}