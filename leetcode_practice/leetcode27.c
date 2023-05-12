
// 原地移除数组中等于val的元素，并返回移除后数组的长度
int removeElement(int *nums, int numsSize, int val) {
    if (numsSize == 0) {
        return 0;
    }
    int left = 0, right = numsSize - 1;
    while (left < right) {
        if (nums[left] == val) {
            nums[left] = nums[right];
            right--;
            numsSize--;
        } else {
            left++;
        }
    }
    if (nums[left] == val) {
        numsSize--;
    }
    return numsSize;
}

int main() {
    int nums[] = {4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 5;
    removeElement(nums, numsSize, val);
}