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
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:

        # 构建前n项和到节点的字典映射
        dummyNode = ListNode(0, head)
        preSumDict = dict()
        tSum = 0
        tNode = dummyNode
        while tNode:
            tSum += tNode.val
            preSumDict[tSum] = tNode
            tNode = tNode.next

        tNode = dummyNode
        tSum = 0
        while tNode:
            tSum += tNode.val
            tNode.next = preSumDict[tSum].next
            tNode = tNode.next

        return dummyNode.next


head = []
head = generate(head)
so = Solution()
ans = so.removeZeroSumSublists(head)
ans = show(ans)
print(ans)
