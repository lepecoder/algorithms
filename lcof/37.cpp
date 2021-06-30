#include <queue>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        // 比如用层次遍历
        TreeNode *r = root;
        string res = "";
        queue<TreeNode *> q;
        if (r) q.emplace(r);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode *t_node = q.front();
                if (t_node == nullptr) {
                    res += ("nullptr");
                } else {
                    res += (to_string(t_node->val));
                    res += (",");
                    q.emplace(t_node->left);
                    q.emplace(t_node->right);
                }
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        // 反序列化
        vector<string> v_data;
        string str = "";
        for (char c : data) {
            if (c == ',') {
                v_data.emplace_back(str);
                str.clear();
            } else {
                str.push_back(c);
            }
        }
        queue<TreeNode *> q;
        TreeNode *res;
        if (v_data.size() > 0) {
            res = new TreeNode(stoi(v_data[0]));
        } else {
            return nullptr;
        }
        q.emplace(res);
        int k = 1;
        while (k < v_data.size()) {
            TreeNode *cur = q.front();
            if (v_data[k] == "nullptr") {
                cur->left = nullptr;
            } else {
                TreeNode *leftnode = new TreeNode(stoi(v_data[k]));
                cur->left = leftnode;
            }
            ++k;
            if (v_data[k] == "nullptr") {
                cur->right = nullptr;
            } else {
                TreeNode *rightnode = new TreeNode(stoi(v_data[k]));
                cur->right = rightnode;
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
