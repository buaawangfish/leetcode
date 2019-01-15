#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

void helper(TreeNode* &t1, TreeNode* &t2)
{
	// add t2 to t1
	if (!t2)
		return;
	if (!t1)
	{
		TreeNode* new_node = new TreeNode(t2->val);
		t1 = new_node;
	}
	t1->val += t2->val;
	helper(t1->left, t2->left);
	helper(t1->right, t1->right);
	return;
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	// preorder problem
	if (!t1)
		return t2;
	if (!t2)
		return t1;
	helper(t1, t2);
	return t1;
}

int main()
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t1_layer1_0 = new TreeNode(3);
	TreeNode* t1_layer1_1 = new TreeNode(2);
	t1->left = t1_layer1_0; t1->right = t1_layer1_1;
	t1_layer1_0->left = new TreeNode(5);

	TreeNode* t2 = new TreeNode(2);
	t2->left = new TreeNode(1);
	t2->right = new TreeNode(3);
	t2->left->right = new TreeNode(4);
	t2->right->right = new TreeNode(7);

	TreeNode* result = mergeTrees(t1, t2);
	return 0;
}