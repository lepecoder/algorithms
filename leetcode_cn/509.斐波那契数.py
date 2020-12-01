#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#
# https://leetcode-cn.com/problems/fibonacci-number/description/
#
# algorithms
# Easy (66.13%)
# Likes:    177
# Dislikes: 0
# Total Accepted:    92.9K
# Total Submissions: 140.5K
# Testcase Example:  '2'
#
# 斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
#
# F(0) = 0,   F(1) = 1
# F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
#
#
# 给定 N，计算 F(N)。
#
#
#
# 示例 1：
#
# 输入：2
# 输出：1
# 解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
#
#
# 示例 2：
#
# 输入：3
# 输出：2
# 解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
#
#
# 示例 3：
#
# 输入：4
# 输出：3
# 解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
#
#
#
#
# 提示：
#
#
# 0 ≤ N ≤ 30
#
#
#
# %%
class Solution:
    def fib(self, N: int) -> int:
        if N < 2:
            return N
        return self.fib(N-1)+self.fib(N-2)

# %%


class Solution:
    """
    带记忆字典
    """

    def __init__(self) -> None:
        self.memo = [-1] * 31

    def fib(self, N: int) -> int:
        if N < 2:
            return N
        if self.memo[N] == -1:
            self.memo[N] = self.fib(N-1)+self.fib(N-2)
        return self.memo[N]
# %%
# @lc code=start


class Solution:
    """
    记忆字典仍然是自顶向下的计算，而动态规划一般使用自底向上的计算，
    以迭代代替递归。
    """

    def fib(self, N: int) -> int:
        if N < 2:
            return N
        a, b = 0, 1
        while N:
            a, b = b, a+b
            N -= 1
        return a


# @lc code=end
so = Solution()
print(so.fib(4))
