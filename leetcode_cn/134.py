# %%
from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # global n
        n = len(gas)
        idx = list(range(n))

        def check(k: int) -> int:
            # 检查此处是否满足要求
            # global n
            ans = 0
            for i in idx[k:n]+idx[0:k]:
                ans += gas[i]
                if ans >= cost[i]:
                    ans -= cost[i]
                else:
                    return i+1
            return -1

        i = 0
        while i < n:
            # for i in range(n):
            k = check(i)
            if k == -1:
                return i
            else:
                i = k

        return -1


so = Solution()
gas = [2, 3, 4]
cost = [3, 4, 3]
print(so.canCompleteCircuit(gas, cost))

# %%
x = [1]


def f():
    print(x)
    x[0] = x[0]+1


f()
print(x)
