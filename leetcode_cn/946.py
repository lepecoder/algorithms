# %%
from typing import List


class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack_ = list()
        k = 0  # poped指针
        n = len(popped)
        for x in pushed:
            while len(stack_) > 0 and k < n and stack_[-1] == popped[k]:
                stack_.pop()
                k += 1
            stack_.append(x)

        return stack_[::-1] == popped[k:]


so = Solution()
pushed = []
popped = []

print(so.validateStackSequences(pushed, popped))
