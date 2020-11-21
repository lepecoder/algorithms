# %%
from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        idx = n-2
        while idx >= 0 and nums[idx] >= nums[idx+1]:
            idx -= 1

        if idx == -1:  # 已经是最大字典序了,改为最小字典序
            nums.sort()
            return
        # 找到比nums[idx]稍大一点的数字,和idx交换
        k = n-1
        while nums[k] <= nums[idx]:
            k -= 1
        nums[k], nums[idx] = nums[idx], nums[k]
        nums[idx+1:] = nums[:idx:-1]


nums = [1, 5, 1]
so = Solution()
so.nextPermutation(nums)
print(nums)

# %%
nums = [1, 2, 3, 4, 5]
print(nums[2:4])
print(nums[3:1:-1])
nums[2:4] = nums[3:1:-1]
print(nums)
