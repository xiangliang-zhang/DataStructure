#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 顺序表范围1-m+n, 前m有序，后n无序，要求整体有序

void Merge(int *data, int m, int n) {
    int temp[m + n + 1];
    temp[0] = 0;
    for (int i = 1; i <= m + n; i++) {
        temp[i] = data[i];
    }
    int i = 1, j = m + 1, k = 1;
    for (; i <= m && j <= m + n; k++) {
        if (temp[i] <= temp[j]) {
            data[k] = temp[i++];
        } else {
            data[k] = temp[j++];
        }
    }
    while (i <= m) {
        data[k++] = temp[i++];
    }
    while (j <= m + n) {
        data[k++] = temp[j++];
    }
}

int main() {
    int data[] = {0, 1, 3, 5, 7, 2, 4, 6, 8};
    int m = 4, n = 4;
    Merge(data, m, n);
    for (int i = 1; i <= 8; i++) {
        printf("%d\n", data[i]);
    }
}