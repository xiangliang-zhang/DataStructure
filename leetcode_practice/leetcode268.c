#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"


// 缺失的数字

int missingNumber(int *nums, int numsSize) {
    int res[numsSize];
    for (int i = 0; i < numsSize; i++) {
        res[i] = 0;
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < numsSize) {
            res[nums[i]] = 1;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (res[i] == 0) {
            return i;
        }
    }
    return numsSize;
}
