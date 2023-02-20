#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 折半查找

// 递归
void BinaryFindRecursion(const int data[], int left, int right, int val) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (val == data[mid]) {
            printf("%d\n", mid);
        } else if (val > data[mid]) {
            BinaryFindRecursion(data, mid + 1, right, val);
        } else {
            BinaryFindRecursion(data, left, mid - 1, val);
        }
    }
}

// 非递归
void BinaryFind(const int data[], int left, int right, int val) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (data[mid] == val) {
            printf("%d\n", mid);
            break;
        } else if (data[mid] > val) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
}

int main() {
    int data[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    int left = 0;
    int right = sizeof(data) / sizeof(data[0]);
    int val = 8;
    BinaryFindRecursion(data, left, right, val);
    BinaryFind(data, left, right, val);
}