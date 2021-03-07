#
# @lc app=leetcode.cn id=1283 lang=python3
#
# [1283] 使结果不超过阈值的最小除数
#
# https://leetcode-cn.com/problems/find-the-smallest-divisor-given-a-threshold/description/
#
# algorithms
# Medium (39.11%)
# Likes:    38
# Dislikes: 0
# Total Accepted:    5.2K
# Total Submissions: 13.1K
# Testcase Example:  '[1,2,5,9]\n6'
#
# 给你一个整数数组 nums 和一个正整数 threshold  ，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。
#
# 请你找出能够使上述结果小于等于阈值 threshold 的除数中 最小 的那个。
#
# 每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。
#
# 题目保证一定有解。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,2,5,9], threshold = 6
# 输出：5
# 解释：如果除数为 1 ，我们可以得到和为 17 （1+2+5+9）。
# 如果除数为 4 ，我们可以得到和为 7 (1+1+2+3) 。如果除数为 5 ，和为 5 (1+1+1+2)。
#
#
# 示例 2：
#
#
# 输入：nums = [2,3,5,7,11], threshold = 11
# 输出：3
#
#
# 示例 3：
#
#
# 输入：nums = [19], threshold = 5
# 输出：4
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 5 * 10^4
# 1 <= nums[i] <= 10^6
# nums.length <= threshold <= 10^6
#
#
#
# %%
from typing import List
import math
# @lc code=start


class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def divSum(nums, div):
            ans = [math.ceil(x / div) for x in nums]
            return sum(ans)
        left = 1
        right = max(nums)
        while left < right:
            mid = (left + right) // 2
            print("%d -- %d -- %d" % (left, mid, right))
            ans = divSum(nums, mid)
            print(ans)
            if ans <= threshold:
                right = mid
            # elif ans == threshold:
                # return mid
            else:
                left = mid + 1

        return left


so = Solution()
nums = [
    81488,
    78770,
    69737,
    14847,
    36203,
    85812,
    62771,
    25584,
    40434,
    55397,
    95643,
    48474,
    63802,
    63203,
    69258,
    16397,
    62134,
    68311,
    48931,
    4317,
    488,
    76613,
    70301,
    24052,
    67069,
    8018,
    61725,
    98992,
    86206,
    54407,
    33175,
    65597,
    5215,
    11866,
    9420,
    93851,
    66858,
    78097,
    70255,
    92021,
    50353,
    91451,
    52417,
    411,
    81332,
    27928,
    51842,
    83525,
    74458,
    10995,
    18792,
    14219,
    31190,
    86907,
    412,
    45731,
    9730,
    1258,
    94589,
    84673,
    20469,
    479,
    71501,
    68751,
    18230,
    77410,
    41662,
    9005,
    72532,
    36514,
    5203,
    528,
    59746,
    45580,
    72611,
    30386,
    40609,
    30783,
    70776,
    78765,
    97187,
    19997,
    16257,
    86367,
    80891,
    43219,
    55020,
    4753,
    2785,
    70141,
    86103,
    25092,
    50595,
    73151,
    69139,
    92893,
    18011,
    94848,
    65111,
    5657]
threshold = 988
print(so.smallestDivisor(nums, threshold))


# @lc code=end

# %%
import math
nums = [1, 2, 5, 9]
a = [math.ceil(x / 2) for x in nums]
print(a)
