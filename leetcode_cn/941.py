# %%
from typing import List


class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        n = len(A)
        if n < 3:
            return False
        k = n-1
        while k > 0 and A[k-1] > A[k]:
            k -= 1
        if k == 0 or k == n-1:
            return False
        for i in range(k):
            if A[i] >= A[i+1]:
                return False
        return True


so = Solution()
print(so.validMountainArray([3, 2, 1]))
