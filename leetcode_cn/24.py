# %%
from typing import List
# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dn = ListNode(-1, head)
        if head is None or head.next is None:
            return head
        h = dn
        while h and h.next and h.next.next:
            a = h
            b = h.next
            c = h.next.next
            a.next = c
            b.next = c.next
            c.next = b
            h = b
        return dn.next
