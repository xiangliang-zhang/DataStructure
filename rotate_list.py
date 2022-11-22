# 数组右转, 数组翻转
from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if k > len(nums):
            k = k % len(nums)
        t = len(nums) - k
        nums[:] = (nums[:t][::-1] + nums[t:][::-1])[::-1]
        print(nums)


nums = [1, 2]
k = 3
s = Solution()
s.rotate(nums, k)
