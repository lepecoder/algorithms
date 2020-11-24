# %%
from typing import List


class Solution:
    def isValid(self, s: str) -> bool:
        stack_ = list()
        for x in s:
            if len(stack_) == 0:
                if x != 'a':
                    return False
            if x == 'a':
                stack_.append(x)
            elif x == 'b':
                if stack_[-1] == 'a':
                    stack_.append(x)
                else:
                    return False
            elif x == 'c':
                if stack_[-1] == 'b':
                    stack_.pop()
                    stack_.pop()
                else:
                    return False
            else:
                return False
        return len(stack_) == 0


# %%
s = "123"
print(s[1:])
