# %%
from typing import List
from collections import deque


class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        # sort就完了，年轻人不讲武德
        max_ans = 0
        nums.sort()
        for i in range(len(nums)-1):
            max_ans = max(max_ans, nums[i+1]-nums[i])
        return max_ans
