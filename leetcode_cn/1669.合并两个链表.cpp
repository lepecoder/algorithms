/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
 */

// @lc code=start
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
class Solution {
  public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        /* 删除第a到第b个节点 */
        ListNode *a_node = list1;
        ListNode *b_node = list1;
        // a_node指向a的前一个节点
        for (int i = 1; i < a; i++) { a_node = a_node->next; }
        // b_node指向第b个节点
        for (int i = 0; i <= b; i++) { b_node = b_node->next; }
        ListNode *list2_end = list2;
        while (list2_end->next) list2_end = list2_end->next;
        a_node->next = list2;
        list2_end->next = b_node;
        return list1;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}