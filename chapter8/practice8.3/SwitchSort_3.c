#include "stdio.h"

// 把奇数移动到偶数前

void OddEvenSort(int *data, int length) {
    int indexOdd = 0, indexEven = length - 1;
    while (indexOdd < indexEven) {
        while (data[indexOdd] % 2 != 0) {
            indexOdd++;
        }
        while (data[indexEven] % 2 == 0) {
            indexEven--;
        }
        int temp = data[indexOdd];
        data[indexOdd] = data[indexEven];
        data[indexEven] = temp;
        indexOdd++;
        indexEven--;
    }
}

void PrintVal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int length = sizeof(data) / sizeof(data[0]);
    OddEvenSort(data, length);
    PrintVal(data, length);
}