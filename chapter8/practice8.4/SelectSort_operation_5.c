#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"

// 判断数据序列是否构成小根堆

bool IsHeap(const int *data, int length) {
    for (int i = length - 1; i > 0; i--) {
        if (i / 2 > 1 && data[i] < data[i / 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7};  // 0位置不使用
    int length = sizeof(data) / sizeof(data[0]);
    int res = IsHeap(data, length);
    printf("%d", res);
}