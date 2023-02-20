#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 堆排序,时间复杂度O(NlogN), 不稳定

void PrintVal(int *data, int length) {
    for (int i = 1; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

void HeapAdjust(int *data, int length, int i) {
    data[0] = data[i];  // 哨兵
    for (int j = 2 * i; j < length; j *= 2) {
        if (j < length && data[j] < data[j + 1]) {  // 判断结点i的两个孩子哪个大
            j++;
        }
        if (data[j] > data[0]) {
            data[i] = data[j];
            i = j;
        } else break;
    }
    data[i] = data[0];
}

void BuildMaxHeap(int *data, int length) {
    for (int i = length / 2; i > 0; i--) {
        HeapAdjust(data, length, i);
    }
}


void HeapSort(int *data, int length) {
    BuildMaxHeap(data, length - 1);
    for (int i = length - 1; i > 1; i--) {
        int temp = data[i];
        data[i] = data[1];
        data[1] = temp;
        HeapAdjust(data, i - 1, 1);
    }
}


int main() {
    int data[] = {-1, 3, 5, 6, 0, 0, 7, 8};
    int length = sizeof(data) / sizeof(data[0]);
    HeapSort(data, length);
    PrintVal(data, length);
}