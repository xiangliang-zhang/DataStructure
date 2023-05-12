#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

// nums[i] == nums[j] && abs(i-j) < k

bool containsNearbyDuplicate(const int *nums, int numsSize, int k) {
    int i = 0;
    while (i < numsSize - 1) {
        for (int j = i + 1; j < numsSize && j <= i + k; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
        i++;
    }
    return false;
}


int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 15;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = containsNearbyDuplicate(nums, numsSize, k);
    printf("%d\n", res);
}