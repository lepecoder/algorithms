#
# @lc app=leetcode.cn id=227 lang=python3
#
# [227] 基本计算器 II
#
# https://leetcode-cn.com/problems/basic-calculator-ii/description/
#
# algorithms
# Medium (39.04%)
# Likes:    288
# Dislikes: 0
# Total Accepted:    39.6K
# Total Submissions: 97.7K
# Testcase Example:  '"3+2*2"'
#
# 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
#
# 整数除法仅保留整数部分。
#
#
#
#
#
# 示例 1：
#
#
# 输入：s = "3+2*2"
# 输出：7
#
#
# 示例 2：
#
#
# 输入：s = " 3/2 "
# 输出：1
#
#
# 示例 3：
#
#
# 输入：s = " 3+5 / 2 "
# 输出：5
#
#
#
#
# 提示：
#
#
# 1
# s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
# s 表示一个 有效表达式
# 表达式中的所有整数都是非负整数，且在范围 [0, 2^31 - 1] 内
# 题目数据保证答案是一个 32-bit 整数
#
#
#
#
#
# %%
from math import floor, ceil
# @lc code=start


class Solution:
    def getOne(self, s: str):
        # 返回 操作数或是操作符 和 剩余字符串
        ops = ['+', '-', '*', '/']
        n = len(s)
        if s[0] in ops:  # 返回操作符
            return s[0], s[1:]

        for i in range(n):
            if s[i] in ops:  # 返回操作数
                return int(s[:i]), s[i:]
        return int(s), ''

    def calculate(self, s: str) -> int:
        # 去除表达式中的空格
        s = s.replace(' ', '')
        pre_op = '+'
        stack = []
        while s != '':
            data, s = self.getOne(s)
            if isinstance(data, int):
                if pre_op == '+':
                    stack.append(data)
                elif pre_op == '-':
                    stack.append(-data)
                elif pre_op == '*':
                    a = stack.pop()
                    c = a * data
                    stack.append(c)
                elif pre_op == '/':
                    a = stack.pop()
                    c = a / data
                    c = floor(c) if c > 0 else ceil(c)
                    stack.append(c)
            else:
                pre_op = data
        return sum(stack)


so = Solution()
print(so.calculate("1*2-3/4+5*6-7*8"))
# @lc code=end
