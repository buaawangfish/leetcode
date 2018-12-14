#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> subsets(vector<int> &nums)
{
	vector<vector<int>> result = vector<vector<int>>();
	if (nums.empty())
	{
		result.push_back(vector<int>());
		return result;
	}

	vector<int> sub_set(nums.begin() + 1, nums.end());
	vector<vector<int>> sub_result = subsets(sub_set);
	for (int j = 0; j < sub_result.size(); j++)
	{
		result.push_back(sub_result[j]);
		sub_result[j].push_back(nums[0]);
		result.push_back(sub_result[j]);
	}
	return result;
}

int main()
{
	vector<int> input = { 1, 2, 3 };
	auto result = subsets(input);
	for (auto x : result)
	{
		for (auto y : x)
		{
			cout << y << ' ';
		}
		cout << endl;
	}
	getchar();
	return 0;
}