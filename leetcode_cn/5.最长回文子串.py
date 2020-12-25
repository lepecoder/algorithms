#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#
# https://leetcode-cn.com/problems/longest-palindromic-substring/description/
#
# algorithms
# Medium (32.55%)
# Likes:    3023
# Dislikes: 0
# Total Accepted:    440.7K
# Total Submissions: 1.4M
# Testcase Example:  '"babad"'
#
# 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
#
# 示例 1：
#
# 输入: "babad"
# 输出: "bab"
# 注意: "aba" 也是一个有效答案。
#
#
# 示例 2：
#
# 输入: "cbbd"
# 输出: "bb"
#
#
#

# @lc code=start
class Solution:
    def expand(self, l, r):
        while l >= 0 and r < self.n and self.s[l] == self.s[r]:
            l -= 1
            r += 1
        return l + 1, r - 1

    def longestPalindrome(self, s: str) -> str:
        self.s = s
        self.n = len(s)
        start, end = 0, 0
        for i in range(self.n):
            l1, r1 = self.expand(i, i)  # 奇数扩展
            l2, r2 = self.expand(i, i + 1)  # 偶数扩展
            if r1 - l1 > end - start:
                start, end = l1, r1
            if r2 - l2 > end - start:
                start, end = l2, r2
        return s[start:end + 1]
 # @lc code=end
