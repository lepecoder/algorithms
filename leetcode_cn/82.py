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
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        ans = ListNode(-1, None)
        h = head
        tail = ans
        while h:
            if h.next and h.val == h.next.val:  # 存在重复元素
                # 找到重复的下一个
                while h.next and h.val == h.next.val:
                    h = h.next
            else:
                t = ListNode(h.val, None)
                tail.next = t
                tail = t
            h = h.next
        return ans.next


headList = []
headNode = generate(headList)
so = Solution()
ans = so.deleteDuplicates(headNode)
ansList = show(ans)
print(ansList)
