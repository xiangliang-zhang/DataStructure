#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 选择排序, 时间复杂度O(n^2), 不稳定

void SelectSort(int *data, int length) {
    for (int i = 0; i < length; i++) {
        int temp_i = i;
        for (int j = i; j < length; j++) {
            if (data[j] < data[temp_i]) {
                temp_i = j;
            }
        }
        int temp = data[i];
        data[i] = data[temp_i];
        data[temp_i] = temp;
    }
}

void PrintVal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

int main() {
    int data[] = {5, 4, 6, 3, 7, 2, 8, 1, 9};
    int length = sizeof(data) / sizeof(data[0]);
    SelectSort(data, length);
    PrintVal(data, length);
}