#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"

// 输出连续的区间

char **summaryRanges(int *nums, int numsSize, int *returnSize) {
    char **res = malloc(sizeof(char *) * numsSize);
    int i = 0;
    *returnSize = 0;
    while (i < numsSize) {
        int low = i;
        i++;
        while (i < numsSize && nums[i] == nums[i - 1] + 1) {
            i++;
        }
        int high = i - 1;
        char *resTemp = (char *) malloc(sizeof(char) * 25);  // 这个地方不可以是4，会报错
        sprintf(resTemp, "%d", nums[low]); // sprintf() 字符串格式化命令, 将数据写入字符串中
        if (low < high) {
            sprintf(resTemp + strlen(resTemp), "->");
            sprintf(resTemp + strlen(resTemp), "%d", nums[high]);
        }
        res[(*returnSize)++] = resTemp;
    }
    return res;
}

int main() {
    int nums[] = {0, 1, 2, 4, 5, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    char **res = summaryRanges(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        puts(res[i]);  // puts() 输出字符串
    }
}