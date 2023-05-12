#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 盛水最多的容器

int max(int a, int b) {
    return a >= b ? b : a;
}

int maxArea(int *height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int max_res = 0;
    while (left < right) {
        int cur_res = (right - left) * max(height[left], height[right]);
        if(cur_res > max_res) max_res = cur_res;
        if(height[left] <= height[right]) left++;
        else right--;
    }
    return max_res;
}


int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);

    int height2[] = {1, 1};
    int heightSize2 = sizeof(height2) / sizeof(height2[0]);
    int res = maxArea(height2, heightSize2);
    printf("%d\n", res);
}