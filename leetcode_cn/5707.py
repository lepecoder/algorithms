from typing import List


class Solution:
    def backtrack(self, path, groups):
        g_path = [groups[i] for i in path]
        if sum(g_path) % self.batch == 0:
            self.ans += 1
            for i in path:
                self.bool_grousp[i] = True
        else:

    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        """
        这是一道回溯题，本质是用n个数字组成最多的k*batchSize
        可以用广度优先搜索，因为使用最少的数字可以构成最多的k*batchsize
        """
        self.ans = 0
        self.batch = batchSize
        self.groups = groups
        self.bool_groups = [False] * len(groups)


# %%
print([False] * 3)
