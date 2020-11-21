# %%
from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = list()

        def _backtrack(path, begin):
            if len(path) == k:
                ans.append(path)
            else:
                for i in range(begin, n+1):
                    _backtrack(path+[i], i+1)

        _backtrack([], 1)
        return ans


so = Solution()
print(so.combine(4, 2))
