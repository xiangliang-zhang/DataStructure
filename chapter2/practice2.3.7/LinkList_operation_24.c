#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "uthash.h"

// 删除单链表中绝对值相同的元素，只保留第一个
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L) {
    L->data = 0;
    L->next = NULL;
}

void SetVal(LinkList *L, const int num[], int length) {
    LinkList *t = L;
    for (int i = 0; i < length; i++) {
        LNode *l = (LNode *) malloc(sizeof(LNode));
        InitLinkList(l);
        l->data = num[i];
        t->next = l;
        t = l;
    }
}

void DelEle(LinkList *L) {
    int cnt = 0;
    LinkList *t = L->next;
    while (t != NULL) {
        cnt++;
        t = t->next;
    }
    int num[cnt];
    for (int i = 0; i < cnt; i++) {
        num[i] = 0;
    }

    int i = 0;
    int flag;
    LinkList *pPre = L;
    t = L->next;
    while (t != NULL) {
        flag = 0;
        if (i == 0) {
            num[i] = abs(t->data);
            i++;
            t = t->next;
            pPre = pPre->next;
            continue;
        }
        for (int j = 0; j < i; j++) {
            if (num[j] == abs(t->data)) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            pPre->next = t->next;
            free(t);
            t = pPre->next;
            continue;
        } else {
            num[i] = abs(t->next->data);
            i++;
            t = t->next;
            pPre = pPre->next;
        }
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
    int num[] = {21, -15, -1, -7, 15};
    int length = 5;
    SetVal(L, num, length);
    DelEle(L);
    printVal(L);

}

// 时间复杂度O(m) m:链表的长度
// 空间复杂度o(n) n:链表中数据的个数