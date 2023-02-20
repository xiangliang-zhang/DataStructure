#include "stdio.h"

// 双端冒泡

void BiBubbleSort(int *data, const int length) {
    int i = 1;
    while (i <= length / 2) {
        for (int j = 0; j < length - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
        for (int k = length - i; k >= 1; k--) {
            if (data[k] < data[k - 1]) {
                int temp = data[k];
                data[k] = data[k - 1];
                data[k - 1] = temp;
            }
        }
        i++;
    }
}

void PrintEle(int *data, const int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

int main() {
    int data[] = {5, 3, 6, 2, 9, 1, 0, 7};
    int length = sizeof(data) / sizeof(data[0]);
    BiBubbleSort(data, length);
    PrintEle(data, length);
}