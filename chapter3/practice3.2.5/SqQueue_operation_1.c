#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 充分利用循环队列的严元素

#define MaxSize 100

typedef struct SqQueue{
    int data[MaxSize];
    int front;
    int rear;
    int tag;
} SqQueue;

void InitSqQueue(SqQueue *q){
    q->front = 0;
    q->rear = 0;
    q->tag = 0;
}

void EnQueue(SqQueue *q, int v){
    if(q->front == q->rear && q->tag == 1){
        return;
    }else{
        q->data[q->rear % MaxSize] = v;
        q->rear = (q->rear + 1) % MaxSize;
        if(q->rear == q->front){
            q->tag = 1;
        }
    }
}

int DeQueue(SqQueue *q){
    if(q->front == q->rear && q->tag==0){
        return -1;
    }else{
        int t = q->data[q->front];
        q->front = (q->front + 1) % MaxSize;
        return t;
    }
}

int main(){
    SqQueue *q = (SqQueue *) malloc(sizeof(SqQueue));
    InitSqQueue(q);
    printf("%d\n", DeQueue(q));
    EnQueue(q, 1);
    EnQueue(q, 2);
    printf("%d\n", DeQueue(q));
    printf("%d\n", DeQueue(q));
    printf("%d\n", DeQueue(q));
    EnQueue(q, 3);
    printf("%d\n", DeQueue(q));
    return 0;
}
