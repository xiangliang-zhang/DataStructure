#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

// 搜索旋转排序数组

int search(const int *nums, int numsSize, int target) {
    if (numsSize <= 0) {
        return -1;
    }
    int left = 0;
    int right = numsSize - 1;
    // 旋转后的数组肯定有一半部分是有序的
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if (nums[0] <= nums[mid]) {  // 左半部分有序
            if (nums[0] <= target && target < nums[mid]) {
                // 目标元素在左半部分
                right = mid - 1;
            } else {  //
                left = mid + 1;
            }
        } else {  // 右半部分有序
            if (nums[mid] < target && target <= nums[numsSize - 1]) {
                // 目标元素在右半部分
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int length = sizeof(nums) / sizeof(nums[0]);
    int target = 3;
    int res = search(nums, length, target);
    printf("%d\n", res);
}