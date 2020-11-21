# %%
from typing import List


class Solution:
    def isValid(self, s: str) -> bool:
        ans = list()
        d = {
            '(': ')',
            '{': '}',
            '[': ']'
        }
        for x in s:
            if x in ['(', '{', "["]:
                ans.append(x)
            else:
                try:
                    t = ans.pop()
                except:
                    return False
                if x != d[t]:
                    return False
        if len(ans) == 0:
            return True
        else:
            return False


so = Solution()
print(so.isValid(')[]{(})'))
# %%
a = ['2', '3']
print(a.pop())
