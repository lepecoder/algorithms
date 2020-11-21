# %%
from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dn = ListNode(-1, head)
        stack = []
        t = dn
        while t is not None:
            stack.append(t)
            t = t.next
        while n > 0:
            stack.pop()
            n -= 1
        pre = stack[-1]
        # print(pre.val)
        pre.next = pre.next.next
        # return dn.next
        return dn.next


n5 = ListNode(5, None)
n4 = ListNode(4, n5)
n3 = ListNode(3, n4)
n2 = ListNode(2, n3)
n1 = ListNode(1, n2)

t = n1
while t:
    print(t.val)
    t = t.next
so = Solution()
t = n1
t = so.removeNthFromEnd(t, 5)


while t:
    print(t.val)
    t = t.next
