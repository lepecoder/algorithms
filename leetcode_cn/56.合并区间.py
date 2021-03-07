#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#
# https://leetcode-cn.com/problems/merge-intervals/description/
#
# algorithms
# Medium (43.68%)
# Likes:    822
# Dislikes: 0
# Total Accepted:    196.1K
# Total Submissions: 440.3K
# Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
#
# 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
# 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
#
#
#
# 示例 1：
#
#
# 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
# 输出：[[1,6],[8,10],[15,18]]
# 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
#
#
# 示例 2：
#
#
# 输入：intervals = [[1,4],[4,5]]
# 输出：[[1,5]]
# 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
#
#
#
# 提示：
#
#
# 1
# intervals[i].length == 2
# 0 i i
#
#
#
# %%
from typing import List
# @lc code=start


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # 先按照区间的起始点排序
        intervals.sort(key=lambda x: x[0])
        ans = [intervals[0]]
        n = len(intervals)
        for i in range(1, n):
            t = intervals[i]
            if ans[-1][1] >= t[0]:  # 有相交区域
                ans[-1][1] = max(t[1], ans[-1][1])
            else:
                ans.append(t)
        return ans

        # @lc code=end


so = Solution()
inte = [[1, 3], [3, 4]]
ans = so.merge(inte)
print(ans)
