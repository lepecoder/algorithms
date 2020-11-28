# %%
from typing import List


class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        s_ = list()
        for x in s:
            if len(s_) == 0:
                s_.append(x)
            elif len(s_) >= k-1 and s_[-(k-1):] == [x]*(k-1):
                s_ = s_[:-(k-1)]
            else:
                s_.append(x)
        return "".join(s_)


so = Solution()
s = "aaa"
print(so.removeDuplicates(s, 3))

# %%
s = "1234567"
print(s[-3:])
print(s[:-3])
print(s[2]*3)
