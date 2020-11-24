# %%
from typing import List
import numpy as np


class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        h = [1 if x > 8 else -1 for x in hours]
        preSum = [0]
        for x in h:
            preSum.append(preSum[-1]+x)
        stack_ = [0]  # 单调栈存储元素索引
        for i, v in enumerate(preSum):
            if v < preSum[stack_[-1]]:
                stack_.append(i)

        ans = 0
        i = len(preSum)-1
        # 倒序扫描，求最大长度坡
        while stack_ and i > 0:
            t = stack_.pop()
            while i > t:
                if preSum[i] > preSum[t]:
                    ans = max(ans, i-t)
                    break
                i -= 1
        return ans


so = Solution()
ans = so.longestWPI([])
print(ans)
