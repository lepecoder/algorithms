# %%
from typing import List


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        set1 = set(nums1)
        set2 = set(nums2)
        ans = set1 & set2
        return list(ans)


so = Solution()
print(so.intersection([1, 2, 2, 1], [2, 2]))
