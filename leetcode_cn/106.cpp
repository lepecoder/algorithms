/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    TreeNode *buildTree(vector<int> inorder, vector<int> postorder) {
        if (inorder.empty()) return nullptr;
        TreeNode *root = new TreeNode(postorder.back());

        // 找到根节点在中序遍历的位置
        auto root_idx = find(inorder.begin(), inorder.end(), root->val);
        // 分别构造左右子树的中序和后续遍历
        int left_size = 0;
        // if (inorder.begin() < root_idx) {
        vector<int> inorder_l(inorder.begin(), root_idx);
        left_size = inorder_l.size();
        vector<int> postorder_l(postorder.begin(), postorder.begin() + left_size);
        root->left = buildTree(inorder_l, postorder_l);
        // }
        // if (root_idx + 1 < inorder.end()) {
        vector<int> inorder_r(root_idx + 1, inorder.end());
        vector<int> postorder_r(postorder.begin() + left_size, postorder.end() - 1);
        root->right = buildTree(inorder_r, postorder_r);
        // }
        return root;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) { output.push_back(stoi(item)); }
    return output;
}

string treeNodeToString(TreeNode *root) {
    if (root == nullptr) { return "[]"; }

    string output = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode *ret = Solution().buildTree(inorder, postorder);

    string out = treeNodeToString(ret);
    cout << out << endl;
    return 0;
}