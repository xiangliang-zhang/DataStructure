#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"


// 查找非递减数组中元素的开始/结束位置
int *searchRange(const int *nums, int numsSize, int target, int *returnSize) {
    *returnSize = 2;
    int *res = (int *) malloc(sizeof(int) * 2);
    res[0] = -1;
    res[1] = -1;
    if (numsSize == 0) return res;

    int left = 0;
    int right = numsSize - 1;
    int tempRes = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            tempRes = mid;
            break;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (nums[tempRes] != target) return res;
    left = tempRes;
    right = tempRes;
    while (left >= 0 && nums[left] == target) left--;
    while (right < numsSize && nums[right] == target) right++;
    res[0] = left + 1;
    res[1] = right - 1;
    return res;
}

int main() {
    int nums[] = {2, 2};
    int length = sizeof(nums) / sizeof(nums[0]);
    int target = 2;
    int returnSize = 2;
    int *res = (int *) malloc(sizeof(int) * 2);
    res = searchRange(nums, length, target, &returnSize);
    printf("%d\t%d", res[0], res[1]);
}