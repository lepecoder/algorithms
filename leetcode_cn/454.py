# %%
from typing import List


class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        abd = dict()
        ans = 0
        for a in A:
            for b in B:
                t = a+b
                abd[t] = abd.get(t, 0) + 1
        for c in C:
            for d in D:
                t = c+d
                ans += abd.get(-t, 0)
        return ans


so = Solution()
a = [1, 2]
b = [-2, -1]
c = [-1, 2]
d = [0, 2]
print(so.fourSumCount(a, b, c, d))

# %%
d = dict()
d['a'] = 123
print(type(d))
print(d)
print(d.get('a'))
