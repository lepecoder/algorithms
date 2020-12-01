#
# @lc app=leetcode.cn id=767 lang=python3
#
# [767] 重构字符串
#
# https://leetcode-cn.com/problems/reorganize-string/description/
#
# algorithms
# Medium (46.07%)
# Likes:    194
# Dislikes: 0
# Total Accepted:    20.5K
# Total Submissions: 44.6K
# Testcase Example:  '"aab"'
#
# 给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
#
# 若可行，输出任意可行的结果。若不可行，返回空字符串。
#
# 示例 1:
#
#
# 输入: S = "aab"
# 输出: "aba"
#
#
# 示例 2:
#
#
# 输入: S = "aaab"
# 输出: ""
#
#
# 注意:
#
#
# S 只包含小写字母并且长度在[1, 500]区间内。
#
#
#

# @lc code=start
# %%
from heapq import heappop
from typing import List
from collections import Counter
import heapq


class Solution:
    def reorganizeString(self, S: str) -> str:
        """
        使用大顶堆将字母按照出现的次数排序，如果有单个字母a出现超过(n+1)/2次,则剩余字母不可能插在a中间,a必有相邻.
        否则每次从堆中选择出现次数最多的两个字母排列,直到堆为空或仅剩一个字母.
        """
        if len(S) < 2:
            return S
        n = len(S)
        counts = Counter(S)
        maxCount = max(counts.items(), key=lambda x: x[1])[1]
        if maxCount > (n+1)//2:
            return ""
        queue = [(-x[1], x[0]) for x in counts.items()]
        heapq.heapify(queue)
        ans = list()
        while len(queue) > 1:
            _, l1 = heapq.heappop(queue)
            _, l2 = heapq.heappop(queue)
            ans.extend([l1, l2])
            counts[l1] -= 1
            counts[l2] -= 1
            if counts[l1] > 0:
                heapq.heappush(queue, (-counts[l1], l1))
            if counts[l2] > 0:
                heapq.heappush(queue, (-counts[l2], l2))
        if queue:
            ans.append(queue[0][1])
        return "".join(ans)


# @lc code=end
