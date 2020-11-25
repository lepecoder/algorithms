# %%
from typing import List
from collections import deque
# Definition for a binary tree node.


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


class Solution_:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        # 递归算法
        ans: List[int] = list()

        def postorder(root: TreeNode) -> None:
            if not root:
                return
            postorder(root.left)
            postorder(root.right)
            ans.append(root.val)
        postorder(root)
        return ans


class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return list()
        # res: List[int] = list()
        res = deque()
        # stack_: List[TreeNode] = list()
        stack_ = deque()
        prev = None
        while root or stack_:
            while root:  # 左孩子入栈
                stack_.append(root)
                root = root.left
            root = stack_.pop()
            if not root.right or root.right == prev:
                res.append(root.val)
                prev = root
                root = None
            else:
                stack_.append(root)
                root = root.right
        return res


so = Solution()
root = "[1, null, 2, 3]"
tree = stringToTree(root)
ans = so.postorderTraversal(tree)
print(ans)


# %%
input = "[1,null,2,3]"
input = input[1:-1]
print(input)
input = input.split(',')
print(input)

b = True
for _ in range(3):
    x = 1 if b else break
    print(x)
