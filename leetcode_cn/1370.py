# %%
from typing import List


class Solution:
    def sortString(self, s: str) -> str:
        num = [0]*26
        for ch in s:
            num[ord(ch)-97] += 1

        ret = list()
        while len(ret) < len(s):
            for i in range(26):
                if num[i]:
                    ret.append(chr(i+97))
                    num[i] -= 1
            for i in range(25, -1, -1):
                if num[i]:
                    ret.append(chr(i+97))
                    num[i] -= 1

        return "".join(ret)


so = Solution()
print(so.sortString('leetcode'))

# %%
print(ord('a'))
