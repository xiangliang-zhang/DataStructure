#include <stdbool.h>
#include <stdlib.h>
#include "stdio.h"
#include <uthash.h>



struct hashTable {
    int key;
    UT_hash_handle hh;
};

bool containsDuplicate(int* nums, int numsSize) {
    struct hashTable* set = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* tmp;
        HASH_FIND_INT(set, nums + i, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashTable));
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);
        } else {
            return true;
        }
    }
    return false;
}


int main() {
    int nums[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = containsDuplicate(&nums, numsSize);
    printf("%d", res);
}