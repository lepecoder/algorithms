#
# @lc app=leetcode.cn id=105 lang=python3
#
# [105] 从前序与中序遍历序列构造二叉树
#
# https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
#
# algorithms
# Medium (69.32%)
# Likes:    924
# Dislikes: 0
# Total Accepted:    164.4K
# Total Submissions: 237.1K
# Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
#
# 根据一棵树的前序遍历与中序遍历构造二叉树。
#
# 注意:
# 你可以假设树中没有重复的元素。
#
# 例如，给出
#
# 前序遍历 preorder = [3,9,20,15,7]
# 中序遍历 inorder = [9,3,15,20,7]
#
# 返回如下的二叉树：
#
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
#
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# %%
from typing import List


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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return None
        root = TreeNode(preorder[0])
        idx = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:idx + 1], inorder[:idx])
        root.right = self.buildTree(preorder[idx + 1:], inorder[idx + 1:])
        return root


so = Solution()


# @lc code=end

# %%
x = [1, 2, 3, 4]
print(x.index(2))
