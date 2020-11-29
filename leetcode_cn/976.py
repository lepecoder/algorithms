# %%
from typing import List


class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        A.sort(reverse=1)
        n = len(A)
        for i in range(n-2):
            if A[i+1]+A[i+2] > A[i]:
                return A[i]+A[i+1]+A[i+2]
        return 0


so = Solution()
print(so.largestPerimeter([3, 6, 2, 3]))
