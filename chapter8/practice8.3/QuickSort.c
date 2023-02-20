#include "stdio.h"

// 快速排序, 时间复杂度O(nlogn),不稳定

int Partition(int *data, int left, int right) {
    int index = data[left];
    while (left < right) {
        while (left < right && data[right] >= index) {
            right--;
        }
        data[left] = data[right];
        while (left < right && data[left] <= index) {
            left++;
        }
        data[right] = data[left];
    }
    data[left] = index;
    return left;
}

void QuickSort(int *data, int left, int right) {
    if (left < right) {
        int indexEle = Partition(data, left, right);
        QuickSort(data, left, indexEle - 1);
        QuickSort(data, indexEle + 1, right);
    }
}

void PrintVal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

int main() {
    int data[] = {5, 6, 7, 8, 4, 3, 2};
    int length = sizeof(data) / sizeof(data[0]);
    QuickSort(data, 0, length - 1);
    PrintVal(data, length);
}