# %%

from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        ans = []
        for i in range(n-3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            a = nums[i]
            for j in range(i+1, n-2):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                b = nums[j]
                target_ = target-a-b
                l = n-1
                for k in range(j+1, n-1):
                    if k > j+1 and nums[k] == nums[k-1]:
                        continue
                    c = nums[k]
                    while l > k and c + nums[l] > target_:
                        l -= 1
                    if l == k:
                        break
                    if c+nums[l] == target_:
                        ans.append([a, b, c, nums[l]])
        return ans


so = Solution()
nums = [1, 0, -1, 0, -2, 2, 0]
t = 1
print(so.fourSum(nums, t))
