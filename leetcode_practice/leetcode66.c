#include "stdlib.h"
#include "stdio.h"
#include "stdlib.h"

// 数组形成的整数加1

int *plusOne(int *digits, int digitsSize, int *returnSize) {
    if (digits[digitsSize - 1] < 9) {
        digits[digitsSize - 1]++;
        *returnSize = digitsSize;
        return digits;
    } else {
        int i = digitsSize - 1;
        while (i >= 0) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                *returnSize = digitsSize;
                return digits;
            }
            i--;
        }
        int *res = malloc(sizeof(int) * (digitsSize + 1));
        for (int j = digitsSize; j > 0; j--) {
            res[j] = digits[j - 1];
        }
        res[0] = 1;
        *returnSize = digitsSize + 1;
        return res;
    }
}

void printVal(int *nums, int numSize) {
    for (int i = 0; i < numSize; i++) {
        printf("%d\t", nums[i]);
    }
}

int main() {
    int nums[] = {9, 8, 9};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int *res = plusOne(nums, numSize, &returnSize);
    printVal(res, returnSize);
}