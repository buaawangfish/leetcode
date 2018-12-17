#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	if (nums.empty()) 
		return nullptr;
	vector<int>::iterator max_it = max_element(nums.begin(), nums.end());
	TreeNode* root = new TreeNode(*max_it);
	if (!root)
		return root;
	vector<int> left_nums(nums.begin(), max_it);
	vector<int> right_nums(max_it + 1, nums.end());
	root->left = constructMaximumBinaryTree(left_nums);
	root->right = constructMaximumBinaryTree(right_nums);
	return root;
}

int main()
{
	vector<int> input{ 3, 2, 1, 6, 0, 5 };
	TreeNode* result = constructMaximumBinaryTree(input);
	getchar();
	return 0;
}