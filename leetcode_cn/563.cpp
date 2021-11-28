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
    int ans=0;
    int fun(TreeNode* r){
        // 返回子节点和
        if (r==nullptr) return 0;
        int le = fun(r->left);
        int ri = fun(r->right);
        ans += abs(le-ri);
        return le+ri;
    }
    int findTilt(TreeNode* root) {
        fun(root);
        return ans;
    }
};
int main(){
    // 
    return 0;
}