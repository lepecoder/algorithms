# %%
from typing import List
import copy


class Solution:
    def trap(self, height: List[int]) -> int:
        # 直方图水量
        # 对于每一个位置，它的水量最大是左侧最大和右侧最大中的最小值
        ans = copy.copy(height)
        for i in range(1, len(height) - 1):
            max_l = max(height[0:i])
            max_r = max(height[i + 1:])
            ans[i] = max(ans[i], min(max_l, max_r))
        return sum(ans) - sum(height)


so = Solution()
ans = so.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])
print(ans)

# %%
a = [1, 2, 3, 4, 5]
print(a[1:])
