#
# @lc app=leetcode.cn id=621 lang=python3
#
# [621] 任务调度器
#
# https://leetcode-cn.com/problems/task-scheduler/description/
#
# algorithms
# Medium (51.50%)
# Likes:    447
# Dislikes: 0
# Total Accepted:    38.7K
# Total Submissions: 74.2K
# Testcase Example:  '["A","A","A","B","B","B"]\n2'
#
# 给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表。其中每个字母表示一种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1
# 个单位时间内执行完。在任何一个单位时间，CPU 可以完成一个任务，或者处于待命状态。
#
# 然而，两个 相同种类 的任务之间必须有长度为整数 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
#
# 你需要计算完成所有任务所需要的 最短时间 。
#
#
#
# 示例 1：
#
#
# 输入：tasks = ["A","A","A","B","B","B"], n = 2
# 输出：8
# 解释：A -> B -> (待命) -> A -> B -> (待命) -> A -> B
# ⁠    在本示例中，两个相同类型任务之间必须间隔长度为 n = 2 的冷却时间，而执行一个任务只需要一个单位时间，所以中间出现了（待命）状态。
#
# 示例 2：
#
#
# 输入：tasks = ["A","A","A","B","B","B"], n = 0
# 输出：6
# 解释：在这种情况下，任何大小为 6 的排列都可以满足要求，因为 n = 0
# ["A","A","A","B","B","B"]
# ["A","B","A","B","A","B"]
# ["B","B","B","A","A","A"]
# ...
# 诸如此类
#
#
# 示例 3：
#
#
# 输入：tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
# 输出：16
# 解释：一种可能的解决方案是：
# ⁠    A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> (待命) -> (待命) -> A ->
# (待命) -> (待命) -> A
#
#
#
#
# 提示：
#
#
# 1
# tasks[i] 是大写英文字母
# n 的取值范围为 [0, 100]
#
#
#
# %%
# %%
import collections
from typing import List
from collections import Counter
import math

"""错了，还没找到原因"""


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        """
        类似767.重构字符串使得相邻字符不同,相当于本题的n=1形式
        在767题里,只要最频繁出现的字符串a出现的次数少于ceil(len/2)就可以重构字符串将其它
        字符插到a的间隙，否则就不能重构，
        本题有两种情况:
        - 当最频繁的字符串a出现次数大于ceil(len/(n+1))，CPU有额外空闲，直接按照a字符串就可以计算出时间
        - 当最频繁的字符串a出现次数小于ceil(len/(n+1))，CPU不需要空闲，时间就是tasks列表的长度
        """
        counts = Counter(tasks)
        # 找出现次数第二多的
        queue = [x[1] for x in counts.items()]
        queue.sort(reverse=1)
        secondCount = queue[1] if len(queue) > 1 else 0
        maxCount = max(counts.items(), key=lambda x: x[1])[1]
        m = len(tasks)
        if maxCount <= math.ceil(m/(n+1)):  # CPU不需要空闲
            if secondCount < maxCount or n == 0:
                return m
            return m+1
        ans = (maxCount-1)*n+maxCount
        if secondCount < maxCount:
            return ans
        return ans+1


tasks = ['A', 'A', 'B', 'B']
so = Solution()
print(so.leastInterval(tasks, 2))

# @lc code=start


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        """
        官方的解法和767题类似,
        按照时间顺序给每个时间点分配任务,为了找出可以分配的任务,使用二元组
        (nextValid_i, rest_i)表示第i个任务nextValid_i最早可以执行的时间,
        rest_i表示剩余执行次数,因为我们要有限选择剩余次数最多的任务.
        遍历所有时间点,找到不在冷却时间而且剩余次数最多的任务,之后更新二元组
        (time+n+1, rest_i-1)
        time可以不顺序遍历,而是直接更新为next_valid中的最小值,直接跳过空闲状态
        """
        freq = collections.Counter(tasks)
        m = len(freq)  # 任务总数
        nextValid = [1]*m
        rest = list(freq.values())
        time = 0
        for i in range(len(tasks)):
            time += 1
            minNextValid = min(nextValid[j] for j in range(m) if rest[j] > 0)
            time = max(time, minNextValid)  # 如果minNextValid > time 表示需要空闲
            best = -1
            for j in range(m):
                if rest[j] and nextValid[j] <= time:  # 执行j任务
                    if best == -1 or rest[j] > rest[best]:
                        best = j
            nextValid[best] = time+n+1
            rest[best] -= 1
        return time


# @lc code=end
