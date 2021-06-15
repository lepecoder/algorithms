#include <bits/stdc++.h>
using namespace std;
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
    vector<int> levelOrder(TreeNode *root) {
        vector<int> res;
        queue<TreeNode *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            TreeNode *t_node = q.front();
            res.emplace_back(t_node->val);
            q.pop();
            if (t_node->left) { q.emplace(t_node->left); }
            if (t_node->right) { q.emplace(t_node->right); }
        }
        return res;
    }
};
int main() {
    //
    return 0;
}