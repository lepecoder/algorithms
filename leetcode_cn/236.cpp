/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    bool isintree(TreeNode *r, TreeNode *p, TreeNode *q) {
        if (!r) return false;
        if (r->val == p->val || r->val == q->val) return true;
        return isintree(r->left, p, q) || isintree(r->right, p, q);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        bool b_left = isintree(root->left, p, q);
        bool b_right = isintree(root->right, p, q);
        // bool b_root = isintree(root, p, q);
        bool b_root = root->val == p->val || root->val == q->val;
        if (b_left && b_right) return root;
        if (b_left && b_root) return root;
        if (b_right && b_root) return root;
        if (b_left) return lowestCommonAncestor(root->left, p, q);
        if (b_right) return lowestCommonAncestor(root->right, p, q);
        return nullptr;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(), input.end());
}

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) { return nullptr; }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) { break; }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) { break; }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) { return stoi(input); }

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
    string line = "[3,5,1,6,2,0,8,null,null,7,4]";
    TreeNode *root = stringToTreeNode(line);
    // int p = stringToInteger(line);
    TreeNode *p = root->left;
    // int q = stringToInteger(line);
    TreeNode *q = root->left->right;
    TreeNode *ret = Solution().lowestCommonAncestor(root, p, q);
    cout << ret->val << endl;
    return 0;
}