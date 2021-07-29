/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
  public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
  public:
    Node *res;
    void dfs(Node *r, Node *h) {
        if (h == nullptr) return;
        Node *hh = new Node();
        hh->val = h->val;
        r->next = hh;
        hh->prev = r;
        dfs(hh, h->child);
        // 之前有把child连接上，现在要找到r的最后一个节点
        while (hh->next) hh = hh->next;
        dfs(hh, h->next);
    }
    Node *flatten(Node *head) {
        res = new Node();
        res->val = -1;
        dfs(res, head);
        if (res->next) res->next->prev = nullptr;
        return res->next;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}