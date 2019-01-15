#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
	if (pre.empty() || post.empty() || (pre.size() != post.size()))
		return nullptr;
	if (pre.size() == 1)
		return new TreeNode(pre[0]);
	
	int root_val = pre[0];
	int left_val = pre[1];
	auto it = find(post.begin(), post.end(), left_val);
	
	int left_len = it - post.begin();
	int right_len = post.end() - 1 - it;
	vector<int> left_pre(pre.begin() + 1, pre.begin() + left_len + 1);
	vector<int> right_pre(pre.begin() + left_len + 1, pre.end());
	vector<int> left_post(post.begin(), it);
	vector<int> right_post(it, post.end() - 1);
	TreeNode* root = new TreeNode(root_val);
	root->left = constructFromPrePost(left_pre, left_post);
	root->right = constructFromPrePost(right_pre, right_post);
	return root;
}

int main()
{

}