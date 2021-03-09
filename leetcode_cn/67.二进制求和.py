#
# @lc app=leetcode.cn id=67 lang=python3
#
# [67] 二进制求和
#
# https://leetcode-cn.com/problems/add-binary/description/
#
# algorithms
# Easy (54.35%)
# Likes:    572
# Dislikes: 0
# Total Accepted:    152.4K
# Total Submissions: 279.9K
# Testcase Example:  '"11"\n"1"'
#
# 给你两个二进制字符串，返回它们的和（用二进制表示）。
#
# 输入为 非空 字符串且只包含数字 1 和 0。
#
#
#
# 示例 1:
#
# 输入: a = "11", b = "1"
# 输出: "100"
#
# 示例 2:
#
# 输入: a = "1010", b = "1011"
# 输出: "10101"
#
#
#
# 提示：
#
#
# 每个字符串仅由字符 '0' 或 '1' 组成。
# 1 <= a.length, b.length <= 10^4
# 字符串如果不是 "0" ，就都不含前导零。
#
#
#
# %%
from typing import List
# @lc code=start


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        c = 0
        ans = ""
        a = a[::-1]
        b = b[::-1]
        an = len(a)
        bn = len(b)
        a = a + "0" * max(0, bn - an)
        b = b + '0' * max(0, an - bn)
        for i in range(max(an, bn)):
            t = int(a[i]) + int(b[i]) + c
            if t > 1:
                t -= 2
                c = 1
            else:
                c = 0
            ans = ans + str(t)
        if c == 1:
            ans = ans + "1"
        return ans[::-1]


so = Solution()
a = "1010"
b = "1011"
print(so.addBinary(a, b))

# @lc code=end
