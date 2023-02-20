#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 数组分成两个集合，元素个数之差最小，元素差值最大

void PrintVal(int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\t", data[i]);
    }
}

void Divide(int *data, int length) {
    int lengthA = length / 2;
    int lengthB = length - lengthA;
    for (int i = length / 2; i >= 1; i /= 2) {
        for (int j = 0; j < length - i; j++) {
            for (int k = j; k >= 0; k -= i) {
                while (data[k] > data[k + i]) {
                    int temp = data[k];
                    data[k] = data[k + i];
                    data[k + i] = temp;
                }
            }
        }
    }
    int dataA[lengthA];
    int dataB[lengthB];
    for (int i = 0; i < lengthA; i++) {
        dataA[i] = data[i];
    }
    for (int i = lengthA; i < length; i++) {
        dataB[i - lengthA] = data[i];
    }
    PrintVal(dataA, lengthA);
    printf("\n");
    PrintVal(dataB, lengthB);
}


int main() {
    int data[] = {5, 4, 6, 3, 7, 2, 8, 1, 9};
    int length = sizeof(data) / sizeof(data[0]);
    Divide(data, length);
}