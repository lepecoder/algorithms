#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
  public:
    TreeNode *cyclicShiftTree(TreeNode *root, int k) {
        // write code here
        if (root == nullptr) return nullptr;
        TreeNode *res = new TreeNode(root->val);
        queue<TreeNode *> q;
        q.emplace(res);
        queue<TreeNode *> q2;
        q2.emplace(root);
        while (!q2.empty()) {
            int count = q2.size();
            while (count--) {
                TreeNode *t = q2.front();
                q2.pop();
                if (!t->left) q2.emplace(nullptr);
                q2.emplace(t->left);
                if (!t->right) q2.emplace(nullptr);
                q2.emplace(t->right);
            }
            queue<TreeNode *> q3(q2);
            q3.emplace(q3.front());
            q3.pop();
            while (!q.empty() && q3.empty()) {
                TreeNode *t = q.front();
                q.pop();
                t->left = q3.front();
                q3.pop();
                if (q3.empty()) break;
                t->right = q3.front();
                q3.pop();
            }
        }
        return res;
    }
};
int main() {
    //
    return 0;
}