#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root->val == p->val || root->val == q->val)
		return root;
	bool left = (root->val > p->val) && (root->val > q->val);
	bool right = (root->val < p->val) && (root->val < q->val);
	if (left)
		return lowestCommonAncestor(root->left, p, q);
	else if (right)
		return lowestCommonAncestor(root->right, p, q);
	else
		return root;
}

int main()
{

}