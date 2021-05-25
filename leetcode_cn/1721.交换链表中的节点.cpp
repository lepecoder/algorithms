/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] 交换链表中的节点
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
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *first, *last = head;
        ListNode *cur = head;
        while (--k) { cur = cur->next; }
        first = cur;
        while (cur->next != nullptr) {
            cur = cur->next;
            last = last->next;
        }
        swap(first->val, last->val);
        return head;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}