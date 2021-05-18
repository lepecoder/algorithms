
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h1 = headA, *h2 = headB;
        if (!h1 || !h2) return nullptr;
        bool b1 = false; // 切换标志位，false表示还没有切换到另一个链表
        while (h1 != h2) {
            if (h1->next) {
                h1 = h1->next;
            } else if (!b1) {
                b1 = true;
                h1 = headB;
            } else {
                return nullptr;
            }
            if (h2->next) {
                h2 = h2->next;
            } else {
                h2 = headA;
            }
            // if (h1->next == nullptr || h2->next == nullptr) return nullptr;
            // if (!b1 && h1->next == nullptr) return nullptr;
        }
        return h1;
    }
};