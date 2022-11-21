#include <math.h>
#include "stdio.h"

// 最大子数组和，动态规划
// 动态规划
int maxSubArray_dp(int *nums, int numsSize) {
    int pre = 0, maxAns = nums[0];
    for (int i = 0; i < numsSize; i++) {
        pre = fmax(pre + nums[i], nums[i]); // （当前元素 + 之前的序列） 和 当前元素对比， 谁大要谁
        maxAns = fmax(maxAns, pre); // 整个过程中会断断续续（如后续中的1/5），取最大的， -2 1 -3 5 -2 7过程值为：-2 1 -2 5 3 10
    }
    return maxAns;
}


//int main() {
//    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//    int numsSize = sizeof(nums) / sizeof(int);
//    int res = maxSubArray_dp(nums, numsSize);
//    printf("%d", res);
//    return 0;
//}