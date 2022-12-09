#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

// ¹²ÏíÕ»µÄÈëÕ»³öÕ»

#define MaxSize 100

typedef struct SqStack{
    int data[MaxSize];
    int top[2];
} SqStack;


void InitSqStack(SqStack *s){
    s->top[0] = -1;
    s->top[1] = MaxSize;
}

void Push(SqStack *s, int i, int val){
    if(i == 0){
        s->top[0]++;
        s->data[s->top[0]] = val;
    }else if(i == 1){
        s->top[1]--;
        s->data[s->top[1]] = val;
    }else{
        printf("Õ»Âú\n");
    }
}

int Pop(SqStack *s, int i){
    int t = -9999;
    if(i == 0 && s->top[0] != -1){
        t = s->data[s->top[0]];
        s->top[0]--;
    }else if(i == 1 && s->top[1] != MaxSize){
        t = s->data[s->top[1]];
        s->top[1]++;
    }else{
        printf("Õ»¿Õ\n");
    }
    return t;
}

int main(){
    SqStack *s = (SqStack *) malloc(sizeof(SqStack));
    InitSqStack(s);
    Pop(s,1);
    Pop(s,0);
    Push(s, 1, 1);
    Pop(s, 0);
    int res = Pop(s, 1);
    printf("%d\n", res);
    Pop(s,1);
}