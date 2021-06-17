#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    ListNode *deleteNode(ListNode *head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *h = dummy;
        while (h->next) {
            if (h->next->val == val) {
                h->next = h->next->next;
                break;
            }
            h = h->next;
        }
        return dummy->next;
    }
};
int main() {
    //
    return 0;
}