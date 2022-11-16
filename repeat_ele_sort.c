#include <stdlib.h>
#include <stdio.h>
#include "stdbool.h"

// 这里的参数为const void*, 意味着可以传入任何类型的参数, 然后将其转换成int*类型, 然后加*取其值
int cmp(const void *_a, const void *_b) {
    char a = *(char *) _a, b = *(char *) _b;
    return a - b;
}

// qsort存在于stdlib.h库, 参数分别为要排序的数组、数组的大小、数组元素的大小、比较方法
bool containsDuplicate(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int nums[] = {1, 3, 2, 6, 7, 8, 9, 10, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = containsDuplicate(nums, numsSize);
    printf("%d", res);
}
