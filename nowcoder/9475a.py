# %%
from typing import List


class Solution:
    def Probability(self, n):
        if n > 10:
            return "0.00"
        ans = 1/(2 ** (n-1))
        s = "%.2f" % (ans)
        return s


so = Solution()
print(so.Probability(10000000000000))

# %%
ans = 0.664
s = "%.2f" % (ans)
print(s)
