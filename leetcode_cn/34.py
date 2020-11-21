# %%
from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        """
        分别查找左右边界
        """
        n = len(nums)
        a, b = 0, n
        while a < b:
            c = (a+b)//2
            if nums[c] >= target:
                b = c
            else:
                a = c+1
        if a == len(nums) or nums[a] != target:
            return [-1, -1]
        left = a
        a, b = 0, n
        while a < b:
            c = (a+b)//2
            if nums[c] > target:
                b = c
            else:
                a = c+1
        return [left, a-1]


so = Solution()
nums = [3, 3, 3, 3]
target = 3
print(so.searchRange(nums, target))
