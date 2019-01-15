#include <iostream>
#include <stack>

using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		_make_stack_empty();
		if (!root)
			return;
		_inOrder(root);
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* top = _stack.top();
		_stack.pop();
		return top->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !_stack.empty();
	}

private:
	stack<TreeNode*> _stack;

	void _make_stack_empty()
	{
		while (!_stack.empty())
			_stack.pop();
		return;
	}

	void _inOrder(TreeNode* root)
	{
		if (!root)
			return;
		_inOrder(root->right);
		_stack.push(root);
		_inOrder(root->left);
		return;
	}
};