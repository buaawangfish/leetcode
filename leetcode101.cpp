#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


bool isSymmetric(TreeNode* root) {
	if (root == NULL) return true;
	TreeNode *left_node = root->left, *right_node = root->right;
	if (bool(left_node) ^ bool(right_node)) return false;
	stack<TreeNode*> left_stack, right_stack;
	return isSameTree(left_node, right_node);
}


bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q == NULL) return true;
	if (p==NULL ^ q==NULL) return false;
	if (p->val == q->val) return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
	else return false;
}

int main()
{
	getchar();
	return 0;
}