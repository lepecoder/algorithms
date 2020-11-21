# %%
from typing import List
from copy import deepcopy


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        """
        乍一看可以用广度优先搜索,但是不方便处理每次搜索后同一单元格字母不能被重复使用,所以还是回溯比较合适
        而且效率也不会低多少
        """
        n = len(word)
        w = len(board[0])
        h = len(board)
        visited = set()
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        def backtrack(k, i, j):
            # 在condi board里寻找word的第k个字母
            visited.add((i, j))
            result = False
            if k == n:
                return True
            else:
                for di, dj in directions:
                    newi, newj = i+di, j+dj
                    if 0 <= newi < h and 0 <= newj < w:
                        if board[newi][newj] == word[k]:
                            if (newi, newj) not in visited:
                                if backtrack(k+1, board, newi, newj):
                                    result = True
                                    break

            visited.remove((i, j))
            return result

        for i in range(h):
            for j in range(w):
                if board[i][j] == word[0]:
                    if backtrack(1, i, j):
                        return True
        return False


so = Solution()
board = [["A", "B", "C", "E"], ["S", "F", "E", "S"], ["A", "D", "E", "E"]]
print(so.exist(board, "ABCESEEEFS"))


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        def check(i: int, j: int, k: int) -> bool:
            if board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True

            visited.add((i, j))
            result = False
            for di, dj in directions:
                newi, newj = i + di, j + dj
                if 0 <= newi < len(board) and 0 <= newj < len(board[0]):
                    if (newi, newj) not in visited:
                        if check(newi, newj, k + 1):
                            result = True
                            break

            visited.remove((i, j))
            return result

        h, w = len(board), len(board[0])
        visited = set()
        for i in range(h):
            for j in range(w):
                if check(i, j, 0):
                    return True

        return False
