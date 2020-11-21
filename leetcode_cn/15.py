# %%
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        ans = list()
        for i in range(n):
            # 剪枝，和上次不同
            if i > 0 and nums[i] == nums[i-1]:
                continue
            k = n-1
            target = -nums[i]
            for j in range(i+1, n):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                while j < k and nums[j]+nums[k] > target:
                    k -= 1
                if j == k:
                    break
                if nums[j]+nums[k] == target:
                    ans.append([nums[i], nums[j], nums[k]])
        return ans


nums = [-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4]

so = Solution()
print(so.threeSum(nums))
# %%

x = [-1, 2, 2, 1]
print(x.index(4))
