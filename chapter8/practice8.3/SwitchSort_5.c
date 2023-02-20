#include "stdlib.h"
#include "stdio.h"

// 找出数组中第k小的元素

int GetKMin(int *data, int length, int k) {
    for (int i = 1; i < length; i++) {
        if (data[i] < data[i - 1]) {
            int tempData = data[i];
            int tempIndex = i - 1;
            while (tempIndex >= 0 && data[tempIndex] > tempData) {
                data[tempIndex + 1] = data[tempIndex];
                tempIndex--;
            }
            tempIndex++;
            data[tempIndex] = tempData;
        }
    }
    return data[k - 1];
}

void PrintVal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

int main() {
    int data[] = {5, 4, 6, 3, 7, 2, 8};
    int length = sizeof(data) / sizeof(data[0]);
    int k = 1;
    int res = GetKMin(data, length, k);
//    PrintVal(data, length);
//    printf("\n");
    printf("%d\n", res);
}