# %%
from typing import List
# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        a = head
        b = head.next
        h1 = head
        h2 = head.next

        while True:
            if b and b.next:
                a.next = b.next
                a = a.next
            else:
                a.next = h2
                break
            if a:
                b.next = a.next
                b = b.next
        return h1
