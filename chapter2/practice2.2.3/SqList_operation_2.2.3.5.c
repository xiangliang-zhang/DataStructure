#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 删除顺序表中值范围在a-b之间的元素, 双指针
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
    s->data[5] = 6;
    s->length = 6;
    return true;
}


bool removeRangeEle(SqList *s, int a, int b) {
    if (a > b) {
        printf("a、b选值有误！");
        return false;
    } else if (s->length == 0) {
        printf("顺序表为空");
        return false;
    } else {
        int i = 0, j = 0, cnt = 0;
        while (j < s->length) {
            if (s->data[j] >= a && s->data[j] <= b) {
                j++;
                cnt++;
            } else {
                s->data[i] = s->data[j];
                i++;
                j++;
            }
        }
        s->length = s->length - cnt;
        return true;
    }
}

void printEle(SqList s) {
    for (int i = 0; i < s.length; i++) {
        printf("%d\n", s.data[i]);
    }
}

int main() {
    SqList s;
    s.length = 0;
    InitSqList(&s);
    int a = 1;
    int b = 6;
    removeRangeEle(&s, a, b);
    printEle(s);
    return 0;
}