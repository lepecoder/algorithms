# %%
from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        ans = digits
        b = 0
        n = len(digits)
        digits[-1] += 1
        for i in range(n - 1, -1, -1):
            digits[i] += b
            if digits[i] >= 10:
                b = 1
                digits[i] -= 10
            else:
                b = 0
                break
        if b == 1:
            digits.insert(0, 1)
        return digits


so = Solution()
di = [1, 0, 9]
print(so.plusOne(di))
