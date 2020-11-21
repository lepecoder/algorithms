# %%
from typing import List


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)
        if m == 0:
            return 0
        for i in range(n-m+1):
            j = 0
            while j < m:
                if haystack[i+j] != needle[j]:
                    break
                j += 1
            if j == m:
                return i
        return -1


so = Solution()
print(so.strStr('hello', 'lo'))


# %%
for i in range(3):
    print(i)
    i = -1
print(i)
