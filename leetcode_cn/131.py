# %%
from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPalindrome(s):
            i = 0
            j = len(s)-1
            while i < j:
                if s[i] != s[j]:
                    return False
                i += 1
                j -= 1
            return True
        ans = list()

        def backtrack(path, s) -> List[str]:
            if len(s) == 0:
                ans.append(path)
                return
            for i in range(1, len(s)+1):
                if isPalindrome(s[:i]):
                    backtrack(path+[s[:i]], s[i:])
        backtrack([], s)
        return ans


so = Solution()
print(so.partition(""))


# %%
s = "123456"
print(s[6:])
