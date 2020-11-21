# %%
from typing import List


class Solution:
    def countAndSay(self, n: int) -> str:
        def getNext(s: str) -> str:
            ans = str()
            a = 1
            for i in range(len(s)):
                # 如何和下一个相同,a+1 不输出
                if i < len(s)-1 and s[i] == s[i+1]:
                    a += 1
                else:
                    ans = ans+str(a)+s[i]
                    a = 1
            return ans
        t = '1'

        for _ in range(n-1):
            nt = getNext(t)
            print(nt)
            t = nt
        return t


so = Solution()
print(so.countAndSay(6))

# %%
ta = "123"
print(len(ta))
print(ta)
