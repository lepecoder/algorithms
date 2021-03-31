/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    do {
      if (fast == nullptr || fast->next == nullptr)
        return false;
      fast = fast->next->next;
      slow = slow->next;
    } while (fast != slow);
    return true;
  }
};
// @lc code=end
