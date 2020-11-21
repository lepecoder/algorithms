# %%
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def generate(vals: List[int]) -> ListNode:
    ans = ListNode(-1, None)
    tail = ans
    for x in vals:
        t = ListNode(x, None)
        tail.next = t
        tail = t
    return ans.next


def show(head: ListNode) -> List[int]:
    ans = list()
    h = head
    while h:
        ans.append(h.val)
        h = h.next
    return ans


class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        """
        用指针p0遍历m n位置, 每次将p0后的节点插入到开头m的位置,p0后移
        """
        dummyNode = ListNode(-1, head)
        i = 1
        left = dummyNode
        while i < m:
            i += 1
            left = left.next
        p = left.next
        while i < n:
            i += 1
            t = p.next
            p.next = t.next
            t.next = left.next
            left.next = t
        return dummyNode.next


head = [1, 2, 3, 4, 5]
head = generate(head)
so = Solution()
ans = so.reverseBetween(head, 1, 5)
ans = show(ans)
print(ans)
