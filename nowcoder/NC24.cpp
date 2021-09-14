#include <bits/stdc++.h>
using namespace std;
#define ll long long
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write code here
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while (head != nullptr && head->next != nullptr) {
            if (head->val != head->next->val) {
                ListNode *t = new ListNode(head->val);
                p->next = t;
                p = t;
            } else {
                int x = head->val;
                while (head != nullptr && head->val == x) head = head->next;
                ListNode *t = new ListNode(head->val);
                p->next = t;
                p = t;
            }
            head = head->next;
        }
        if (head) {
            ListNode *t = new ListNode(head->val);
            p->next = t;
            p = t;
        }
        p->next = nullptr;
        if (head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(head->val + 1, head);
        // int pre = dummy->val;
        ListNode *pre = dummy;
        ListNode *p = head;
        while (p) {
            if (p->next == nullptr || p->val == p->next->val) {
                pre->next = p;
                pre = p;
            } else {
                // 滑动到下一个和p->val值不同的节点
                int x = p->val;
                while (p->val == x) p = p->next;
                pre->next = p;
                pre = p;
            }
            p = p->next;
        }
        return dummy->next;
    }
};
