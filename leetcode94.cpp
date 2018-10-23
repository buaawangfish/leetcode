#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

vector<int> inorderTraversal(TreeNode* root) {
	stack<TreeNode*> s;
	vector<int>result;
	while (root || !s.empty())
	{
		while (!root)
		{
			s.push(root);
			root = root->left;
		}
		if (s.empty())
		{
			root = s.top();
			result.push_back(root->val);
			root = root->right;
			s.pop();
		}
	}
	return result;
}

int main()
{
	getchar();
	return 0;
}