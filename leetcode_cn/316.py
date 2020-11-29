# %%
from typing import List
from collections import Counter


class Solution:

    def removeDuplicateLetters(self, s: str) -> str:
        c = Counter(s)
        stack_ = list()
        for x in s:
            if x not in stack_:  # x不在栈中,入栈
                while len(stack_) > 0 and c[stack_[-1]] > 0 and stack_[-1] >= x:
                    stack_.pop()
                    # c[t] -= 1
                stack_.append(x)
            c[x] -= 1

        return "".join(stack_)


so = Solution()
print(so.removeDuplicateLetters('cbacdcbc'))

# %%
a = 'a'
b = 'b'
print(a < b)
