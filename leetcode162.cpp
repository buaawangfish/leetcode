#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
	if (nums.empty()) return -1;

	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		bool greater_than_left = (mid > 0) ? (nums[mid] > nums[mid - 1]) : (true);
		bool greater_than_right = (mid < nums.size() - 1) ? (nums[mid] > nums[mid + 1]) : (true);
		if (greater_than_left && greater_than_right)
			return mid;
		else if (greater_than_right)
			right = mid - 1;
		else // if (greater_than_left)
			left = mid + 1;
	}
	return -1;
}

int main()
{
	vector<int> inp{ 2, 1, 2};
	cout << findPeakElement(inp);
	getchar();
	return 0;
}