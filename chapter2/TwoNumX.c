#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

// 数组中两数之和为X, 时间换空间

void TwoNumX(const int *data, int length, int X) {
    int max = data[0];
    for (int i = 1; i < length; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    int temp[max];
    for (int i = 0; i <= max; i++) {
        temp[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        temp[data[i]] = 1;
    }
    for (int i = 0; i < length; i++) {
        if (data[i] < X / 2 && data[i] != X - data[i] && temp[X - data[i]] == 1) {
            printf("%d %d \n", data[i], (X - data[i]));
        }
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(data) / sizeof(data[0]);
    int X = 10;
    TwoNumX(data, length, X);
}