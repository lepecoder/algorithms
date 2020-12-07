#
# @lc app=leetcode.cn id=118 lang=python3
#
# [118] 杨辉三角
#
# https://leetcode-cn.com/problems/pascals-triangle/description/
#
# algorithms
# Easy (67.90%)
# Likes:    414
# Dislikes: 0
# Total Accepted:    132.2K
# Total Submissions: 191.4K
# Testcase Example:  '5'
#
# 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
#
#
#
# 在杨辉三角中，每个数是它左上方和右上方的数的和。
#
# 示例:
#
# 输入: 5
# 输出:
# [
# ⁠    [1],
# ⁠   [1,1],
# ⁠  [1,2,1],
# ⁠ [1,3,3,1],
# ⁠[1,4,6,4,1]
# ]
#
#

# %%
from typing import List
# @lc code=start


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans: List[List[int]] = list()
        # ans.append([0])
        for i in range(numRows):
            row = [1]*(i+1)
            for j in range(1, i):
                row[j] = ans[i-1][j-1] + ans[i-1][j]
            ans.append(row)
        return ans


so = Solution()
print(so.generate(3))
# @lc code=end
