#include <iostream>
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

vector<int> rightSideView(TreeNode* root) {
	if (!root) return vector<int>();

	vector<int> result;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty())
	{
		result.push_back(que.back()->val);
		int len = que.size();
		for (int i = 0; i < len; i++)
		{
			TreeNode* top_node = que.front();
			if (top_node->left) que.push(top_node->left);
			if (top_node->right) que.push(top_node->right);
			que.pop();
		}
	}
	return result;
}

int main()
{
	queue<TreeNode*> que;
	que.push(nullptr);
	return 0;
}