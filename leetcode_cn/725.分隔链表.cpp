/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
#define ll long long
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int n = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            n++;
        }
        int len = n / k, remain = n % k;
        cur = head;
        vector<ListNode *> res(k, nullptr);
        for (int i = 0; i < k && cur; i++) {
            res[i] = cur;
            int size = len + (i < remain ? 1 : 0);
            for (int j = 1; j < size; j++) { cur = cur->next; }
            ListNode *next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}