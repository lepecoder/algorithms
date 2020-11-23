# %%
from typing import List


class Solution:

    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        citations = citations[::-1]
        n = len(citations)
        i = 0
        while i < n and citations[i] > i:
            i += 1
        return i


so = Solution()
print(so.hIndex([0, 1, 3, 5, 6]))
