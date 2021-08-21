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
    vector<vector<int>> res;
    int target;
    void dfs(vector<int> &path, TreeNode *r, int sum) {
        if (r->left == nullptr && r->right == nullptr && sum == target) {
            res.emplace_back(path);
        } else {
            if (r->left) {
                path.emplace_back(r->left->val);
                dfs(path, r->left, sum + r->left->val);
                path.pop_back();
            }
            if (r->right) {
                path.emplace_back(r->right->val);
                dfs(path, r->right, sum + r->right->val);
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        res.clear();
        this->target = target;
        vector<int> path;
        dfs(path, root, 0);
        return res;
    }
};
int main() {
    //
    return 0;
}