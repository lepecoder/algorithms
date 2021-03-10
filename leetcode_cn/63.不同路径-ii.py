#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#
# https://leetcode-cn.com/problems/unique-paths-ii/description/
#
# algorithms
# Medium (37.22%)
# Likes:    507
# Dislikes: 0
# Total Accepted:    126.1K
# Total Submissions: 334.1K
# Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
#
# 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
#
# 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
#
# 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
#
#
#
# 网格中的障碍物和空位置分别用 1 和 0 来表示。
#
#
#
# 示例 1：
#
#
# 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
# 输出：2
# 解释：
# 3x3 网格的正中间有一个障碍物。
# 从左上角到右下角一共有 2 条不同的路径：
# 1. 向右 -> 向右 -> 向下 -> 向下
# 2. 向下 -> 向下 -> 向右 -> 向右
#
#
# 示例 2：
#
#
# 输入：obstacleGrid = [[0,1],[0,0]]
# 输出：1
#
#
#
#
# 提示：
#
#
# m == obstacleGrid.length
# n == obstacleGrid[i].length
# 1
# obstacleGrid[i][j] 为 0 或 1
#
#
#
# %%
from typing import List
# @lc code=start


class Solution:

    dp = []

    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # 从左上角到右下角，用动态规划的方法，
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        global dp
        dp = [[-1] * n for _ in range(m)]
        return self.f(obstacleGrid, m - 1, n - 1)

    def f(self, obstacleGrid, i, j):
        if i < 0 or j < 0:
            return 0
        elif dp[i][j] != -1:
            return dp[i][j]
        if obstacleGrid[i][j] == 1:
            dp[i][j] = 0
            # return 0
        elif i == 0 and j == 0:
            dp[i][j] = 1
            # return 1
        else:
            dp[i][j] = self.f(obstacleGrid, i - 1, j) + self.f(obstacleGrid, i, j - 1)
        return dp[i][j]


so = Solution()
obs = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
print(so.uniquePathsWithObstacles(obs))
