#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root) {
	stack<TreeNode*> s;
	if (!root)
		return vector<int>();
	vector<int> result;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* top_node = s.top();
		s.pop();
		result.push_back(top_node->val);
		if (top_node->right)
			s.push(top_node->right);
		if (top_node->left)
			s.push(top_node->left);
	}
	return result;
}

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* layer1 = new TreeNode(2);
	TreeNode* layer2 = new TreeNode(3);
	root->right = layer1;
	layer1->left = layer2;
	vector<int> output = preorderTraversal(root);
	for_each(output.begin(), output.end(), [](int x){cout << x << ' '; });
	getchar();
	return 0;
}