# %%
from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        '''
        先排序，用双重循环遍历a,b,寻找c. 由于经过排序,a<b<c.可以使用二分查找c=target-a-b
        同样是因为排序后a<b<c,所以可以使用剪枝.
        剪枝原则:
        1. 如果a+b>=target-b  c->b后一个
        2.  待补充
        '''
        nums.sort()
        closest = sum(nums[:3])  # 初始值
        min_diff = 999999
        n = len(nums)
        for i in range(n-2):
            a = nums[i]
            for j in range(i+1, n-1):
                b = nums[j]
                if a+b >= target-b:
                    c = nums[j+1]
                else:
                    idea_c = target-a-b
                    c = self.binSearch(nums, idea_c)
                sum_ = a+b+c
                diff = abs(sum_-target)
                if diff < min_diff:
                    min_diff = diff
                    closest = sum_
        return closest

    def binSearch(self, nums, target):
        '''
        用二分查找在nums里找target,如果找到就返回target,找不到就返回最接近target的数
        注意: 二分查找到最后不一定是最接近的
        '''
        l = 0
        r = len(nums)-1
        while l < r:
            c = (l+r)//2
            cen = nums[c]
            if cen == target:
                return target
            elif cen > target:
                r = c-1
            else:
                l = c+1
        ans = list()
        ans.append(nums[r])
        # 比较自身和相邻两个中最接近target的
        ans.append(nums[l])
        if l != 0:
            ans.append(nums[l-1])
        if r != len(nums)-1:
            ans.append(nums[r+1])
        # print(ans)
        # ans中最多有4个数,返回其中最接近target的
        min_diff = 999999
        ans_ = ans[0]
        for x in ans:
            if abs(x-target) < min_diff:
                ans_ = x
                min_diff = abs(x-target)
        return ans_


so = Solution()
nums = [-1, 2, 1, -4]
target = 1
print(so.threeSumClosest(nums, target))

# %%
x = [1, 2, 3, 4, 5]
print(sum(x[:3]))
