#include <stdbool.h>
#include <stdlib.h>
#include "stdio.h"

// ����Ŀ���Ҫ���أ������Ƶ�include�ļ�����
#include <uthash.h>

typedef struct hashTable {
    int key;
    UT_hash_handle hh;
} hash_table;

bool containsDuplicate(int *nums, int numsSize) {
    hash_table *set = NULL;
    for (int i = 0; i < numsSize; i++) {
        hash_table *tmp;
        HASH_FIND_INT(set, nums + i, tmp); // ����1ΪҪѰ�ҵĹ�ϣ�� ����2Ϊ�����ĵ�ַ, ����3ΪѰ�ҵ��ı����ĵ�ַ
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