#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



void calcSumNumbers(TreeNode* root, int father_val, vector<int>& record)
{
	if (!root) return;
	int res = father_val * 10;
	res += root->val;
	if (!root->left && !root->right)
		record.push_back(res);
	else
	{
		calcSumNumbers(root->left, res, record);
		calcSumNumbers(root->right, res, record);
	}
}

int sumNumbers(TreeNode* root) {
	vector<int> record;
	if (!root) return 0;
	calcSumNumbers(root, 0, record);
	return accumulate(record.begin(), record.end(), 0);
}

int main()
{
	TreeNode* root = new TreeNode(4);
	TreeNode* layer1_0 = new TreeNode(9);
	TreeNode* layer1_1 = new TreeNode(0);
	root->left = layer1_0;
	root->right = layer1_1;
	TreeNode* layer2_0 = new TreeNode(5);
	TreeNode* layer2_1 = new TreeNode(1);
	layer1_0->left = layer2_0;
	layer1_0->right = layer2_1;
	cout << sumNumbers(root);
	getchar();
	return 0;
}