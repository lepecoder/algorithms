#
# @lc app=leetcode.cn id=659 lang=python3
#
# [659] 分割数组为连续子序列
#
# https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/description/
#
# algorithms
# Medium (42.87%)
# Likes:    154
# Dislikes: 0
# Total Accepted:    7.8K
# Total Submissions: 16.4K
# Testcase Example:  '[1,2,3,3,4,5]'
#
# 给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。
#
# 如果可以完成上述分割，则返回 true ；否则，返回 false 。
#
#
#
# 示例 1：
#
# 输入: [1,2,3,3,4,5]
# 输出: True
# 解释:
# 你可以分割出这样两个连续子序列 :
# 1, 2, 3
# 3, 4, 5
#
#
#
#
# 示例 2：
#
# 输入: [1,2,3,3,4,4,5,5]
# 输出: True
# 解释:
# 你可以分割出这样两个连续子序列 :
# 1, 2, 3, 4, 5
# 3, 4, 5
#
#
#
#
# 示例 3：
#
# 输入: [1,2,3,4,4,5]
# 输出: False
#
#
#
#
# 提示：
#
#
# 输入的数组长度范围为 [1, 10000]
#
#
#
#
#

# %%
from typing import List
import collections
import heapq
mp = collections.defaultdict(list)
print(mp.get(3))


# @lc code=start
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        """
        将升序数组分割成一个或多个`连续整数`的子序列,子序列可以由最后一个数字和子序列的长度唯一确定.
        那么当我们遇到一个数字x时,我们可以查找所有以x-1结尾的子序列,如果有多个就把x添加到长度最短的
        子序列,如果没有就新建一个子序列
        ---
        使用int->list的map存储以x结尾的的子序列,这里的list是一个小顶堆,存储子序列的长度,每次取出长度
        最短的序列,将x加上.
        最后如果检查map里的所有优先队列都应该>=3
        """
        mp = collections.defaultdict(list)
        for x in nums:
            queue = mp.get(x-1)
            if queue:
                prevLength = heapq.heappop(queue)
                heapq.heappush(mp[x], prevLength+1)
            else:
                heapq.heappush(mp[x], 1)
        return not any(queue and queue[0] < 3 for queue in mp.values())


so = Solution()
print(so.isPossible([1, 2, 3]))

# @lc code=end
