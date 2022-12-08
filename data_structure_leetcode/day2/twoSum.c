#include <malloc.h>
#include <stdio.h>
#include "uthash.h"

// 两数之和

// 暴力求解,时间复杂度O(N²)
int *twoSum_violence(int *nums, int numsSize, int target, int *returnSize) {
    int *res = (int *) malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

//哈希表寻找target - nums[i]的差值，时间复杂度为O(N)
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} hash_table;

hash_table *hashtable; // 存放元素的值，元素的索引

hash_table *find(int ikey) {
    hash_table *tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp); // 在hashtable中利用ikey元素的地址进行寻找，并返回tmp
    return tmp;
}

void insert(int ikey, int ival) { // ikey存放的是元素，ival存放的是坐标
    hash_table *tmp = malloc(sizeof(hash_table));
    tmp->key = ikey, tmp->val = ival;
    HASH_ADD_INT(hashtable, key, tmp);
}

int *twoSum_hash(int *nums, int numsSize, int target, int *returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        hash_table *it = find(target - nums[i]);
        if (it != NULL) {
            int *t = malloc(sizeof(int) * 2);
            t[0] = it->val;// 存储第1坐标
            t[1] = i; // 存储第2坐标
            *returnSize = 2;
            return t;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

//int main() {
//    int nums[] = {3, 2, 4};
//    int target = 6;
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//    int *returnSize;
//    int *res = twoSum_hash(nums, numsSize, target, returnSize);
//    printf("%d %d", res[0], res[1]);
//}