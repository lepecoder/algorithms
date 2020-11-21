# %%
from typing import List
# Definition for a binary tree node.


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if root is None:
            return 0
        ans = 0
        tree = [root]
        while len(tree) > 0:
            t = tree.pop()
            if t.left is None and t.right is None:
                ans += t.val
            if t.left:
                tree.append(t.left)
                t.left.val += 10*t.val
            if t.right:
                tree.append(t.right)
                t.right.val += 10*t.val
        return ans
