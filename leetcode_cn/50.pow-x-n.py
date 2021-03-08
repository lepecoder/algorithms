#
# @lc app=leetcode.cn id=50 lang=python3
#
# [50] Pow(x, n)
#
# https://leetcode-cn.com/problems/powx-n/description/
#
# algorithms
# Medium (37.02%)
# Likes:    600
# Dislikes: 0
# Total Accepted:    160.9K
# Total Submissions: 431K
# Testcase Example:  '2.00000\n10'
#
# 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）。
#
#
#
# 示例 1：
#
#
# 输入：x = 2.00000, n = 10
# 输出：1024.00000
#
#
# 示例 2：
#
#
# 输入：x = 2.10000, n = 3
# 输出：9.26100
#
#
# 示例 3：
#
#
# 输入：x = 2.00000, n = -2
# 输出：0.25000
# 解释：2^-2 = 1/2^2 = 1/4 = 0.25
#
#
#
#
# 提示：
#
#
# -100.0
# -2^31 
# -10^4
#
#
#
# @lc code=start
class Solution:
    def myPow(self, x: float, n: int) -> float:
        # 快速幂
        # 将幂运算从O(N)加速到O(log_2 N)
        # 相当于二分的思想，可以用二进制实现
        b = True
        if n < 0:
            n = -n
            b = False
        ans = 1
        base = x  # 幂运算的底
        while n != 0:
            if n % 2 == 1:
                ans *= base
            base *= base  # 二进制的思想，移动一位，底也翻倍
            n //= 2
        if b:
            return ans
        else:
            return 1 / ans


so = Solution()
print(so.myPow(-3, 0))


# @lc code=end
