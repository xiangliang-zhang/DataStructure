#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

// 求数组中出现次数大于一般的元素

int majorityElement(const int *nums, int numsSize) {
    int cnt = 1;
    int res = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == res) {
            cnt++;
        } else {
            cnt--;
            if (cnt == 0) {
                cnt = 1;
                res = nums[i];
            }
        }
    }
    return res;
}

int main() {
    int nums[] = {2,2,1,1,1,2,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = majorityElement(nums, numsSize);
    printf("%d\n", res);
}