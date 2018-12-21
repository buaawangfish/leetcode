#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
	// 还可以用双指针
	if (numbers.size() < 2) return vector<int>();
	if (numbers.size() == 2) return vector<int>{0, 1};

	for (auto it = numbers.begin(); it != numbers.end() - 1; it++)
	{
		auto left = it + 1;
		auto right = numbers.end() - 1;
		while (left <= right)
		{
			auto mid = left + (right - left) / 2;
			if (*mid == target - *it)
				return vector<int>{static_cast<int>(it - numbers.begin()), static_cast<int>(mid - numbers.begin())};
			else if (*mid > (target - *it))
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
}

int main()
{
	vector<int> input{ 1, 2, 7};
	vector<int> output = twoSum(input, 9);
	cout << output[0] << ' ' << output[1];
	getchar();
	return 0;
}