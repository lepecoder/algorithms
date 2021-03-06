#
# @lc app=leetcode.cn id=58 lang=python3
#
# [58] 最后一个单词的长度
#
# https://leetcode-cn.com/problems/length-of-last-word/description/
#
# algorithms
# Easy (33.95%)
# Likes:    285
# Dislikes: 0
# Total Accepted:    162.2K
# Total Submissions: 473.9K
# Testcase Example:  '"Hello World"'
#
# 给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。如果不存在最后一个单词，请返回 0 。
#
# 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
#
#
#
# 示例 1：
#
#
# 输入：s = "Hello World"
# 输出：5
#
#
# 示例 2：
#
#
# 输入：s = " "
# 输出：0
#
#
#
#
# 提示：
#
#
# 1
# s 仅有英文字母和空格 ' ' 组成
#
#
#
# %%
# @lc code=start


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        t = s[::-1]
        idx = t.find(' ')
        if idx == -1:
            return len(s)
        return idx


so = Solution()
s = 'alwkdjawlkjdlas'
print(so.lengthOfLastWord(s))
# @lc code=end
