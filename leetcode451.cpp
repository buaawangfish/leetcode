#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(pair<char, int>a, pair<char, int>b)
	{
		if (a.first != b.first) return a.second < b.second;
		else return a.first > b.first;
	}
};

string frequencySort(string s) {
	if (s.empty()) return "";

	unordered_map<char, int> cnt_map;
	for (int i = 0; i < s.size(); i++)
		cnt_map[s[i]] += 1;
	priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> que;
	for (auto each : cnt_map)
		que.push(each);
	string res;
	while (!que.empty())
	{
		for (int i = 0; i < que.top().second; i++){
			res += que.top().first;
		}
		que.pop();
	}
	return res;
}

int main()
{
	cout << frequencySort("ttrree");
	getchar();
	return 0;
}
