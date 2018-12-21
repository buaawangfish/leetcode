#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, int& sum)
{
	if (!root)
		return;
	else
	{
		sum += 1;
		helper(root->left, sum);
		helper(root->right, sum);
		return;
	}
}

int countNodes(TreeNode* root) {
	int result = 0;
	helper(root, result);
	return result;
}



int main()
{
	return 0;
}