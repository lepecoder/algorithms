#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> res;
		if (root){
			q.emplace(root);
		}
		int n;
		bool b = false;
		while(!q.empty()){
			n = q.size();
			vector<int> t_vec;
			while(n--){
				TreeNode *t_node = q.front();
				q.pop();
				t_vec.emplace_back(t_node->val);
				if (t_node->left){
					q.emplace(t_node->left);
				}
				if (t_node->right){
					q.emplace(t_node->right);
				}
			}
			if (b){
				reverse(t_vec.begin(), t_vec.end());
			}
			b = !b;
			res.emplace_back(t_vec);
		}
		return res;
    }
};
int main(){



    return 0;
}
