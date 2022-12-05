#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"

// 第一题: 删除顺序表中最小的元素，由最后一个元素填补

// 使用动态分配的数组
#define InitSize 100
typedef struct {
    int *data;
    int length;
} SqList;

bool InitSqList(SqList *s) {
    s->data[0] = 5;
    s->data[1] = 4;
    s->data[2] = 3;
    s->data[3] = 2;
    s->data[4] = 1;
    s->data[5] = '\0';
    s->length = 5;
    return true;
}

int removeMin(SqList *s){
    if (s->length == 0){
        return -9999;
    }
    int minTemp = 0;
    for(int i = 0; i < s->length; i++){
        if(s->data[i] < s->data[minTemp]){
            minTemp = i;
        }
    }
    int minData = s->data[minTemp];
    s->data[minTemp] = s->data[s->length - 1];
    return minData;
}

int main() {
    SqList s;
    s.data = (int *) malloc(sizeof(int) * InitSize);
    s.length = 0;
    InitSqList(&s);
    int minData = removeMin(&s);
    printf("%d", minData);
    return 0;
}