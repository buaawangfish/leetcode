#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int pathSum(TreeNode* root, int sum) {
	if (!root)
		return 0;
	else
		return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int dfs(TreeNode* root, int sum)
{
	if (!root)
		return 0;
	if (root->val == sum)
		return 1 + dfs(root->left, 0) + dfs(root->right, 0);
	else
		return dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
}


int main()
{
	return 0;
}