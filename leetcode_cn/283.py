# %%
from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        ans = 0  # 已经移动的0

        def _move(k: int) -> None:
            # 将第k个位置的元素移动到n-ans-1
            for i in range(k, n-1-ans):
                nums[i], nums[i+1] = nums[i+1], nums[i]

        i = 0
        while i < n-ans:
            if nums[i] == 0:
                _move(i)
                ans += 1
            else:
                i += 1


so = Solution()
nums = [0, 0, 0, 0, 0]
so.moveZeroes(nums)
print(nums)
