from typing import List


class Solution:
    def check(self, nums: List[int]) -> bool:
        # argmin
        # min_v = 101
        # min_i = 0
        # for i,v in enumerate(nums):
        #     if min_v < v
        n = len(nums)
        ans = False
        for i in range(n):
            t = nums[i]
            for j in range(1, n):
                if nums[(i + j) % n] >= t:
                    t = nums[(i + j) % n]
                    if j == n - 1:
                        ans = True
                else:
                    break
        return ans


so = Solution()
nums = [1, 1, 2, 3, 2, 1]
print(so.check(nums))
