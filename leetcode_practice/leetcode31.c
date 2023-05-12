#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"

// 整数数组的下一个排列

void swap(int *a, int *b) {
    int t = *a;
    *a = *b, *b = t;
}

void reverse(int *nums, int left, int right) {
    while (left < right) {
        swap(nums + left, nums + right);
        left++, right--;
    }
}

void nextPermutation(int *nums, int numsSize) {
    // 自右往左找比较小的数
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // 自右向左找比nums[i]大的数
    if (i >= 0) {
        int j = numsSize - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }
        swap(nums + i, nums + j);
    }

    // 调整后的i位置为大的数，j位置为小的数，此时调整i右边位置上的数
    // 右边的数均为倒序，直接倒置即可，因为在前面遍历的时候都是判断的前一元素大于后面元素
    reverse(nums, i + 1, numsSize - 1);
}


int main() {
    int nums[] = {1, 3, 4, 5, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    nextPermutation(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\t", nums[i]);
    }
}