# %%
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        链表的左半边+反转后的右半边
        利用快慢指针找到中间位置
        """
        if not head:
            return None
        p1 = p2 = head
        while p2.next and p2.next.next:
            p1 = p1.next
            p2 = p2.next.next
        # 此时p1就是中间节点, 分成前后两端
        p2 = p1.next
        p1.next = None
        p1 = head
        # 逆置后半段
        a = None
        b = p2
        while b:
            c = b.next
            b.next = a
            a, b = b, c
        p2 = a
        ans = p1
        while p2:
            t = p2
            p2 = p2.next
            t.next = p1.next
            p1.next = t
            p1 = t.next
