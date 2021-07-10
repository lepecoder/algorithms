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
    ListNode *partition(ListNode *head, int x) {
        ListNode *h_left = new ListNode();
        ListNode *h_right = new ListNode();
        ListNode *cur_left = h_left;
        ListNode *cur_right = h_right;
        ListNode *h = head;
        while (h != nullptr) {
            if (h->val < x) {
                cur_left->next = h;
                cur_left = cur_left->next;
            } else {
                cur_right->next = h;
                cur_right = cur_right->next;
            }
            h = h->next;
        }
        cur_left->next = h_right->next;
        cur_right->next = nullptr;
        return h_left->next;
    }
};
