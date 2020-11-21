# %%
from typing import List


class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        ans = False
        K -= 1
        N -= 1
        for _ in range(N):
            if K % 2 == 1:
                ans = ~ans
            K = K//2
        return 1 if ans else 0


so = Solution()

print(so.kthGrammar(4, 5))


# %%
x = [1, 2, 3]
print(x[::-1])
