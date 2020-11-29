# %%
from typing import List


class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        n = len(A)
        for i in range(n-1):
            if i % 2 != A[i] % 2:
                for j in range(i+1, n):
                    if i % 2 == A[j] % 2 and j % 2 != A[j] % 2:
                        A[i], A[j] = A[j], A[i]
                        break
        return A


so = Solution()
print(so.sortArrayByParityII([648, 831, 560, 986, 192, 424, 997, 829, 897, 843]))
