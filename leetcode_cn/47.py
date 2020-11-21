# %%
from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = list()

        def backtrack(path: List[int], visit: List[bool]) -> None:
            if len(path) == n:
                ans.append(path)
            else:
                for i in range(n):
                    if (visit[i] == True or (i > 0 and nums[i] == nums[i-1] and visit[i-1] == False)):
                        pass
                    else:
                        visit[i] = True
                        backtrack(path+[nums[i]], visit)
                        visit[i] = False
        backtrack([], [False]*n)
        return ans


so = Solution()
print(so.permuteUnique([1, 1, 2]))

# %%
x = [1, 3, 2]
b = [False, True, True]
print(x[b])
