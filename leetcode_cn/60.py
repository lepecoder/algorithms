from typing import List
from math import ceil, floor


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans = []

        def fact(n: int) -> int:
            ans = 1
            for t in range(1, n + 1):
                ans *= t
            return ans

        def backtrack(condi: List[int], k: int) -> None:
            print(condi)
            if len(condi) == 0:
                return
            t = fact(len(condi) - 1)
            # 每跳过一位，就可以跳过t个排列,下取整，
            # idx = max(ceil(k / t) - 1, 0)
            idx = k // t   # 下去整
            idx = max(idx, 0)
            ans.append(condi[idx])
            backtrack(condi[:idx] + condi[idx + 1:], k % t)

        # 要找第k个排列，也就是需要跳过k-1个
        backtrack(list(range(1, n + 1)), k - 1)
        ans = list(map(lambda x: str(x), ans))
        return ''.join(ans)


so = Solution()
print(so.getPermutation(4, 9))

# %%
# print(2 % 2)
