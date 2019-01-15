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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.empty() || inorder.empty() || (preorder.size() != inorder.size()))
		return nullptr;

	if (preorder.size() == 1)
		return new TreeNode(preorder[0]);

	int root_val = preorder[0];
	vector<int>::iterator it = find(inorder.begin(), inorder.end(), root_val);
	if (it == inorder.end())
		return nullptr;
	int left_len = it - inorder.begin();
	int right_len = inorder.end() - it - 1;
	TreeNode* root = new TreeNode(root_val);
	vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + left_len + 1);
	vector<int> right_preorder(preorder.begin() + left_len + 1, preorder.end());
	vector<int> left_inorder(inorder.begin(), it);
	vector<int> right_inorder(it + 1, inorder.end());
	root->left = buildTree(left_preorder, left_inorder);
	root->right = buildTree(right_preorder, right_inorder);
	return root;	
}

int main()
{
	getchar();
	return 0;
}