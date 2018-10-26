#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

bool isSubtree(TreeNode* s, TreeNode* t) {
	if (isSametree(s, t)) return true;
	bool left = (s->left) ? isSubtree(s->left, t) : false;
	bool right = (s->right) ? isSubtree(s->right, t) : false;
	return left || right;
}

bool isSametree(TreeNode*s, TreeNode* t)
{
	if (s == nullptr && t == nullptr)
		return true;
	if (s == nullptr || t == nullptr)
		return false;
	if (s->val == t->val)
		return isSametree(t->left, s->left) && isSametree(t->right, s->right);
	else return false;
}
	

int main()
{
	return 0;
}