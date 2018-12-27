#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

void helper(TreeNode* root, vector<int> &result)
{
	if (!root)
		return;
	helper(root->left, result);
	helper(root->right, result);
	result.push_back(root->val);
	return;
}

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
//	helper(root, result);
	stack<TreeNode*> tree_stack;
	if (!root)
		return result;
	tree_stack.push(root);
	TreeNode* curr = root;
	TreeNode* visited = nullptr;

	while (curr)
	{
		tree_stack.push(curr->left);
		curr = curr->left;
	}

	while (!tree_stack.empty())
	{
		curr = tree_stack.top();
		tree_stack.pop();
		if ((!curr->right) || curr->right == visited)
		{
			result.push_back(curr->val);
			visited = curr;
		}
		else
		{
			tree_stack.push(curr);
			curr = curr->right;
			while (curr)
			{
				tree_stack.push(curr);
				curr = curr->left;
			}
		}
	}
	return result;
}

int main()
{
	getchar();
	return 0;
}