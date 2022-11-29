#define MaxSize 50
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 循环队列的简单实现,初始化、入队、出队、判空
typedef struct{
    int data[MaxSize];
    int front, rear;
} CircularQueue;

// 初始化队列
CircularQueue *InitQueue(){
    CircularQueue *c = (CircularQueue *) malloc(sizeof(CircularQueue));
    c->front = 0;
    c->rear = 0;
    return c;
}

// 入队
bool EnQueue(CircularQueue *c, int v){
    if ((c->rear + 1) % MaxSize != (c->front)){
        c->data[c->rear] = v;
        c->rear = (c->rear + 1) % MaxSize;
        return true;
    }else{
        return false;
    }
}

// 出队
int DeQueue(CircularQueue *c){
    if (c->front == c->rear){
        return -1;
    }else{
        int t = c->data[c->front];
        c->front = (c->front + 1) % MaxSize;
        return t;
    }
}

// 判空
bool EmptyQueue(CircularQueue * c){
    if (c->front == c->rear){
        return true;
    }else{
        return false;
    }
}

int main(){
    CircularQueue *c = InitQueue();
    printf("EmptyQueue or not: %d\n", EmptyQueue(c));
    EnQueue(c, 666);
    printf("EmptyQueue or not: %d\n", EmptyQueue(c));
    printf("Inserted element:%d\n", c->data[c->front]);
    int t = DeQueue(c);
    printf("Deleted element:%d\n", t);
    printf("EmptyQueue or not: %d\n", EmptyQueue(c));
    return 0;
}