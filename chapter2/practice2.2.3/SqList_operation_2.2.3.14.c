#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 输出三元组的最小距离
#define MaxSize 100
typedef struct {
    int data[MaxSize];
    int length;
} SqList;


int getMinTriple(SqList s1, SqList s2, SqList s3) {
    int min = abs(s1.data[0] - s2.data[0]) + abs(s2.data[0] - s3.data[0]) + abs(s3.data[0] - s1.data[0]);
    int i = 0, j = 0, k = 0;
    while (i < s1.length && j < s2.length && k < s3.length) {
        int temp = abs(s1.data[i] - s2.data[j]) + abs(s2.data[j] - s3.data[k]) + abs(s3.data[k] - s1.data[i]);
        if (temp < min) {
            min = temp;
        }
        // 整体思路为固定最右边的点，左边的两个点右移，从而找到最小的距离
        // s1最小
        if (s1.data[i] < s2.data[j] && s1.data[i] < s3.data[k]) {
            i++;
        } else if (s2.data[j] < s1.data[i] && s2.data[j] < s3.data[k]) { // s2最小
            j++;
        } else { // s3最小
            k++;
        }
    }
    return min;
}

int main() {
    SqList s1, s2, s3;

    s1.data[0] = -1;
    s1.data[1] = 0;
    s1.data[2] = 9;
    s1.length = 3;

    s2.data[0] = -25;
    s2.data[1] = -10;
    s2.data[2] = 10;
    s2.data[3] = -11;
    s2.length = 4;

    s3.data[0] = 2;
    s3.data[1] = 9;
    s3.data[2] = 17;
    s3.data[3] = 30;
    s3.data[4] = 41;
    s3.length = 5;

    int mainEle = getMinTriple(s1, s2, s3);
    printf("MainEle: %d", mainEle);
    return 0;
}

// 时间复杂度o(m + n + q)
// 空间复杂度o(1)