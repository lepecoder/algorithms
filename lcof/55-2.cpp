class Solution {
public:
	unordered_map<TreeNode*,int> mp;
	//int height()
    bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		bool is_left = isBalanced(root->left);	
		bool is_right = isBalanced(root->right);
		int h_left, h_right;
		root->left == nullptr?h_left=0:h_left = mp[root->left];
		root->right == nullptr?h_right=0:h_right=mp[root->right];
		mp[root] = 1+max(h_left, h_right);
		if (is_left == false || is_right==false) return false;
		if (abs(h_left-h_right) <= 1) return true;
		return false;
    }
};
