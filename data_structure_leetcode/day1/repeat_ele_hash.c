#include <stdbool.h>
#include <stdlib.h>
#include "stdio.h"
#include "uthash.h" // 额外的库需要下载，并复制到include文件夹内

// 判断是否包含重复元素，哈希
typedef struct hashTable {
    int key;
    UT_hash_handle hh; // 用户自定义数据必须包含的结构
} hash_table;

bool containsDuplicate(int *nums, int numsSize) {
    hash_table *set = NULL;
    for (int i = 0; i < numsSize; i++) {
        hash_table *tmp;
        HASH_FIND_INT(set, nums + i, tmp); // 参数1为要寻找的哈希表， 参数2为要寻找的变量的地址，即*nums中值的地址, 参数3为寻找到的变量的地址
        if (tmp == NULL) {
            tmp = malloc(sizeof(hash_table)); // 出错行，忘记分配内存
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);// 往哈希表set中添加名为key的变量，存储在tmp中
        } else {
            return true;
        }
    }
    return false;
}


int main() {
    int nums[] = {1, 1, 2, 3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = containsDuplicate(nums, numsSize);
    printf("%d", res);
}
