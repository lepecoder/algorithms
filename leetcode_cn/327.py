# %%
from typing import List


class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        """
        求区间内元素的和,为了避免重复计算,可以先将数组排序,计算前n项和,那么
        preSum[j] - preSum[i] 就是(i,j]的和
        """
