#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* trimBST(TreeNode* root, int L, int R) {
	if (!root)
		return nullptr;
	if (L <= root->val && root->val <= R)
	{
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
		return root;
	}
	else if (root->val < L)
	{
		root = trimBST(root->right, L, R);
		return root;
	}
	else if (root->val > R)
	{
		root = trimBST(root->left, L, R);
		return root;
	}
}