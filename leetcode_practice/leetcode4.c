#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 找两个正序数组的中位数, 归并思想


double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int mid, n, m;
    double res = 0;
    n = m = 0;
    if (nums1Size + nums2Size == 1)
        mid = 1;
    else
        mid = ((nums1Size + nums2Size) / 2) + 1;
    int nums[mid];

    for (int i = 0; i < mid; i++)
        if (n < nums1Size && m < nums2Size)
            nums[i] = nums1[n] < nums2[m] ? nums1[n++] : nums2[m++];
        else if (n >= nums1Size)
            nums[i] = nums2[m++];
        else if (m >= nums2Size)
            nums[i] = nums1[n++];


    if ((nums1Size + nums2Size) % 2 == 0)
        res = (double) (nums[mid - 1] + nums[mid - 2]) / 2;
    else if (mid == 1)
        res = nums[0];
    else
        res = nums[mid - 1];

    return res;
}


int main() {
    int nums1[] = {1, 2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {1, 1};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    double res = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("%f\n", res);
}