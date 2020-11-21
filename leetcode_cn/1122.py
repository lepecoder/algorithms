# %%
from typing import List


class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        m = dict()
        ans_ = []
        ans = []
        for i in arr2:
            m[i] = 0
        for x in arr1:
            if x in m:
                m[x] += 1
            else:
                ans_.append(x)
        for k, v in m.items():
            for _ in range(v):
                ans.append(k)
        ans_.sort()
        return ans+ans_


so = Solution()
arr1 = []
arr2 = []
ans = so.relativeSortArray(arr1, arr2)
print(ans)
