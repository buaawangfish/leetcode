#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums) {
	return foo(nums, 0, nums.size());
}

TreeNode* foo(vector<int>&nums, int start, int end)
{
	if (start > end) return NULL;
	int mid = (start + end) / 2;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = foo(nums, start, mid - 1);
	root->right = foo(nums, mid + 1, end);
	return root;
}

int main()
{
	return 0;
}