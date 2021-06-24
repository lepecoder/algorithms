/*

 * @lc app=leetcode.cn id=82 lang=cpp

 *

 * [82] 删除排序链表中的重复元素 II

 */

// @lc code=start

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode() : val(0), next(nullptr) {}

 *     ListNode(int x) : val(x), next(nullptr) {}

 *     ListNode(int x, ListNode *next) : val(x), next(next) {}

 * };

 */

class Solution {

  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = ListNode();
        ListNode *cur = head;
        while (cur) {
            // judge whether cur is repeat
            if (cur->next && cur->val == cur->next->val) {
                // jumping nodes equal to cur
                ListNode *p = cur;
                while (p && p->val == cur->val) p = p->next;
                cur = p;
            }
            dummy->next = cur;
            if (cur) { cur = cur->next; }
        }
        return dummy->next;
    }
};

// @lc code=end
