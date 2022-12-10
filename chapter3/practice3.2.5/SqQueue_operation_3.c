#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 利用栈模拟队列

#define MaxSize 100

typedef struct SqStack{
    int data[MaxSize];
    int head;
} SqStack;

void InitStack(SqStack *s){
    s->head = -1;
}

void Push(SqStack *s, int x){
    if(s->head + 1 == MaxSize){
        return;
    }else{
        s->head++;
        s->data[s->head] = x;
    }
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

bool StackEmpty(SqStack *s){
    if(s->head == -1){
        return true;
    }else{
        return false;
    }
}

bool StackOverflow(SqStack *s){
    if(s->head + 1 == MaxSize){
        return true;
    }else{
        return false;
    }
}

void EnQueue(SqStack *s1, SqStack *s2, int x){
    if(!StackOverflow(s1)){
        Push(s1, x);
    }
}

int DeQueue(SqStack *s1, SqStack *s2){
    while(!StackEmpty(s1) && !StackOverflow(s2)){
        Push(s2, Pop(s1));
    }
    int res = Pop(s2);
    while(!StackOverflow(s1) && !StackEmpty(s2)){
        Push(s1, Pop(s2));
    }
    return res;
}

bool QueueEmpty(SqStack *s1, SqStack *s2){
    if (s1->head == -1 && s2->head == -1){
        return true;
    }else{
        return false;
    }
}

int main(){
    SqStack *s1 = (SqStack *) malloc(sizeof(SqStack));
    SqStack *s2 = (SqStack *) malloc(sizeof(SqStack));
    InitStack(s1);
    InitStack(s2);
    EnQueue(s1, s2, 1);
    EnQueue(s1, s2, 2);
    EnQueue(s1, s2, 3);
    EnQueue(s1, s2, 4);
    EnQueue(s1, s2, 5);
    EnQueue(s1, s2, 6);
    printf("%d\n", QueueEmpty(s1, s2));
    DeQueue(s1, s2);
    DeQueue(s1, s2);
    DeQueue(s1, s2);
    DeQueue(s1, s2);
    DeQueue(s1, s2);
    DeQueue(s1, s2);
    printf("%d\n", QueueEmpty(s1, s2));
}