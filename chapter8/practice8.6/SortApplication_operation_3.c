#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 计数排序

void CountSorting(int *data, int length) {
    int res[length];
    for (int i = 0; i < length; i++) {
        int count = 0;
        for (int j = 0; j < length; j++) {
            if (data[j] < data[i]) {
                count++;
            }
        }
        res[count] = data[i];
    }
    for (int i = 0; i < length; i++) {
        printf("%d\t", res[i]);
    }
}

int main() {
    int data[] = {5, 4, 6, 3, 7, 2, 8};
    int length = sizeof(data) / sizeof(data[0]);
    CountSorting(data, length);
}