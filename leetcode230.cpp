#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, int& cnt, int k, TreeNode* &result, bool& isFind)
{
	if (!root)
		return;
	helper(root->left, cnt, k, result, isFind);
	if (cnt == k)
	{
		result = root;
		isFind = true;
	}
	cnt++;
	if (!isFind)
		helper(root->right, cnt, k, result, isFind);
}

int kthSmallest(TreeNode* root, int k) {
	if (!root)
		return -1;
	int cnt = 1;
	TreeNode* result = root;
	bool isFind = false;
	helper(root, cnt, k, result, isFind);
	return result->val;	
}



int main()
{
	getchar();
	return 0;
}