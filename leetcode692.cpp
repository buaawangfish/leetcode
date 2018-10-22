#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
	bool operator()(pair<int, string>a, pair<int, string>b)
	{
		if (a.first == b.first)
		{
			return a.second < b.second;
		}
		else return a.first > b.first;
	}
};

vector<string> topKFrequent(vector<string>& words, int k) {
	if (words.empty()) return vector<string>();
	unordered_map<string, int> hashmap;
	for (int i = 0; i < words.size(); i++)
		hashmap[words[i]]++;
	vector<string> result();
	
	priority_queue < pair<int, string>, vector<pair<int, string>>, cmp> heap;
	for (auto x : hashmap)
	{
		pair<int, string> temp;
		temp.first = x.second;
		temp.second = x.first;
		heap.push(temp);
	}
	
	for (int i = 0; i < k; i++)
	{
		result.push_back(heap.top().second);
		heap.pop();
	}
	
	return result;
}



int main()
{
	vector<string> input = { "i", "love", "leetcode", "love", "coding" };
	vector<string> output = topKFrequent(input, 2);
	
	getchar();
	return 0;
}