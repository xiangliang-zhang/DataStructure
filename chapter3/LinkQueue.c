#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
// 队列的简单链式存储,初始化、入队、出队、判空

// 节点结构
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

// 链队列结构
typedef struct {
    LNode *front, *rear;
} LinkList;

// 初始化链队列，分配内存、指针置空
LinkList *InitQueue(){
    LinkList *lnode = (LinkList *)malloc(sizeof(LinkList));
    lnode->front = NULL;
    lnode->rear = NULL;
    return lnode;
}

// 判队空
bool EmptyQueue(LinkList *l){
    if (l->rear == NULL && l->front == NULL){
        return true;
    }else{
        return false;
    }
}

// 入队
bool EnQueue(LinkList *l, int v){
    LNode *t = (LNode *) malloc(sizeof(LNode));
    t->data = v;
    t->next = NULL;
    if (l->front == NULL && l->rear == NULL){
        l->rear = t;
        l->front = t;
        return true;
    }else{
        l->rear->next = t;
        l->rear = t;
        return true;
    }
    return false;
}

// 出队
int DeQueue(LinkList *l){
    if (l->front != NULL && l->rear != NULL){
        int t = l->front->data;
        LNode *tmp = l->front;
        if (l->front == l->rear){
            l->front = NULL;
            l->rear = NULL;
        }else{
            l->front = l->front->next;
        }
        return t;
    }else{
        return -1;
    }
}

int main(){
    LinkList *l = InitQueue();
    printf("EmptyQueue or not: %d\n", EmptyQueue(l));
    EnQueue(l, 666);
    printf("Inserted element: %d\n", l->front->data);
    printf("EmptyQueue or not: %d\n", EmptyQueue(l));
    int t = DeQueue(l);
    printf("Deleted element: %d\n", t);
    printf("EmptyQueue or not: %d\n", EmptyQueue(l));
    return 0;
}