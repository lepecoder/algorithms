# %%
from typing import List


class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        global ans
        global res
        ans = 0
        res = ""

        def backtrack(path):
            if len(path) == n:
                global ans
                global res
                ans += 1
                if ans == k:
                    res = path
            else:
                for x in ['a', 'b', 'c']:
                    if path[-1] != x:
                        backtrack(path+x)

        backtrack('a')
        backtrack('b')
        backtrack('c')
        return res


so = Solution()
print(so.getHappyString(3, 90))


# %%
x = "123"
print(x[-1])
