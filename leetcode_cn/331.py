# %%
from typing import List
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
    def isValidSerialization(self, preorder: str) -> bool:
        slots = 1
        for node in preorder.split(','):
            slots -= 1
            if slots < 0:
                return False
            if node != '#':
                slots += 2
        return slots == 0
