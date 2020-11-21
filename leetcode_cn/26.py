# %%
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # if len(nums) == 0
        i = 0
        while i < len(nums):
            if i < len(nums)-1 and nums[i] == nums[i+1]:
                del nums[i+1]
            else:
                i += 1
        return i


so = Solution()
nums = []
x = so.removeDuplicates(nums)
print(x)
print(nums)
