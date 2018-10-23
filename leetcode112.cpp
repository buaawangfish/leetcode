#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

bool hasPathSum(TreeNode* root, int sum) {
	if (!root) return false;
	if (!(root->left || root->right)) return (sum == root->val);
	else return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main()
{
	getchar();
	return 0;
}