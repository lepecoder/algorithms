# %%
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        '''
        先找到旋转点,然后分别在两边用二分搜索
        '''
        n = len(nums)
        a, b = 0, n-1
        while a < b-1:
            c = (a+b)//2
            if nums[c] < nums[a]:  # 旋转点就在l和c之间
                b = c
            else:
                a = c
        if target >= nums[0]:
            l, r = 0, a
        else:
            l, r = b, n-1
        while l <= r:
            c = (l+r)//2
            if nums[c] == target:
                return c
            elif nums[c] < target:
                l = c+1
            else:
                r = c-1
        if l == n or nums[l] != target:
            return -1
        else:
            return l


so = Solution()
nums = [4, 5, 6, 7, 0, 1, 2]
target = 3
print(so.search(nums, target))

# %%
