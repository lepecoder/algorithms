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
    /**
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    int dep[10000];
    int fa[10000];
    void dfs(TreeNode *r, int deep, int pre) {
        if (r == nullptr) return;
        fa[r->val] = pre;
        dep[r->val] = deep;
        dfs(r->left, deep + 1, r->val);
        dfs(r->right, deep + 1, r->val);
    }
    //     int
    int lowestCommonAncestor(TreeNode *root, int o1, int o2) {
        // write code here
        dfs(root, 1, -1);
        int dp1 = dep[o1], dp2 = dep[o2];
        while (fa[o1] != fa[o2]) {
            if (dep[o1] > dep[o2]) {
                o1 = fa[o1];
            } else {
                o2 = fa[o2];
            }
        }
        if (o1 == o2) return o1;
        return fa[o1];
    }
};
int main() {
    //
    return 0;
}