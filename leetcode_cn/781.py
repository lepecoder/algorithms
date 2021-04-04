from typing import List
from math import ceil


class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        dic = dict()
        for x in answers:
            dic[x + 1] = dic.get(x + 1, 0) + 1
        print(dic)
        ans = 0
        for key, val in dic.items():
            ans += ceil(val / key) * key
        return ans


so = Solution()
answ = [10, 10, 10]
ans = so.numRabbits(answ)
print(ans)
