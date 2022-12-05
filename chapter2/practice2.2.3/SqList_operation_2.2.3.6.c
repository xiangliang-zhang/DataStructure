#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 从有序顺序表中删除所有重复元素
#define MaxSize 100

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

bool InitSqList(SqList *s) {
    s->data[0] = 1;
    s->data[1] = 2;
    s->data[2] = 2;
    s->data[3] = 3;
    s->data[4] = 3;
    s->data[5] = 3;
    s->data[6] = 4;
    s->data[7] = 5;
    s->data[8] = 5;
    s->length = 9;
    return true;
}

bool removeRepeatEle(SqList *s) {
    if (s->length > 1) {
        int i = 0, j = 0, cnt = 0;
        while (j < s->length - 1) {
            while (s->data[j] == s->data[j + 1]) {
                j++;
                cnt++;
            }
            s->data[i] = s->data[j];
            j++;
            i++;
        }
        s->length = s->length - cnt;

    }
    return true;

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
    removeRepeatEle(&s);
    printEle(s);
    return 0;
}