#include <minmax.h>
#include <math.h>
#include "stdio.h"
#include "stdlib.h"
#include "uthash.h"

// 排序 + 双指针
int cmp(const void *_a, const void *_b) {
    int a = *(int *) _a, b = *(int *) _b;
    return a - b;
}


int *get_sorted_nums(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums;
}


int *intersect_sort_pointer(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    int *t1 = get_sorted_nums(nums1, nums1Size);
    int *t2 = get_sorted_nums(nums2, nums2Size);
    int i = 0, j = 0, k = 0;
    int *res = (int *) malloc(sizeof(int) * min(nums1Size, nums2Size));
    while (i < nums1Size && j < nums2Size) {
        if (t1[i] == t2[j]) {
            res[k++] = t1[i];
            i++;
            j++;
            *returnSize = *returnSize + 1;
        } else if (t1[i] < t2[j]) {
            i++;
        } else if (t1[i] > t2[j]) {
            j++;
        }
    }
    return res;
}
// 哈希方法
typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} hash_table;

int *intersect_hash(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize){
    hash_table *h = NULL;
    for(int i = 0; i < nums1Size; i++){
        hash_table *t;
        HASH_FIND_INT(h, nums1 + i, t);
        if (t != NULL){
            t -> value++;
        }else{
            t = malloc(sizeof(hash_table));
            t -> key = nums1[i];
            t -> value = 1;
            HASH_ADD_INT(h, key, t);
        }
    }
    int *k;
    if (nums1Size < nums2Size)
    {
        k = nums1;
    }
    else {
        k = nums2;
    }
    int cnt = 0;
    for (int i = 0; i < nums2Size; i++) {
        hash_table *t = NULL;
        HASH_FIND_INT(h, &nums2[i], t);
        if (t != NULL && t->value) {
            t->value--;
            k[cnt] = t->key;
            cnt++;
        }
    }
    *returnSize = cnt;
    return k;
}

int main() {
    int nums[] = {4,7,9,7,6,7};
    int nums2[] = {5,0,0,6,1,6,2,2,4};
    int nums1Size = sizeof(nums) / sizeof(nums[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize = 0;
    int *res = intersect_hash(nums, nums1Size, nums2, nums2Size, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d\t", res[i]);
    }
    return 0;
}