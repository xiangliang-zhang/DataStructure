// 线性表的单链式存储

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 头插
LinkList HeadInsert(LinkList L) {
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    L->data = 0;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

//尾插
LinkList TailInsert(LinkList L) {
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s;
    LNode *r = L;
    int x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = r->next;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 获取第i个结点的值
LNode *GetElem(LinkList L, int i){
    LNode *r = L;
    for (int index = 0; index < i; index++){
        r = r->next;
    }
    return r;
}

// 按值查找元素
LNode *LocateElem(LinkList L, int v){
    LNode *l = L;
    while (l->next != NULL){
        if (l->data == v){
            return l;
        }else{
            l = l->next;
        }
    }
    return NULL;
}

//插入结点
bool insertLNode(LinkList L, int i, int v){
    LNode *r = L;
    LNode *s;
    for (int index = 0; index < i - 1; index++){
        r = r->next;
    }
    s = (LNode *) malloc(sizeof(LNode));
    s->data = v;
    s->next = r->next;
    r->next = s;
    return true;
}

// 删除结点
bool deleteLNode(LinkList L, int i, int e){
    LNode *r = L;
    LNode *t;
    for(int index = 0; index < i-1; index++){
        r = r->next;
    }
    t = r->next;
    e = t->data;
    r->next = r->next->next;
    free(t);
    return true;
}

// 获取链表的长度
int getLength(LinkList L){
    int num = 0;
    LNode *r = L;
    while (r != NULL){
        num++;
        r = r->next;
    }
    return num;
}


int main() {
    LinkList L = NULL;

//    LinkList L1 = HeadInsert(L);
//    LNode *res1 = GetElem(L1, 5);
//    printf("%d", res1->data);

    LinkList L2 = TailInsert(L);
//    LNode *res2 = GetElem(L2, 5);
//    printf("%d\n", res2->data);
//    LNode *res3 = LocateElem(L2, 5);
//    printf("%d\n", res3->data);


//    insertLNode(L2, 5, 5);
    deleteLNode(L2, 5, 0);

//    int length = getLength(L1);
//    printf("%d", length);
}