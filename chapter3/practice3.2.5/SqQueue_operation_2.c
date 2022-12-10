#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

// 利用栈将队列中的元素逆置

#define MaxSize 100

typedef struct SqStack{
    int data[MaxSize];
    int head;
} SqStack;

typedef struct SqQueue{
    int data[MaxSize];
    int front;
    int rear;
} SqQueue;

void InitSqStack(SqStack *s){
    s->head = -1;
}

void InitSqQueue(SqQueue *q){
    q->front = 0;
    q->rear = -1;
}

void Push(SqStack *s, int val){
    s->head++;
    s->data[s->head] = val;
}

int Pop(SqStack *s){
    if(s->head == -1){
        return -1;
    }else{
        int t = s->data[s->head];
        s->head--;
        return t;
    }
}

void EnQueue(SqQueue *q, int val){
    if(q->rear != MaxSize - 1){
        q->rear++;
        q->data[q->rear] = val;
    }
}

int DeQueue(SqQueue *q){
    if(q->front == q->rear + 1){
        return -1;
    }else{
        int t = q->data[q->front];
        q->front++;
        return t;
    }
}

int main(){
    SqQueue *q = (SqQueue *) malloc(sizeof(SqQueue));
    SqStack *s = (SqStack *) malloc(sizeof(SqStack));
    InitSqQueue(q);
    InitSqStack(s);
    EnQueue(q, 1);
    EnQueue(q, 3);
    EnQueue(q, 5);
    EnQueue(q, 7);
    EnQueue(q, 9);

    Push(s, DeQueue(q));
    Push(s, DeQueue(q));
    Push(s, DeQueue(q));
    Push(s, DeQueue(q));
    Push(s, DeQueue(q));

    EnQueue(q, Pop(s));
    EnQueue(q, Pop(s));
    EnQueue(q, Pop(s));
    EnQueue(q, Pop(s));
    EnQueue(q, Pop(s));

    printf("%d\n", DeQueue(q));
    printf("%d\n", DeQueue(q));
    printf("%d\n", DeQueue(q));
    printf("%d\n", DeQueue(q));
    printf("%d\n", DeQueue(q));

}
