#
# @lc app=leetcode.cn id=540 lang=python3
#
# [540] 有序数组中的单一元素
#
# https://leetcode-cn.com/problems/single-element-in-a-sorted-array/description/
#
# algorithms
# Medium (59.57%)
# Likes:    174
# Dislikes: 0
# Total Accepted:    19.4K
# Total Submissions: 32.6K
# Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
#
# 给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。
#
# 示例 1:
#
#
# 输入: [1,1,2,3,3,4,4,8,8]
# 输出: 2
#
#
# 示例 2:
#
#
# 输入: [3,3,7,7,10,11,11]
# 输出: 10
#
#
# 注意: 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。
#
#
# %%
from typing import List
# @lc code=start


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            mid_left_even = (mid - left) % 2 == 0
            if nums[mid + 1] == nums[mid]:
                if mid_left_even:
                    left = mid + 2
                else:
                    right = mid - 1
            elif nums[mid - 1] == nums[mid]:
                if mid_left_even:
                    right = mid - 2
                else:
                    left = mid + 1
            else:
                return nums[mid]
        return nums[left]


so = Solution()
nums = [1, 1, 2, 3, 3, 4, 4]
print(so.singleNonDuplicate(nums))


# @lc code=end
