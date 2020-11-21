# %%
from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = list()
        nums.sort()
        n = len(nums)

        def backtrack(path, k):
            ans.append(path)
            if k < n:
                backtrack(path+nums[k:k+1], k+1)
            for i in range(k+1, n):
                if nums[i] != nums[i-1]:
                    backtrack(path+nums[i:i+1], i+1)
        backtrack([], 0)
        return ans


so = Solution()
nums = [1, 2, 2, 5]
print(so.subsetsWithDup(nums))

# %%
x = [1, 3, 2]
print(x.sort())
