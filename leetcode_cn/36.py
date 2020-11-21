# %%
from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def isSudoku(bo) -> bool:
            if type(bo[0]) == list:
                x = bo[0]+bo[1]+bo[2]
            else:
                x = bo
            n = 9 - x.count('.')
            s = set(x)
            m = (len(s)-1) if "." in s else len(s)
            return m == n
        for i in range(9):
            if not isSudoku(board[i]):
                return False
            if not isSudoku([x[i] for x in board]):
                return False
        for i in ([0, 3, 6]):
            x = [t[0:3] for t in board[i:i+3]]
            y = [t[3:6] for t in board[i:i+3]]
            z = [t[6:9] for t in board[i:i+3]]
            if not (isSudoku(x) and isSudoku(y) and isSudoku(z)):
                return False
        return True


so = Solution()
x = [
    [".", ".", "4", ".", ".", ".", "6", "3", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
    ["5", ".", ".", ".", ".", ".", ".", "9", "."],
    [".", ".", ".", "5", "6", ".", ".", ".", "."],
    ["4", ".", "3", ".", ".", ".", ".", ".", "1"],
    [".", ".", ".", "3", ".", ".", ".", ".", "."],
    [".", ".", ".", "5", ".", ".", ".", ".", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."]]

print(so.isValidSudoku(x))

# %%
x = [['1', '2', '.'],
     ['2', '3', '.']]
y = x[0]+x[1]
print(type(x[0]) == list)
# %%
b = [
    ["5", "3", ".", ".", "7", ".", ".", ".", "."],
    ["6", ".", ".", "1", "9", "5", ".", ".", "."],
    [".", "9", "8", ".", ".", ".", ".", "6", "."],
    ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
    ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
    ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
    [".", "6", ".", ".", ".", ".", "2", "8", "."],
    [".", ".", ".", "4", "1", "9", ".", ".", "5"],
    [".", ".", ".", ".", "8", ".", ".", "7", "9"]
]

i = 0
x = [t[0:3] for t in b[0:3]]
print(x)
