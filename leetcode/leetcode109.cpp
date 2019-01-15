#include <iostream>
#include <vector>

using namespace std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* creatSearchTree(vector<int> arr)
{
	if (arr.empty())
		return nullptr;
	int n = arr.size();
	if (n == 1)
	{
		TreeNode* root = new TreeNode(arr[0]);
		return root;
	}
	vector<int> left_arr(arr.begin(), arr.begin() + n / 2);
	vector<int> right_arr(arr.begin() + n / 2 + 1, arr.end());
	TreeNode* root = new TreeNode(arr[n / 2]);
	root->left = creatSearchTree(left_arr);
	root->right = creatSearchTree(right_arr);
	return root;
}

TreeNode* sortedListToBST(ListNode* head) {
	vector<int> arr;
	while (head)
	{
		arr.push_back(head->val);
		head = head->next;
	}
	return creatSearchTree(arr);
}