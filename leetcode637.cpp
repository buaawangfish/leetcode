#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<double> averageOfLevels(TreeNode* root) {
	if (!root) return vector<double>();

	queue<TreeNode*> que;
	vector<double> res;
	que.push(root);
	
	while (!que.empty())
	{
		int len = que.size();
		double curr_avg = 0;
		for (int i = 0; i < len; i++)
		{
			TreeNode* fnt = que.front();
			que.pop();
			curr_avg += fnt->val;
			if (fnt->left) que.push(fnt->left);
			if (fnt->right) que.push(fnt->right);			
		}
		res.push_back(curr_avg / len);
	}
	return res;
}

int main()
{
	return 0;
}