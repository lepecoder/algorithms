/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
  public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.emplace(root);
        int max_;
        while (!q.empty()) {
            max_ = INT_MIN;
            int count = q.size();
            while (count--) {
                TreeNode *r = q.front();
                q.pop();
                max_ = max(max_, r->val);
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
            res.push_back(max_);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}