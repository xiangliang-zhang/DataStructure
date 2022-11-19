from typing import List

# 暴力
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row = len(matrix)
        column = len(matrix[0])
        flag_col0 = any(matrix[i][0] == 0 for i in range(row))

        record = []
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    record.append((i, j))
        for item in record:
            for t in range(0, row):
                matrix[t][item[1]] = 0
            for t in range(0, column):
                matrix[item[0]][t] = 0
        print()


matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
s = Solution()
s.setZeroes(matrix)
