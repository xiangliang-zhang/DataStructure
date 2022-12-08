#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 线性表的双链表存储
typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;


// 双链表的插入, 在双链表L中第i个位置插入元素v,特例：位置0
bool insertEle(DLinkList L, int i, int v) {
    DLinkList t = L;
    if (i == 0) {
        DNode *val = (DNode *) malloc(sizeof(DNode));
        L = val;
        val->data = v;
        val->next = t;
        val->prior = NULL;
        t->prior = val;
        return true;
    } else if (i > 0){
        for(int a = 0; a < i - 1; a ++)
        {
            if (t->next){
                t = t->next;
            }
            else {
                break;
            }
        }
        DLinkList n = t->next;
        DNode *val = (DNode *) malloc(sizeof(DNode));
        val->data = v;
        val->next = n;
        val->prior = t;
        t->next = val;
        if (n) n->prior = val;
        return true;
    }else
        return false;
}

// 双链表的删除, 删除第i个位置的元素并返回， 特例：第一个元素、最后一个元素
int deleteEle(DLinkList L, int i) {
    DLinkList t = L;
    if (i == 0) {
        int val = L->data;
        L = L->next;
        L->prior = NULL;
        return val;
    } else {
        int j = 0;
        while (t->next != NULL && j < i) {
            t = t->next;
            j++;
        }
        DLinkList p = t->prior;
        int val = t->data;
        p->next = p->next->next;
        if (p->next) p->next->prior = p; // 避免删除最后一个元素出错
        free(t);
        return val;
    }
}

int main() {
    DNode *d1 = (DNode *) malloc(sizeof(DNode));
    DNode *d2 = (DNode *) malloc(sizeof(DNode));
    DNode *d3 = (DNode *) malloc(sizeof(DNode));
    DNode *d4 = (DNode *) malloc(sizeof(DNode));
    DNode *d5 = (DNode *) malloc(sizeof(DNode));
    DLinkList d = d1;
    d1->data = 1;
    d2->data = 2;
    d3->data = 3;
    d4->data = 4;
    d5->data = 5;

    d1->next = d2;
    d2->next = d3;
    d3->next = d4;
    d4->next = d5;
    d5->next = NULL;

    d5->prior = d4;
    d4->prior = d3;
    d3->prior = d2;
    d2->prior = d1;
    d1->prior = NULL;

    int res1 = insertEle(d, 6, 10);
    printf("%d", res1);

    int res2 = deleteEle(d, 4);
    printf("%d", res2);
}