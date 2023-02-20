#include "stdio.h"

// 冒泡排序,事件复杂度O(n^2),稳定

void BubbleSort(int *data, int length) {
    for (int i = 0; i < length; i++) {
        int flag = 0;
        for (int j = 0; j < length - i; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

void PrintVal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}


int main() {
    int data[] = {5, 4, 3, 2, 1, 0};
    int length = sizeof(data) / sizeof(data[0]);
    BubbleSort(data, length);
    PrintVal(data, length);
}