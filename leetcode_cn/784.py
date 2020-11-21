# %%
from typing import List


class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        ans = list()
        n = len(S)

        def _switch(s: str):
            if s.islower():
                return s.upper()
            else:
                return s.lower()

        def _backtrack(path: List[str], k: int):
            ans.append("".join(path))
            for i in range(k, n):
                if path[i].isalpha():
                    path[i] = _switch(path[i])
                    _backtrack(path, i+1)
                    path[i] = _switch(path[i])

        _backtrack(list(S), 0)
        return ans


so = Solution()
print(so.letterCasePermutation("3123"))

# %%
x = "awd"
print(x)
x[1] = "a"
print(x)
