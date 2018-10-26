#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

int sumOfLeftLeaves(TreeNode* root) {
	return dfs(root, false);
}

int dfs(TreeNode* root, bool isLeft)
{
	if (!root) return 0;
	if (root->left == NULL && root->right == NULL && isLeft) return root->val;
	else return dfs(root->left, true) + dfs(root->right, false);
}

int main()
{
	return 0;
}