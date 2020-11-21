# %%
from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []

        def backtrack(candi: List[int], idx):
            if sum(candi) == target:
                ans.append(candi)
            elif sum(candi) < target:
                for i, x in enumerate(candidates[idx:]):
                    backtrack(candi+[x], i+idx)
        backtrack([], 0)
        return ans


so = Solution()
candidates = [3]
target = 8
res = so.combinationSum(candidates, target)
print(res)

# %%
x = [1, 2, 3, 4, 5]
print(x[2:3])
