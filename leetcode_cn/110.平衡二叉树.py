#
# @lc app=leetcode.cn id=110 lang=python3
#
# [110] 平衡二叉树
#
# https://leetcode-cn.com/problems/balanced-binary-tree/description/
#
# algorithms
# Easy (54.94%)
# Likes:    622
# Dislikes: 0
# Total Accepted:    180.3K
# Total Submissions: 325.8K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# 给定一个二叉树，判断它是否是高度平衡的二叉树。
#
# 本题中，一棵高度平衡二叉树定义为：
#
#
# 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
#
#
#
#
# 示例 1：
#
#
# 输入：root = [3,9,20,null,null,15,7]
# 输出：true
#
#
# 示例 2：
#
#
# 输入：root = [1,2,2,3,3,null,null,4,4]
# 输出：false
#
#
# 示例 3：
#
#
# 输入：root = []
# 输出：true
#
#
#
#
# 提示：
#
#
# 树中的节点数在范围 [0, 5000] 内
# -10^4
#
#
#

# %%
from typing import List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def stringToTree(s: str) -> TreeNode:
    if s == '[]':
        return None
    s = s[1:-1]
    l = [x.strip() for x in s.split(',')]
    for i in range(len(l)):
        if l[i] != 'null':
            l[i] = int(l[i])
    ans = TreeNode(l[0])
    layer: deque[TreeNode] = deque([ans])
    i, n = 1, len(l)
    while i < n:
        t_layer: deque[TreeNode] = deque()
        while layer:
            node = layer.pop()
            if l[i] != 'null':
                node.left = TreeNode(l[i])
                t_layer.append(node.left)
            i += 1
            if i >= n:
                break
            if l[i] != 'null':
                node.right = TreeNode(l[i])
                t_layer.append(node.right)
            i += 1
            if i >= n:
                break
        layer = t_layer
    return ans


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # 计算二叉树的高度
    def getH(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return 1 + max(self.getH(root.left), self.getH(root.right))

    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        leftH = self.getH(root.left)
        rightH = self.getH(root.right)
        if abs(leftH - rightH) > 1:
            return False
        return True and self.isBalanced(root.left) and self.isBalanced(root.right)


so = Solution()
root = '[]'
root = stringToTree(root)
ans = so.isBalanced(root)
print(ans)

# @lc code=end
