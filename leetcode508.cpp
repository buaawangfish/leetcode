#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

struct cmp {
	bool operator()(pair<int, int>a, pair<int, int>b)
	{
		return a.second < b.second;
	}
};

int SubTreeSum(TreeNode* root, unordered_map<int, int> &sum_record)
{
	if (!root) return 0;
	else
	{
		int res = SubTreeSum(root->left, sum_record) + SubTreeSum(root->right, sum_record) + root->val;
		sum_record[res]++;
		return res;
	}
}

vector<int> findFrequentTreeSum(TreeNode* root) {
	if (!root)
		return vector<int>();
	unordered_map<int, int> sum_record;
	vector<int> res;
	SubTreeSum(root, sum_record);
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> que;
	for (auto each : sum_record)
		que.push(each);
	int top1_node = que.top().first;
	int top1_freq = que.top().second;
	while (!que.empty() && que.top().second == top1_freq)
	{
		res.push_back(que.top().first);
		que.pop();
	}
	return res;
}



int main()
{
	TreeNode* root = new TreeNode(5);
	TreeNode* layer1_0 = new TreeNode(2);
	TreeNode* layer1_1 = new TreeNode(-5);
	root->left = layer1_0;
	root->right = layer1_1;
	vector<int> out = findFrequentTreeSum(root);
	for (auto x : out)
	{
		cout << x << ' ';
	}
	getchar();
	return 0;
}