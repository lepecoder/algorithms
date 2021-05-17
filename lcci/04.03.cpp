#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        vector<ListNode *> res;
        queue<TreeNode *> q;
        q.emplace(tree);
        while (!q.empty()) {
            int n = q.size();
            ListNode *dummy = new ListNode(0);
            ListNode *tail = dummy;
            while (n--) {
                TreeNode *t = q.front();
                q.pop();
                if (t->left) { q.emplace(t->left); }
                if (t->right) { q.emplace(t->right); }
                // ListNode *cur = new ListNode(t->val);
                tail->next = new ListNode(t->val);
                tail = tail->next;
            }
            res.emplace_back(dummy->next);
        }
        return res;
    }
};
int main() {
    //
    return 0;
}
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();