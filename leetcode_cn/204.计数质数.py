#
# @lc app=leetcode.cn id=204 lang=python3
#
# [204] 计数质数
#
# https://leetcode-cn.com/problems/count-primes/description/
#
# algorithms
# Easy (35.72%)
# Likes:    522
# Dislikes: 0
# Total Accepted:    96.2K
# Total Submissions: 262.6K
# Testcase Example:  '10'
#
# 统计所有小于非负整数 n 的质数的数量。
#
#
#
# 示例 1：
#
# 输入：n = 10
# 输出：4
# 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
#
#
# 示例 2：
#
# 输入：n = 0
# 输出：0
#
#
# 示例 3：
#
# 输入：n = 1
# 输出：0
#
#
#
#
# 提示：
#
#
# 0 <= n <= 5 * 10^6
#
#
#

# @lc code=start
# %%
class Solution:
    def countPrimes(self, n: int) -> int:
        """
        筛素数法
        众所周知,素数的倍数一定不是素数,我们可以用一个布尔数组保存信息,
        一开始假设所有数都是素数,从第一个素数2开始,将它的倍数标记为false,
        然后找到下一个素数3,将它的倍数也标记为false,之后继续找素数并筛去它的倍数
        """
        if n < 2:
            return 0
        res = [1]*n
        for i in range(2, int(n**0.5)+1):
            # if res[i] == False:
            #     continue
            # t = 2
            # while i*t < n:
            #     res[i*t] = False
            #     t+=1
            if res[i]:
                # res[i*i:n:i] = [0]*((n-1-i*i)//i+1)
                for j in range(i*i, n, i):
                    res[j] = 0
        return sum(res) - 2


so = Solution()
print(so.countPrimes(10))
# @lc code=end
