#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

int maxDepth(TreeNode* root) {
	if (root == NULL) return 0;
	else return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
	getchar();
	return 0;
}