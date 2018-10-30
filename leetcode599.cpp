#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>


using namespace std;

struct cmp
{
	bool operator() (pair<int, string>a, pair<int, string>b)
	{
		return a.first > b.first;
	}
};

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
	unordered_map<string, int> map1, map2;
	for (int i = 0; i < list1.size(); i++)
		map1[list1[i]] = i;
	for (int i = 0; i < list2.size(); i++)
	{
		if (map1.find(list2[i]) != map1.end())
			map2[list2[i]] = i+map1[list2[i]];
	}		
	priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> que;
	for (auto each : map2)
		que.push(pair<int, string>{each.second, each.first});
	vector<string> res;
	int idx = que.top().first;
	while (que.top().first == idx)
	{
		res.push_back(que.top().second);
		que.pop();
	}
	return res;
}

int main()
{
	vector<string> Andy{ "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string> Doris{ "KFC", "Shogun", "Burger King" };
	vector<string> output = findRestaurant(Andy, Doris);
	getchar();
	return 0;

}