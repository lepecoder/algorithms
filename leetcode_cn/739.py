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
    def dailyTemperatures(self, head: List[int]) -> List[int]:
        if not head:
            return None
        stack_ = list()  # 单调栈
        h = head
        n = len(h)
        ans = [0]*n     # 保存结果
        for i, v in enumerate(h):
            if len(stack_) == 0:
                stack_.append(i)
                continue
            while v > h[stack_[-1]]:  # 如果比栈顶元素大
                t = stack_.pop()
                ans[t] = i-t
                if len(stack_) == 0:
                    break
            stack_.append(i)
        return ans


so = Solution()
head = [73, 74, 75, 71, 69, 72, 76, 73]
ans = so.dailyTemperatures(head)
print(ans)
