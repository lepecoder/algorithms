# %%
from typing import List


class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        ans = 0

        def f(arr: List[int], pie: List[int]) -> bool:
            n = len(arr)
            m = len(pie)
            for i in range(n-m+1):
                if arr[i:i+m] == pie:
                    return True
            return False

        for x in pieces:
            if len(x) == 0:
                if x[0] in arr:
                    ans += 1
            else:
                if f(arr, x):
                    ans += len(x)
        if ans == len(arr):
            return True
        else:
            return False


arr = [15, 85]
pieces = [[85, 15]]
so = Solution()
print(so.canFormArray(arr, pieces))

# %%
x = [1, 2, 3, 4, 5]
print(x[2:5])
