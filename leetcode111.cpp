#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

int minDepth(TreeNode* root) {
	if (!root) return 0;
	else 
	{
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (left == 0) return 1 + right;
		else if (right == 0) return 1 + left;
		else return 1 + min(left, right);	
	}
}

int main()
{

}