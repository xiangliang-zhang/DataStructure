#include "stdio.h"

// 希尔排序, 时间复杂度为O(n^2), 空间复杂度为O(1)

void ShellSort(int *data, int length) {
    for (int i = length / 2; i >= 1; i /= 2) {
        for (int j = 0; j < length - i; j++) {
            int k = j;
            while (data[k] > data[k + i]) {
                int temp = data[k];
                data[k] = data[k + i];
                data[k + i] = temp;
                k -= i;
            }
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
    ShellSort(data, length);
    PrintVal(data, length);
}