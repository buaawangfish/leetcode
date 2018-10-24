#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBalanced(TreeNode* root) {
	if (!root)
		return true;
	else if (abs(getLen(root->left) - getLen(root->right)) > 1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
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