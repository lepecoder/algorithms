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
        return dummy->next;
    }
};
int main() {
    //
    return 0;
}