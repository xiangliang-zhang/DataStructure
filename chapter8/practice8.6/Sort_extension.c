#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 排序,时间复杂度O(n), 空间复杂度O(1)

void Sort(int *data, int length) {
    int max = data[0];
    for (int i = 0; i < length; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    int res[max];
    for (int i = 0; i <= max; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        res[data[i]] = 1;
    }
    for (int i = 0; i <= max; i++) {
        if (res[i] == 1) {
            printf("%d\t", i);
        }
    }
}

int main() {
    int data[] = {5, 4, 6, 3, 7, 2, 8};
    int length = sizeof(data) / sizeof(data[0]);
    Sort(data, length);
}