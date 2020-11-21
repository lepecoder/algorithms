# %%
from typing import List


class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        ans = [[x, y] for x in range(R) for y in range(C)]
        ans.sort(key=lambda x: abs(x[0]-r0)+abs(x[1]-c0))
        return ans


so = Solution()
print(so.allCellsDistOrder(2, 3, 1, 2))
