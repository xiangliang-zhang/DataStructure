from typing import List

# 判断是否为有效的数独， 行/列/九宫格

# 暴力
class Solution:

    def check_row_column(self, board, i, j):
        flag = True
        count = 0
        for index in range(0, 9):
            if board[i][index] == board[i][j]:
                count += 1
        for index in range(0, 9):
            if board[index][j] == board[i][j]:
                count += 1
        if count != 2:
            flag = False
        return flag

    def check_square(self, board, i, j):
        flag = True
        store = []
        for index_x in range(i // 3 * 3, i // 3 * 3 + 3):
            for index_y in range(j // 3 * 3, j // 3 * 3 + 3):
                if board[index_x][index_y].isdigit():
                    if board[index_x][index_y] not in store:
                        store.append(board[index_x][index_y])
                    else:
                        flag = False
                        return flag
        return flag

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        flag = True
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j].isdigit():
                    if self.check_row_column(board, i, j) and self.check_square(board, i, j):
                        flag = True
                    else:
                        flag = False
                        return flag

        return flag


s = Solution()
board = [[".", ".", ".", ".", "5", ".", ".", "1", "."],
         [".", "4", ".", "3", ".", ".", ".", ".", "."],
         [".", ".", ".", ".", ".", "3", ".", ".", "1"],
         ["8", ".", ".", ".", ".", ".", ".", "2", "."],
         [".", ".", "2", ".", "7", ".", ".", ".", "."],
         [".", "1", "5", ".", ".", ".", ".", ".", "."],
         [".", ".", ".", ".", ".", "2", ".", ".", "."],
         [".", "2", ".", "9", ".", ".", ".", ".", "."],
         [".", ".", "4", ".", ".", ".", ".", ".", "."]]
print(s.isValidSudoku(board))
