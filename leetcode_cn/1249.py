# %%
from typing import List


class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack_ = list()  # 储存括号的位置,合法的会被消去
        for i, v in enumerate(s):
            if v == '(':
                stack_.append(i)
            elif v == ')':
                if len(stack_) == 0 or s[stack_[-1]] == ')':
                    stack_.append(i)
                elif s[stack_[-1]] == '(':
                    stack_.pop()
        a = set(range(len(s)))
        b = set(stack_)
        ans = [s[i] for i in a if i not in b]
        return "".join(ans)


so = Solution()
s = "h((((((((b)"
print(so.minRemoveToMakeValid(s))

# %%
a = set([1, 2])
b = set([2, 3])
print(a-b)
