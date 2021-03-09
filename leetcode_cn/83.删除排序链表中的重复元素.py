#
# @lc app=leetcode.cn id=83 lang=python3
#
# [83] 删除排序链表中的重复元素
#
# https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
#
# algorithms
# Easy (51.75%)
# Likes:    485
# Dislikes: 0
# Total Accepted:    189.4K
# Total Submissions: 363.3K
# Testcase Example:  '[1,1,2]'
#
# 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
#
# 示例 1:
#
# 输入: 1->1->2
# 输出: 1->2
#
#
# 示例 2:
#
# 输入: 1->1->2->3->3
# 输出: 1->2->3
#
#

# @lc code=start
# Definition for singly-linked list.
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
        if head is None:
            return head
        ans = ListNode(head.val)
        p = ans
        h = head.next
        while h:
            if h.val != p.val:
                t = ListNode(h.val)
                p.next = t
                p = p.next
            h = h.next
        return ans


head = [1, 1, 2, 3, 3]
head = generate(head)

so = Solution()
ans = so.deleteDuplicates(head)
print(show(ans))
# @lc code=end
