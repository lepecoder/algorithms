# %%
from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        i: int = 0
        while i < n and citations[n-1-i] > i:
            i += 1
        return i


so = Solution()
print(so.hIndex([0, 1, 3, 5, 6]))

# %%
# %%

# 二分法


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        left, right = 0, n-1
        while left <= right:
            pivot = (left)+right//2
            if citations[pivot] == n-pivot:
                return n-pivot
            elif citations[pivot] < n - pivot:
                left = pivot + 1
            else:
                right = pivot - 1

        return n - left
