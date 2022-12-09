#include <string.h>
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

// 判断单链表元素是否为中心对称元素

#define MaxSize 100

typedef struct SqStack{
    char data[MaxSize];
    int head;
} SqStack;

void InitStack(SqStack *s){
    s->head = -1;
}

typedef struct LNode{
    char data;
    struct LNode *next;
} LNode, LinkList;

void InitLinkList(LinkList *L){
    L->data = 0;
    L->next = NULL;
}

void SetListVal(LinkList *L, const char s[], int length){
    LinkList *t = L;
    for(int i = 0; i < length; i++){
        LNode *temp = (LNode *) malloc(sizeof(LNode));
        InitLinkList(temp);
        temp->data = s[i];
        t->next = temp;
        t = temp;
    }
}

void Push(SqStack * s, char val){
    s->head++;
    s->data[s->head] = val;
}

char Pop(SqStack *s){
    if(s->head >= 0){
        char temp = s->data[s->head];
        s->head--;
        return temp;
    }
    return 0;
}

bool IsSymmetrical(LinkList *L){
    SqStack *s = (SqStack *) malloc(sizeof(SqStack));
    InitStack(s);
    int cnt = 0;
    LinkList *t = L->next;
    while(t != NULL){
        cnt++;
        t = t->next;
    }
    t = L->next;
    for(int i = 0; i < cnt / 2; i++){
        Push(s, t->data);
        t = t->next;
    }
    if(cnt % 2 != 0){
        t = t->next;
    }
    while(s->head != -1 && t != NULL && Pop(s) == t->data){
        t = t->next;
    }
    if(t == NULL && s->head == -1){
        return true;
    }else{
        return false;
    }
}

int main(){
    LinkList *L = (LinkList *) malloc(sizeof(LinkList));
    InitLinkList(L);
    char s[] = {'a', 'b',  'a'};
    int length = sizeof(s) / sizeof(s[0]);
    SetListVal(L, s, length);
    int res = IsSymmetrical(L);
    printf("Symmetrical or not: %d\n", res);
}