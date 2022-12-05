#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 查找元素，若存在与后一元素交换，否则插入该元素
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
    s->data[4] = 96;
    s->data[5] = 97;
    s->data[6] = 98;
    s->data[7] = 99;
    s->length = 8;
    return true;
}

bool insertEle(SqList *s, int val, int i) {
    for (int j = s->length; j > i + 1; j--) {
        s->data[j] = s->data[j - 1];
    }
    s->data[i + 1] = val;
    return true;
}

bool FindOrInsert(SqList *s, int val) {
    for (int i = s->length - 1; i >= 0; i--) {
        if (s->data[i] > val) {
            continue;
        } else if (s->data[i] == val) {
            int temp = s->data[i];
            s->data[i] = s->data[i + 1];
            s->data[i + 1] = temp;
            break;
        } else if (s->data[i] < val) {
            insertEle(s, val, i);
            break;
        }
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
    int val = 95;
    FindOrInsert(&s, val);
    printEle(s);
    return 0;
}

// 最优解应为折半查找

