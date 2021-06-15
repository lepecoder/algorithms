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
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        if (root) { q.emplace(root); }
        while (!q.empty()) {
            vector<int> temp_vec;
            int n = q.size();
            while (n--) {
                TreeNode *temp_node = q.front();
                q.pop();
                temp_vec.emplace_back(temp_node->val);
                if (temp_node->left) { q.emplace(temp_node->left); }
                if (temp_node->right) { q.emplace(temp_node->right); }
            }
            res.emplace_back(temp_vec);
        }
        return res;
    }
};
int main() {
    //
    return 0;
}