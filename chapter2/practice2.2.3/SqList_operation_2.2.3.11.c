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
    s->data[5] = 20;
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
    return -1;
}

// 方法二，
// 1. 分别求两数组中位数
// 2. 若相同，则返回次数
// 3. 若不相同，则保留较小数组的较大部分 和 较大数组的较小部分
// 4. 重复求中位数
// 时间复杂度为o(log2n)
int getMedianRecursion(SqList s1, SqList s2) {
    int i_s1 = 0, j_s1 = s1.length - 1, i_s2 = 0, j_s2 = s2.length - 1;
    while (i_s1 < j_s1 && i_s2 < j_s2) {
        int mid_1 = (i_s1 + j_s1) / 2;
        int mid_2 = (i_s2 + j_s2) / 2;
        int median1 = s1.data[mid_1];
        int median2 = s2.data[mid_2];
        if (median1 == median2) {
            return median1;
        } else if (median1 < median2) { // 取s1的后半部分和s1的前半部分
            if ((i_s1 + j_s1) % 2 == 0) { // s1中元素个数为奇数
                i_s1 = mid_1;  // 去掉中位数前的元素
            } else { // s1中元素为偶数
                i_s1 = mid_1 + 1; // 去掉一般元素
            }
            j_s2 = mid_2; // 无论s2中的元素个数为奇偶，均去除中位数后的元素
        } else { // 取s1的前半部分和s2的后半部分
            if ((i_s2 + j_s2) % 2 == 0) {
                i_s2 = mid_2;
            } else {
                i_s2 = mid_2 + 1;
            }
            j_s1 = mid_1;
        }
    }
    return s1.data[i_s1] < s2.data[i_s2] ? s1.data[i_s1] : s2.data[i_s2];
}


int main() {
    SqList s1, s2;
    InitSqList1(&s1);
    InitSqList2(&s2);
//    int median = getMedian(s1, s2);
//    printf("Median: %d", median);
    int median2 = getMedianRecursion(s1, s2);
    printf("Median: %d", median2);
    return 0;
}

// 最优解应为递归
