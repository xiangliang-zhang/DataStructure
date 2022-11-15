#include <stdbool.h>
#include <stdlib.h>
#include "stdio.h"

// 额外的库需要下载，并复制到include文件夹内
#include <uthash.h>

typedef struct hashTable {
    int key;
    UT_hash_handle hh;
} hash_table;

bool containsDuplicate(int *nums, int numsSize) {
    hash_table *set = NULL;
    for (int i = 0; i < numsSize; i++) {
        hash_table *tmp;
        HASH_FIND_INT(set, nums + i, tmp); // 参数1为要寻找的哈希表， 参数2为变量的地址, 参数3为寻找到的变量的地址
        if (tmp == NULL) {
            tmp = malloc(sizeof(hash_table));
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);
        } else {
            return true;
        }
    }
    return false;
}


int main() {
    int nums[] = {1, 1, 2, 3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = containsDuplicate(&nums, numsSize);
    printf("%d", res);
}