#include <bits/stdc++.h>
using namespace std;
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
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode *reverse(ListNode *r) {
        // 翻转链表
        if (r == nullptr) return r;
        ListNode *p1 = nullptr;
        ListNode *p2 = r;
        ListNode *p3 = r->next;
        while (p2) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        return p1;
    }
    ListNode *addInList(ListNode *head1, ListNode *head2) {
        // write code here
        auto h1 = reverse(head1);
        auto h2 = reverse(head2);
        ListNode *res = new ListNode(0);
        ListNode *r = res;
        int add = 0;
        int a, b, c;
        while ((h1 && h2) || add) {
            a = 0, b = 0;
            if (h1) {
                a = h1->val;
                h1 = h1->next;
            }
            if (h2) {
                b = h2->val;
                h2 = h2->next;
            }
            // a = h1 == nullptr ? 0 : h1->val;
            // b = h2 == nullptr ? 0 : h2->val;
            c = a + b + add;
            add = c / 10;
            c = c % 10;
            ListNode *t = new ListNode(c);
            r->next = t;
            r = t;
        }
        // 此时add=0, h1 h2可能不为空
        if (h1) { r->next = h1; }
        if (h2) { r->next = h2; }
        res = reverse(res->next);
        return res;
    }
};
int main() {
    //
    return 0;
}