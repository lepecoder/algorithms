# %%
from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == val:
                del nums[i]
            else:
                i += 1
        return len(nums)


so = Solution()
nums = [2, 3, 2, 34, 2]
print(so.removeElement(nums, 2))
print(nums)
