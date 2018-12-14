#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
	bool ifEnd = false;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == i + 1)
			continue;

		int flag = i;
		int idx = nums[i] - 1;
		ifEnd = false;
		for (int j = 0; j <= nums.size(); j++)
		{
			int next_idx = nums[idx] - 1;
			if (nums[idx] - 1 == idx)
				return idx + 1;
			if (nums[idx] == nums[flag])
			{
				ifEnd = true;
				break;
			}
			idx = next_idx;
		}
		if (ifEnd) return nums[i];
	}
}

int main()
{
	cout << findDuplicate(vector<int>{3,4,2,2});
	getchar();
	return 0;
}