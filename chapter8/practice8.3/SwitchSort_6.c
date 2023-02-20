#include "stdlib.h"
#include "stdio.h"

// 荷兰国旗

void DutchFlagSort(int *data, int length) {
    int left = -1, right = length;
    int i = 0;
    while (i < right) {
        if (data[i] == 0) {
            left++;
            int temp = data[i];
            data[i] = data[left];
            data[left] = temp;
            i++;
        } else if (data[i] == 2) {
            right--;
            int temp = data[i];
            data[i] = data[right];
            data[right] = temp;
        } else {
            i++;
        }
    }
}

void PrintVal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

int main() {
    int data[] = {0, 1, 2, 0, 2, 1, 2, 1, 0, 2, 0, 1};
    int length = sizeof(data) / sizeof(data[0]);
    DutchFlagSort(data, length);
    PrintVal(data, length);
}