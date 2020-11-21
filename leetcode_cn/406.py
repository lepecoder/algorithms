# %%
from typing import List


class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda x: (x[0], -x[1]))
        n = len(people)
        ans = [[] for _ in range(n)]
        for p in people:
            position = p[1] + 1
            for i in range(n):
                if not ans[i]:
                    position -= 1
                    if position == 0:
                        ans[i] = p
                        break
        return ans


# %%
x = [[1]*3]
print(x)
