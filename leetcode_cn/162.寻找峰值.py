#
# @lc app=leetcode.cn id=162 lang=python3
#
# [162] 寻找峰值
#
# https://leetcode-cn.com/problems/find-peak-element/description/
#
# algorithms
# Medium (48.02%)
# Likes:    348
# Dislikes: 0
# Total Accepted:    70.6K
# Total Submissions: 146.7K
# Testcase Example:  '[1,2,3,1]'
#
# 峰值元素是指其值大于左右相邻值的元素。
#
# 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
#
# 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
#
# 你可以假设 nums[-1] = nums[n] = -∞。
#
# 示例 1:
#
# 输入: nums = [1,2,3,1]
# 输出: 2
# 解释: 3 是峰值元素，你的函数应该返回其索引 2。
#
# 示例 2:
#
# 输入: nums = [1,2,1,3,5,6,4]
# 输出: 1 或 5
# 解释: 你的函数可以返回索引 1，其峰值元素为 2；
# 或者返回索引 5， 其峰值元素为 6。
#
#
# 说明:
#
# 你的解法应该是 O(logN) 时间复杂度的。
#
#
# %%
from typing import List
# @lc code=start


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        """
        由于nums[-1] = nums[n] = -inf，所以对于一个递增序列，最后一个元素就是峰值
        对于一个递减序列，第一个元素就是峰值。
        如此一来，使用二分查找，对于中间元素，如果大于右侧，那么左半边可能是一个递减，搜索 左半边，
        如果中间元素小于右侧，那么右半边可能是一个递增的，搜索右半边。
        """
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            # print("%d -- %d -- %d"%(l,mid,r))
            if nums[mid] > nums[mid + 1]:
                r = mid
            else:
                l = mid + 1
        return l


so = Solution()
nums = [3, 1]
print(so.findPeakElement(nums))

# @lc code=end
