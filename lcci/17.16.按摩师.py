"""
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，
因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
---
输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4
"""
# %%
from typing import List


class Solution:
    def massage(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            a = dp[i - 1]  # 不接受第i个
            if i >= 2:
                b = nums[i - 1] + dp[i - 2]
            else:
                b = nums[i - 1]
            dp[i] = max(a, b)
        return(dp[-1])


so = Solution()
nums = [1, 3, 3]
print(so.massage(nums))
