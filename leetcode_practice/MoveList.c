#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 翻转数组

void Reverse(int *data, int left, int right) {
    while (left < right) {
        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;
        left++;
        right--;
    }
}

int MoveLeft(int *data, int length, int k) {
    int left = 0, right = k - 1;
    Reverse(data, left, right);
    left = k, right = length - 1;
    Reverse(data, left, right);
    left = 0, right = length - 1;
    Reverse(data, left, right);
    return 0;
}

int main() {
    int data[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int length = sizeof(data) / sizeof(data[0]);
    MoveLeft(data, length, 5);
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}