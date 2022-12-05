#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 一维数组左移x个位置
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

bool swapLocation(int *t, int m, int n) {
    while (m < n) {
        int temp = t[m];
        t[m] = t[n];
        t[n] = temp;
        m++;
        n--;
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
    int m = 3; // 左移个数
    int n = s.length;
    swapLocation(s.data, 0, m - 1);
    swapLocation(s.data, m, n - 1);
    swapLocation(s.data, 0, n - 1);
    printEle(s);
    return 0;
}