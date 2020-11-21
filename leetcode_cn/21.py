# %%
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        ans = ListNode(-1, None)
        l0 = ans
        while l1 and l2:
            if l1.val < l2.val:
                l0.next = l1
                l1 = l1.next
            else:
                l0.next = l2
                l2 = l2.next
            l0 = l0.next
        if l1:
            l0.next = l1
        if l2:
            l0.next = l2
        return ans.next
