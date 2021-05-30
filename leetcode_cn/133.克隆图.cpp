/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
  public:
    unordered_map<int, Node *> mp;
    Node *cloneNode(Node *node) {
        if (mp.find(node->val) != mp.end()) return mp[node->val];
        Node *res = new Node(node->val);
        mp[node->val] = res;
        for (Node *nei : node->neighbors) { res->neighbors.emplace_back(cloneNode(nei)); }
        return res;
    }
    Node *cloneGraph(Node *node) {
        // memset(visited, false ,sizeof(visited));
        Node *res = cloneNode(node);
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}