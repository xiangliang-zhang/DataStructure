from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for i in range(1, numRows + 1):
            res.append([0] * i)
        for i in range(len(res)):
            for j in range(len(res[i])):
                if i == 0 or j == 0 or j == i:
                    res[i][j] = 1
                else:
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j]
        return res


a = Solution()
print(a.generate(0))
