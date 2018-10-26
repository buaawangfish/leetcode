#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int diameterOfBinaryTree(TreeNode* root) {
	if (!root || ( (!root->left) && (!root->right) ))
		return 0;
	else if (root->left && root->right)
	{
		int left = getLen(root->left) - 1;
		int right = getLen(root->right) - 1;
		return max(max(left + right + 2, diameterOfBinaryTree(root->left)),
			diameterOfBinaryTree(root->right));
	}
	else
		return (root->left) ? max(diameterOfBinaryTree(root->left), getLen(root->left)) :
		max(diameterOfBinaryTree(root->right), getLen(root->right));
}

int getLen(TreeNode* root)
{
	if (!root)
		return 0;
	else
		return 1 + max(getLen(root->left), getLen(root->right));
}

int main()
{
	return 0;
}