#
# @lc app=leetcode.cn id=100 lang=python3
#
# [100] 相同的树
#
# https://leetcode-cn.com/problems/same-tree/description/
#
# algorithms
# Easy (60.39%)
# Likes:    579
# Dislikes: 0
# Total Accepted:    181.7K
# Total Submissions: 300.8K
# Testcase Example:  '[1,2,3]\n[1,2,3]'
#
# 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
#
# 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
#
#
#
# 示例 1：
#
#
# 输入：p = [1,2,3], q = [1,2,3]
# 输出：true
#
#
# 示例 2：
#
#
# 输入：p = [1,2], q = [1,null,2]
# 输出：false
#
#
# 示例 3：
#
#
# 输入：p = [1,2,1], q = [1,1,2]
# 输出：false
#
#
#
#
# 提示：
#
#
# 两棵树上的节点数目都在范围 [0, 100] 内
# -10^4
#
#
#

# @lc code=start
# Definition for a binary tree node.
# %%
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def stringToTree(s: str) -> TreeNode:
    s = s[1:-1]
    l = [x.strip() for x in s.split(',')]
    for i in range(len(l)):
        if l[i] != 'null':
            l[i] = int(l[i])
    if not l or l[0] == 'null':
        return None
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


class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p is None and q is not None or p is not None and q is None:
            return False
        if p is None and q is None:
            return True
        if p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
# @lc code=end
