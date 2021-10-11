#include <bits/stdc++.h>
using namespace std;
#define ll long long
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        bool bs = false; // swap
        while (p1 != p2) {
            if (p1->next == nullptr) {
                if (bs == true) return nullptr;
                bs = true;
                p1 = headB;
            } else {
                p1 = p1->next;
            }
            if (p2->next == nullptr) {
                p2 = headA;
            } else {
                p2 = p2->next;
            }
        }
        return p1;
    }
};
int main() {
    //
    return 0;
}