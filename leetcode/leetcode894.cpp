#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> allPossibleFBT(int N) {
	if (N % 2 == 0)
		return vector<TreeNode*>();
	vector<TreeNode*> result;
	if (N == 1)
	{
		TreeNode* new_node = new TreeNode(0);
		result.push_back(new_node);
		return result;
	}
	int n = N;
	for (int i = 1; i < N; i+=2)
	{
		vector<TreeNode*> left_trees = allPossibleFBT(i);
		vector<TreeNode*> right_trees = allPossibleFBT(N - 1 - i);
		for (auto left : left_trees)
		{
			for (auto right : right_trees)
			{
				TreeNode* new_root = new TreeNode(0);
				new_root->left = left;
				new_root->right = right;
				result.push_back(new_root);
			}
		}
	}
	return result;
}

int main()
{
	vector<TreeNode*> result = allPossibleFBT(3);
	getchar();
	return 0;
}