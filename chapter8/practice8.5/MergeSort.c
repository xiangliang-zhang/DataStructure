#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"

// 归并排序

#define MaxSize 100

void Merge(int *data, int left, int mid, int right) {  // 两个数组,数组一low - mid, 数组二mid+1 - high
    int temp[MaxSize];
    for (int i = left; i <= right; i++) {
        temp[i] = data[i];
    }
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (temp[i] <= temp[j]) {
            data[k] = temp[i];
            i++;
        } else {
            data[k] = temp[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        data[k] = temp[i];
        k++;
        i++;
    }
    while (j <= right) {
        data[k] = temp[j];
        k++;
        j++;
    }
}

void MergeSort(int *data, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(data, left, mid);
        MergeSort(data, mid + 1, right);
        Merge(data, left, mid, right);
    }
}

void PrintVal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

int main() {
    int data[] = {5, 4, 6, 3, 7, 2, 8, 9, 1};
    int length = sizeof(data) / sizeof(data[0]);
    MergeSort(data, 0, length - 1);
    PrintVal(data, length);
}