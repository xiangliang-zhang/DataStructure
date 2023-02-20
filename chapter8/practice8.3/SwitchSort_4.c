#include "stdlib.h"
#include "stdio.h"

// 快排，参考元素随机

int Partition(int *data, int left, int right) {

    int randomIndex = rand() % (right - left + 1) + left;
    int temp = data[randomIndex];
    data[randomIndex] = data[left];
    data[left] = temp;

    int index_data = data[left];
    while (left < right) {
        while (left < right && data[right] >= index_data)
            right--;
        data[left] = data[right];
        while (left < right && data[left] <= index_data)
            left++;
        data[right] = data[left];
    }
    data[left] = index_data;
    return left;
}

void QuickSort(int *data, int left, int right) {
    if (left < right) {
        int index = Partition(data, left, right);
        QuickSort(data, left, index - 1);
        QuickSort(data, index + 1, right);
    }
}

void PrintVal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

int main() {
    int data[] = {5, 4, 6, 3, 7, 2, 8};
    int length = sizeof(data) / sizeof(data[0]);
    QuickSort(data, 0, length - 1);
    PrintVal(data, length);
}