# %%
from typing import List


class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        n = min(10, n)
        ans = 10
        base = 9
        ev = 9
        for _ in range(1, n):
            ev *= base
            base -= 1
            ans += ev
        return ans


so = Solution()
print(so.countNumbersWithUniqueDigits(2))
