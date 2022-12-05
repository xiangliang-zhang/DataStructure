#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 尽可能快的获取两个升序序列的中位数

// 方法一: 遍历两序列， 时间复杂度 o(m+n) 空间复杂度 o(1)
#define MaxSize 100
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

bool InitSqList1(SqList *s) {
    s->data[0] = 2;
    s->data[1] = 4;
    s->data[2] = 6;
    s->data[3] = 8;
    s->data[4] = 10;
    s->data[5] = 11;
    s->length = 6;
    return true;
}

bool InitSqList2(SqList *s) {
    s->data[0] = 12;
    s->data[1] = 13;
    s->data[2] = 15;
    s->data[3] = 17;
    s->data[4] = 19;
    s->length = 5;
    return true;
}

int getMedian(SqList s1, SqList s2) {
    int i = 0, j = 0;
    int cnt = 0;
    int median_index;
    if ((s1.length + s2.length) % 2 == 0) {
        median_index = (s1.length + s2.length) / 2 - 1;
    } else {
        median_index = (s1.length + s2.length) / 2;
    }
    while (i < s1.length && j < s2.length) {
        if (s1.data[i] <= s2.data[j]) {
            if (cnt == median_index) {
                return s1.data[i];
            }
            i++;
            cnt++;
        } else {
            if (cnt == median_index) {
                return s2.data[j];
            }
            j++;
            cnt++;
        }

    }
    if (cnt < median_index) {
        while (i < s1.length) {
            cnt++;
            i++;
            if (cnt == median_index) {
                return s1.data[i];
            }
        }
        while (j < s2.length) {
            cnt++;
            j++;
            if (cnt == median_index) {
                return s2.data[j];
            }
        }
    }

}


int main() {
    SqList s1, s2;
    InitSqList1(&s1);
    InitSqList2(&s2);
    int median = getMedian(s1, s2);
    printf("Median: %d", median);
    return 0;
}

// 最优解应为递归
