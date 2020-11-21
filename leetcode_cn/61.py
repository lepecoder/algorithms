# %%
from typing import List
# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        """
        倒数第k个节点作为新的头节点，原来的尾节点的next指向原来的头结点,但新的头结点要和
        之前的节点断开连接.
        p1 p2两个指针,p2先走k步,之后p1 p2同时走,当p2走到尾节点时p1走到新头结点的前一个节点
        """
        p1 = p2 = head
        if head is None or head.next is None:
            return head
        n = 1
        while k:
            k -= 1
            if p2.next:
                p2 = p2.next
                n += 1
            else:
                p2 = head
                k = k % n
        while p2.next:
            p2 = p2.next
            p1 = p1.next
        p2.next = head
        ans = p1.next
        p1.next = None
        return ans


so = Solution()
