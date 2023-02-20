#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// n个元素的数组的某个元素归位，要求比较次数不超过n

int RightLocation(int *data, int length) {
    int index = data[length - 1];
    int left = 1, right = length - 1;
    while (left < right) {
        while (left < right && data[left] <= index) left++;
        if (left < right) data[right] = data[left];
        while (left < right && data[right] >= index) right--;
        if (left < right) data[left] = data[right];
    }
    data[left] = index;
    return left;
}

int main() {
    int data[] = {0, 5, 4, 6, 3, 7, 2, 8};
    int length = sizeof(data) / sizeof(data[0]);
    int res = RightLocation(data, length);
    printf("%d\n", res);
}