#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

/*
vector<int> preorder(Node* root) {
	vector<int> result = vector<int>();
	if (!root)
		return result;
	else
		result.push_back(root->val);
	for (auto child : root->children)
	{
		for (auto item : preorder(child))
		{
			result.push_back(item);
		}
	}
	return result;
}
*/

vector<int> preorder(Node* root) {
	stack<Node*> s;
	vector<int> result;
	if (!root) 
		return result;
	else
	{
		s.push(root);
		while (!s.empty())
		{
			Node* curr = s.top();
			s.pop();
			result.push_back(curr->val);
			for (int i = curr->children.size() - 1; i >= 0; i--)
				s.push(curr->children[i]);
		}
	}
	return result;
}

