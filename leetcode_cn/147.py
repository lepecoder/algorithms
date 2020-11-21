# %%
from typing import List


class ListNode:
    def __init__(self, x, next=None):
        self.val = x
        self.next = next


class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        """
        不更改源数据，返回新链表
        """
        if not head or not head.next:
            return head
        t = ListNode(head.val, None)
        ans = ListNode(float('-inf'), t)
        h = head.next
        while h:
            k = ans
            while k.next and k.next.val < h.val:
                k = k.next
            t = ListNode(h.val, k.next)
            h = h.next
            k.next = t
        return ans.next


# %%
x = [3, 2, 1]
print(sort(x))
