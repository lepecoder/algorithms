# %%
from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = list()
        n = len(nums)

        def backtrack(path):
            if len(path) == n:
                ans.append(path)
            for x in nums:
                if x not in path:
                    backtrack(path+[x])
        backtrack([])
        return ans


so = Solution()
print(so.permute([1, 2, 3]))


# %%

s = set()
s.add(5)
ss = set.add(s, 2)
print(ss)
