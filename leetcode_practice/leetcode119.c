#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

// 返回杨辉三角的第x行

// (0, 0) = 1
// (1, 0) = 1
// (1, 1) = 1
// (2, 0) = 1
// （2，1） = （1， 0） + （1， 1）
// (3, 1) = (2, 0) + (2, 1)
// (3, 2) = (2, 1) + (2, 2)

int *getRow(int rowIndex, int *returnSize) {
    int nums[34][34];
    for (int i = 0; i < 34; i++) {
        for (int j = 0; j < 34; j++) {
            nums[i][j] = 1;
        }
    }
    for (int i = 2; i <= rowIndex; i++) {
        for (int j = 1; j <= i - 1; j++) {
            nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
        }
    }
    int *res = (int *) malloc(sizeof(int) * (rowIndex + 1));
    for (int i = 0; i <= rowIndex; i++) {
        res[i] = nums[rowIndex][i];
    }
    *returnSize = rowIndex + 1;
    return res;
}

int main() {
    int rowIndex = 3;
    int returnSize = 0;
    int *res = getRow(rowIndex, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d\t", res[i]);
    }
}