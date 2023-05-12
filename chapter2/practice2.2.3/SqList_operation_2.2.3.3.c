#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// O(n)时间复杂度 O(1)空间复杂度内删除顺序表中的指定元素
#define MaxSize 100

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

bool InitSqList(SqList *s){
    s->data[0] = 1;
    s->data[1] = 2;
    s->data[2] = 3;
    s->data[3] = 3;
    s->data[4] = 4;
    s->data[5] = 5;
    s->data[6] = '\0';
    s->length = 6;
    return true;
}

// 一个指针记录元素应该存放的位置，一个指针遍历元素
bool removeEle(SqList *s, int val){
    int k = 0;
    for(int i = 0; i < s->length; i++){
        if(s->data[i] != val){
            s->data[k] = s->data[i];
            k++;
        }
    }
    s->length = k;
    return true;
}


void PrintVal(SqList *L){
    for(int i = 0; i < L->length; i++){
        printf("%d\t", L->data[i]);
    }
}

int main(){
    SqList s;
    InitSqList(&s);
    int val = 3;
    removeEle(&s, val);
    PrintVal(&s);
}