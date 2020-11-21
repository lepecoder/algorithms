# %%
from typing import List


class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        """
        贪心+单调栈
        错了9次,真是服了
        """
        ans = []
        for x in num:
            while k and ans and x < ans[-1]:
                ans.pop()
                k -= 1
            ans.append(x)

        ans = ans[0:len(ans)-k]
        return "".join(ans).lstrip('0') or "0"


# %%
ans = []
print("".join(ans).lstrip('0') or "0")
