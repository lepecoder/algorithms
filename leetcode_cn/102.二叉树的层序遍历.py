#
# @lc app=leetcode.cn id=102 lang=python3
#
# [102] 二叉树的层序遍历
#
# https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
#
# algorithms
# Medium (64.21%)
# Likes:    801
# Dislikes: 0
# Total Accepted:    265K
# Total Submissions: 412.7K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
#
#
#
# 示例：
# 二叉树：[3,9,20,null,null,15,7],
#
#
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
#
#
# 返回其层序遍历结果：
#
#
# [
# ⁠ [3],
# ⁠ [9,20],
# ⁠ [15,7]
# ]
#
#
#
# %%
from typing import List
# @lc code=start
# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def stringToTree(s: str) -> TreeNode:
    if s == '[]':
        return None
    tree = [x.strip() for x in s[1:-1].split(',')]
    for i in range(len(tree)):
        tree[i] = int(tree[i]) if tree[i] != 'null' else None
    root = TreeNode(tree.pop(0))
    layer = [root]
    while layer and tree:
        if t := layer.pop(0):
            if x := tree.pop(0):
                t1 = TreeNode(x)
                layer.append(t1)
                t.left = t1
            else:
                t.left = None
            if x := tree.pop(0):
                t2 = TreeNode(x)
                layer.append(t2)
                t.right = t2
            else:
                t.right = None

    return root


def treeToString(root: TreeNode) -> str:
    #  树结构转字符串, 层次遍历
    if not root:
        return []
    p = [root]
    ans = []
    while p:
        if len(p) == p.count(None):
            break
        t = p.pop(0)
        if t:
            ans.append(t.val)
            p.append(t.left)
            p.append(t.right)
        else:
            ans.append(None)
    return ans


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        p = [root]  # 层次遍历队列
        q = []  # 临时层
        ans = [[root.val]]  # 遍历过的结果
        while p:
            t = p.pop(0)  # 从左pop
            if t.left is not None:
                q.append(t.left)
            if t.right:
                q.append(t.right)

            if len(p) == 0:
                p = q
                if p:
                    ans.append([x.val for x in p])
                q = []

        return ans


s = '[]'
s1 = stringToTree(s)
so = Solution()
s2 = so.levelOrder(s1)
print(s2)

# @lc code=end
