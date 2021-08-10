#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
  public:
    /**
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return int整型vector<vector<>>
     */
    int sum;
    vector<vector<int>> res;
    void dfs1(vector<int> &path, TreeNode *r, int s) {
        if (r->left == nullptr && r->right == nullptr) {
            if (s == sum) { res.emplace_back(path); }
        } else {
            if (r->left) {
                vector<int> t(path);
                t.emplace_back(r->left->val);
                dfs1(t, r->left, s + r->left->val);
            }
            if (r->right) {
                vector<int> t(path);
                t.emplace_back(r->right->val);
                dfs1(t, r->right, s + r->right->val);
            }
        }
    }
    void dfs(vector<int> &&path, TreeNode *r, int s) {
        if (r->left == nullptr && r->right == nullptr) {
            if (s == sum) res.emplace_back(path);
        } else {
            if (r->left) {
                path.emplace_back(r->left);
                dfs(move(path), r->left, s + r->left->val);
                path.pop_back();
            }
            if (r->right) {
                path.emplace_back(r->right);
                dfs(move(path), r->right, s + r->right->val);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        // write code here
        if (root == nullptr) return res;
        this->sum = sum;
        // vector<int> path;
        // path.emplace_back(root->val);
        dfs(vector<int>{root->val}, root, root->val);
        return res;
    }
};
int main() {
    //
    return 0;
}