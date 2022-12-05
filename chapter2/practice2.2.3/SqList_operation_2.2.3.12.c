#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 找到整数序列中的主元素(出现次数大于序列长度一半)
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


int getMainEle(SqList s1) {
    int cnt = 0;
    int t = s1.data[0];
    for (int i = 0; i < s1.length; i++) {
        if (s1.data[i] == t) {
            cnt++;
        } else {
            if (cnt > 0) {
                cnt--;
            } else
                t = s1.data[i];
            cnt = 1;
        }
    }

    int num = 0;
    for (int i = 0; i < s1.length; i++) {
        if (s1.data[i] == t) {
            num++;
        }
    }
    if (num > (s1.length / 2)) {
        return t;
    }
    return -1;
}

int main() {
    SqList s1;
    InitSqList1(&s1);
    int mainEle = getMainEle(s1);
    printf("MainEle: %d", mainEle);
    return 0;
}

// 时间复杂度o(n)
// 空间复杂度o(1)