#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	if (nums.size() <= 2 || nums.back() < 0) return result;
	for (auto it = nums.begin(); it != nums.end() - 2; it++)
	{
		if (*it > 0) break;
		if (it != nums.begin() && (*it == *(it - 1))) continue;
		else
		{
			auto left = it + 1;
			auto right = nums.end() - 1;
			while (left < right)
			{
				if (left >(it + 1) && (*left == *(left - 1))) { 
					left++; continue; 
				}
				if (*left + *right + *it < 0) left++;
				else if (*left + *right + *it > 0) right--;
				else
				{
					vector<int> temp(3);
					temp[0] = *it;
					temp[1] = *left;
					temp[2] = *right;
					result.push_back(temp);
					left++; right--;
				}
			}
		}
	}
	return result;
}

int main()
{
	int input[] = { -4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6 };
	vector<int> input_vec(input, input + 15);
	vector<vector<int> > result = threeSum(input_vec);
	
	for (auto ext : result)
	{
		for (auto in : ext)
		{
			cout << in << ' ';
		}
		cout << endl;
	}
	getchar();
	return 0;
}
