#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct cmp
{
	bool operator() (pair<int, int>a, pair<int, int>b)
	{
		return a.second < b.second;
	}
};

vector<int> topKFrequent(vector<int>& nums, int k) {
	if (nums.empty())
		return vector<int>();

	vector<int> res;
	unordered_map<int, int> hashmap;
	for (auto num : nums)
		hashmap[num]++;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
	for (auto each : hashmap)
		que.push(each);
	while (k-- && !que.empty())
	{
		res.push_back(que.top().first);
		que.pop();
	}
	return res;
}

int main()
{
	vector<int> input{ 1 };
	vector<int> res = topKFrequent(input, 1);
	for (auto x : res)
	{
		cout << x << ' ';
	}
	getchar();
	return 0;
}