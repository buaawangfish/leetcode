#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
	if (nums.empty()) return -1;
	if (nums.size() == 1) return nums[0];
	if (nums.size() == 2) return nums[0] < nums[1] ? nums[0] : nums[1];

	auto left_it = nums.begin();
	auto right_it = nums.end() - 1; 
	while (left_it <= right_it)
	{
		auto mid_it = left_it + (right_it - left_it) / 2;
		 
		if (*left_it > *right_it)
		{
			if (*mid_it < *(mid_it - 1))
				return *mid_it;

			if (*mid_it >= *left_it)
				left_it = mid_it + 1;
			else if (*mid_it < *right_it)
				right_it = mid_it - 1;
		}
		else
			return *left_it;
	}
}

int main()
{
	vector<int> input{ 2,3,4,5,1 };
	cout << findMin(input);
	getchar();
	return 0;
}