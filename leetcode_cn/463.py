# %%
from typing import List


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        ans = 0
        w = len(grid)
        h = len(grid[0])
        for i in range(w):
            for j in range(h):
                if grid[i][j] == 0:
                    continue
                if i == 0 or grid[i-1][j] == 0:
                    ans += 1
                # print(i, j)
                if i == w-1 or grid[i+1][j] == 0:
                    ans += 1
                if j == 0 or grid[i][j-1] == 0:
                    ans += 1
                if j == h-1 or grid[i][j+1] == 0:
                    ans += 1
        return ans


so = Solution()
li = [[0, 0]]


print(so.islandPerimeter(li))
