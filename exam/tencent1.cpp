#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    TreeNode *deleteNodes(TreeNode *root) {
        if (root == nullptr) return root;
        queue<TreeNode *> q;
        q.emplace(root);
        unordered_set<int> st;
        st.emplace(root->val);
        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                auto t = q.front();
                q.pop();
                if (t->left) {
                    if (st.count(t->left->val) > 0) {
                        t->left = nullptr;
                    } else {
                        st.emplace(t->left->val);
                        q.emplace(t->left);
                    }
                }
                if (t->right) {
                    if (st.count(t->right->val) > 0) {
                        t->right = nullptr;
                    } else {
                        st.emplace(t->right->val);
                        q.emplace(t->right);
                    }
                }
            }
        }
        return root;
    }
};
int main() {
    //
    return 0;
}