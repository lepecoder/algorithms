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
    int kthLargest(TreeNode *root, int k) {
        TreeNode *r = root;
        stack<TreeNode *> stk;
        while (r != nullptr || !stk.empty()) {
            while (r) {
                stk.emplace(r);
                r = r->right;
            }
            if (!stk.empty()) {
                r = stk.top();
                stk.pop();
                if ((--k) == 0) { return r->val; }
                r = r->left;
            }
        }
        return -1;
    }
};
int main() {
    // k
    return 0;
}