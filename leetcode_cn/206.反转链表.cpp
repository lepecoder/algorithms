/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// @lc code=start
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *p1 = nullptr, *p2 = head, *p3 = head->next;
        while (p2) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3 == nullptr ? nullptr : p3->next;
        }
        return p1;
    }
};
// @lc code=end

int isPrime(int n) {
    if (n <= 1) return 0; // 1不是素数
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0; // 能被整除的也不是素数
    }
    return 1;
}

int main() {
    for (int i = 2; i < 10; i++) { cout << isPrime(i) << ' '; }
    return 0;
}