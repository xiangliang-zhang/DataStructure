#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define MaxSize 50

// 队列的顺序存储实现,初始化、入队、出队、判空
typedef struct {
    int data[MaxSize];
    int front, rear;
} SqQueue;

SqQueue *InitQueue(){
    SqQueue *s = (SqQueue *)malloc(sizeof(SqQueue));
    s->front = 0;
    s->rear = 0;
    return s;
}

bool EnQueue(SqQueue *s, int v){
    if (s->rear < MaxSize){
        s->data[s->rear] = v;
        s->rear++;
        return true;
    }else{
        return false;
    }
}

int DeQueue(SqQueue *s){
    if(s->front != s->rear){
        int t = s->data[s->front];
        s->front++;
        return t;
    }else{
        return -1;
    }
}

bool EmptyQueue(SqQueue *s){
    if(s->front == s->rear){
        return true;
    }else{
        return false;
    }
}

int main(){
    SqQueue *s = InitQueue();
    printf("Initial s.front: %d\n", s->front);
    printf("Initial s.rear: %d\n", s->rear);
    printf("EmptyQueue or not: %d\n", EmptyQueue(s));
    EnQueue(s, 666);
    printf("Inserted element: %d\n", s->data[s->front]);
    printf("EmptyQueue or not: %d\n", EmptyQueue(s));
    int t = DeQueue(s);
    printf("Deleted element: %d\n", t);
    printf("EmptyQueue or not: %d\n", EmptyQueue(s));
    return 0;
}