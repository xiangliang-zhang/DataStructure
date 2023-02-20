#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 直接插入排序, 时间复杂度O(n^2),空间复杂度O(1),稳定

void InsertSort(int *data, int length) {
    int i, j;
    for (i = 0, j = 1; j < length; i++, j++) {
        if (data[j] < data[i]) {
            int t = j;
            while (data[t] < data[t - 1]) {
                int temp = data[t];
                data[t] = data[t - 1];
                data[t - 1] = temp;
                t--;
            }
        }
    }
}

// 折半插入排序,时间复杂度O(n^2), 空间复杂度O(1), 稳定
void BinaryInsertSort(int *data, int length) {
    for (int i = 0, j = 1; j < length; i++, j++) {
        if (data[j] < data[i]) {
            int right = i;
            int left = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (data[mid] > data[j]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            int temp = data[j];
            for (right = j; right > left; right--) {
                data[right] = data[right - 1];
            }
            data[left] = temp;
        }
    }
}

void PrintVal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

int main() {
    int data[] = {1, 2, 5, 4, 3, 7, 6};
    int length = sizeof(data) / sizeof(data[0]);
//    InsertSort(data, length);
    BinaryInsertSort(data, length);
    PrintVal(data, length);
}