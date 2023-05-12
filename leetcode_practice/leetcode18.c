#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 求数组内四元组等于目标值的组合

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int notContain(int **res, const int *returnSize, const int *tmp) {
    int flag = 1;
    for (int i = 0; i < *returnSize; i++) {
        if (res[i][0] == tmp[0] && res[i][1] == tmp[1] && res[i][2] == tmp[2] && res[i][3] == tmp[3]) {
            return 0;
        }
    }
    return flag;
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 1001);


    for (int f = 0; f < numsSize; f++) {
        printf("%d\t", nums[f]);
    }
    printf("\n");

    int **res = malloc(sizeof(int *) * 1001);
    for (int index1 = 0; index1 < numsSize - 3; index1++) {
        for (int index2 = index1 + 1; index2 < numsSize - 2; index2++) {
            int index3 = index2 + 1;
            int index4 = numsSize - 1;
            while (index3 < index4) {
                long temp1 = (int)nums[index1];
                long temp2 = (int)nums[index2];
                long temp3 = (int)nums[index3];
                long temp4 = (int)nums[index4];
                long tar = (int)target;
                if (temp1 + temp2 + temp3 + temp4 == tar) {
                    int *tmp = malloc(sizeof(int) * 4);
                    tmp[0] = nums[index1];
                    tmp[1] = nums[index2];
                    tmp[2] = nums[index3];
                    tmp[3] = nums[index4];
                    if (notContain(res, returnSize, tmp) == 1) {
                        (*returnColumnSizes)[(*returnSize)] = 4;
                        res[(*returnSize)++] = tmp;
                    }
                    index3++;
                    index4--;
                } else if (temp1 + temp2 + temp3 + temp4 < tar) {
                    index3++;
                } else {
                    index4--;
                }
            }
        }
    }
    return res;
}

int main() {
    int nums[] = {1000000000,1000000000,1000000000,1000000000};
    int length = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int **returnColumnSizes = malloc(sizeof(int) * 1001);
    int target = 0;
    int **res = fourSum(nums, length, target, &returnSize, returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
}