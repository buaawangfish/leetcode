#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
	unordered_map<int, int> hashmap;
	hashmap[nums[0]]++;
	for (int i = 1; i < nums.size(); i++)
	{
		nums[i] += nums[i - 1];
		hashmap[nums[i]]++;
	}
	int res = hashmap[k];
	for (int i = 0; i < nums.size(); i++)
	{
		hashmap[nums[i]]--;
		res += hashmap[k + nums[i]];
	}
	return res;
}

int main()
{
	vector<int> input{ 1 };
	cout << subarraySum(input, 0);
	getchar();
	return 0;
}