#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 顺序表元素逆置
#define MaxSize 100
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

bool InitSqList(SqList *s) {
    s->data[0] = 1;
    s->data[1] = 2;
    s->data[2] = 3;
    s->data[3] = 4;
    s->data[4] = 5;
    s->length = 5;
    return true;
}

bool reverseSqList(SqList *s){
    int i = 0;
    int j = s->length-1;
    while (i < j){
        int temp = s->data[i];
        s->data[i] = s->data[j];
        s->data[j] = temp;
        i++;
        j--;
    }
    return true;
}

int main() {
    // 初始化
    SqList s;
    InitSqList(&s);
    reverseSqList(&s);
    return 0;
}