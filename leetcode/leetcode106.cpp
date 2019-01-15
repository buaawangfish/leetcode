#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if (postorder.empty() || inorder.empty() || (postorder.size() != inorder.size()))
		return nullptr;

	if (postorder.size() == 1)
		return new TreeNode(postorder[0]);

	int root_val = *(postorder.end() - 1);
	vector<int>::iterator it = find(inorder.begin(), inorder.end(), root_val);
	if (it == inorder.end())
		return nullptr;
	int left_len = it - inorder.begin();
	int right_len = inorder.end() - it - 1;
	TreeNode* root = new TreeNode(root_val);
	vector<int> left_postorder(postorder.begin(), postorder.begin() + left_len);
	vector<int> right_postorder(postorder.begin() + left_len, postorder.end() - 1);
	vector<int> left_inorder(inorder.begin(), it);
	vector<int> right_inorder(it + 1, inorder.end());
	root->left = buildTree(left_inorder, left_postorder);
	root->right = buildTree(right_inorder, right_postorder);
	return root;
}

int main()
{
	getchar();
	return 0;
}