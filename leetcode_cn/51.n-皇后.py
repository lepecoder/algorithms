#
# @lc app=leetcode.cn id=51 lang=python3
#
# [51] N 皇后
#
# https://leetcode-cn.com/problems/n-queens/description/
#
# algorithms
# Hard (73.40%)
# Likes:    772
# Dislikes: 0
# Total Accepted:    106.1K
# Total Submissions: 143.9K
# Testcase Example:  '4'
#
# n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
#
# 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
#
#
#
# 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
#
#
#
# 示例 1：
#
#
# 输入：n = 4
# 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
# 解释：如上图所示，4 皇后问题存在两个不同的解法。
#
#
# 示例 2：
#
#
# 输入：n = 1
# 输出：[["Q"]]
#
#
#
#
# 提示：
#
#
# 1
# 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
#
#
#
#
#
# %%
from typing import List
# @lc code=start


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []

        def backtrack(track):
            if len(track) == n:
                ans.append(track)
            else:
                for x in range(n):
                    b = True
                    for i, v in enumerate(track):
                        if x == v:
                            b = False
                            break
                        if abs(len(track) - i) == abs(x - v):  # 斜对角上
                            b = False
                            break
                    if b:
                        backtrack(track + [x])
        for i in range(n):
            backtrack([i])
        # return ans
        # 转化成Q和.的格式
        print(ans)
        q = []
        for i in range(len(ans)):
            a = []
            for j in ans[i]:
                t = ['.'] * n
                t[j] = 'Q'
                t = ''.join(t)
                a.append(t)
            q.append(a)
        return q


so = Solution()
print(so.solveNQueens(4))
# @lc code=end
