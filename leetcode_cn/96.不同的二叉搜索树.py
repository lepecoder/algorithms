#
# @lc app=leetcode.cn id=96 lang=python3
#
# [96] 不同的二叉搜索树
#
# https://leetcode-cn.com/problems/unique-binary-search-trees/description/
#
# algorithms
# Medium (69.34%)
# Likes:    1047
# Dislikes: 0
# Total Accepted:    108.9K
# Total Submissions: 157.1K
# Testcase Example:  '3'
#
# 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
#
# 示例:
#
# 输入: 3
# 输出: 5
# 解释:
# 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
#
# ⁠  1         3     3      2      1
# ⁠   \       /     /      / \      \
# ⁠    3     2     1      1   3      2
# ⁠   /     /       \                 \
# ⁠  2     1         2                 3
#
#
# %%
# @lc code=start
class Solution:
    def numTrees(self, n: int) -> int:
        # f(0) = 1
        # f(1) = 1
        # f(2) = 2
        # f(3) = f(0)*f(2)+f(1)*f(1)+f(2)*f(0) = 5
        ans = [1, 1, 2, 5]
        k = 4
        while k <= n:
            t = 0
            for i in range(k):
                t += ans[i] * ans[k - 1 - i]
            ans.append(t)
            k += 1
        return ans[n]


so = Solution()
print(so.numTrees(3))

# @lc code=end
