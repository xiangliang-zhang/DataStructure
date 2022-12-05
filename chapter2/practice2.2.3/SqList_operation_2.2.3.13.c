#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 尽快找到数组中未出现的最小整数
#define MaxSize 100
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

bool InitSqList1(SqList *s) {
    s->data[0] = 0;
    s->data[1] = 5;
    s->data[2] = 5;
    s->data[3] = 3;
    s->data[4] = 5;
    s->data[5] = 1;
    s->data[6] = 5;
    s->data[7] = 7;
    s->length = 8;
    return true;
}


int getMinInteger(SqList s1) {
    int max = s1.data[0];
    for (int i = 0; i < s1.length; i++) {
        if (s1.data[i] > max) {
            max = s1.data[i];
        }
    }
    int findMin[max + 1];
    memset(findMin, 0, max + 1);
    for (int i = 0; i < s1.length; i++) {
        if (s1.data[i] >= 1) {
            findMin[s1.data[i]] = 1;
        }
    }
    for (int i = 1; i < max + 1; i++) {
        if (findMin[i] == 0) {
            return i;
        }
    }
    return max + 1;
}

int main() {
    SqList s1;
    InitSqList1(&s1);
    int mainEle = getMinInteger(s1);
    printf("MainEle: %d", mainEle);
    return 0;
}

// 时间复杂度o(n)
// 空间复杂度o(n)
// 空间换时间