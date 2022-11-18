from typing import List  # 类型检查


class Solution(object):
    def matrixReshape(self, mat, r, c):
        """
        :type mat: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        m = len(mat)
        n = len(mat[0])
        if (m * n) != (r * c):
            return mat
        t = []
        for i in range(len(mat)):
            for j in range(len(mat[i])):
                t.append(mat[i][j])
        t_c = int(m * n / r)
        res = [[0] * c for _ in range(r)]
        index = 0
        for i in range(r):
            for j in range(t_c):
                res[i][j] = t[index]
                index += 1
        return res

    def matrixReshape_2(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(nums), len(nums[0])
        if m * n != r * c:
            return nums

        ans = [[0] * c for _ in range(r)]
        for x in range(m * n):
            ans[x // c][x % c] = nums[x // n][x % n]  # x//c 确定行 x%c 确定列

        return ans


mat = [[1, 2], [3, 4]]
a = Solution()
print(a.matrixReshape_2(mat, 1, 4))
