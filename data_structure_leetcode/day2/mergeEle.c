#include <math.h>
#include <stdio.h>
#include "stdlib.h"

// 合并有序数组，三指针尾插

// 三指针尾插法，优点：省空间
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {

    int a = nums1Size - 1, i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] <= nums2[j]) nums1[a--] = nums2[j--];
        else nums1[a--] = nums1[i--];
    }

    while (i >= 0) nums1[a--] = nums1[i--];
    while (j >= 0) nums1[a--] = nums2[j--];
}

//int main() {
//    int nums1[] = {4, 0, 0, 0, 0, 0};
//    int nums2[] = {1, 2, 3, 5, 6};
//    merge(nums1, 6, 1, nums2, 5, 5);
//    for (int i = 0; i < 6; i++) {
//        printf("%d\t", nums1[i]);
//    }
//}