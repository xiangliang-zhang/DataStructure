#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LNode, *LiStack;

// 链栈的初始化，带头节点
LiStack Initial() {
    LiStack l = (LNode *) malloc(sizeof(LNode));
    l->next = NULL;
    return l;
}

// 判栈空
bool isEmpty(LiStack l){
    if (l->next == NULL){
        return true;
    }else{
        return false;
    }
}

// 入栈
bool Push(LiStack l, int v){
    LiStack t = (LNode *) malloc(sizeof(LNode));
    t->data = v;
    t->next = l->next;
    l->next = t;
    return true;
}

// 出栈
bool Pop(LiStack l, int *t){
    if (l->next != NULL){
        *t = l->next->data;
        LNode *node = l->next;
        l->next = l->next->next;
        free(node);
        return true;
    }else{
        return false;
    }
}

// 获得栈顶元素
bool getTop(LiStack l, int *top){
    if (l->next != NULL){
        *top = l->next->data;
        return true;
    }else{
        return false;
    }
}

int main() {
    int t = 0;
    int top = 0;
    LiStack l = Initial();
    printf("Empty or not: %d\n", isEmpty(l));
    Push(l, 1);
    Push(l, 2);
    printf("Empty or not: %d\n", isEmpty(l));
    Pop(l, &t);
    printf("Pop stack value: %d\n", t);
    printf("Empty or not: %d\n", isEmpty(l));
    getTop(l, &top);
    printf("top value: %d\n", top);
    printf("Empty or not: %d\n", isEmpty(l));
    return 0;
}