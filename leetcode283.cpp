#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
	int zero_cnt = 0;
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		if (i >= len - zero_cnt) break;
		if (nums[i] == 0)
		{
			zero_cnt++;
			nums.erase(nums.begin() + i);
			i--;
		}
	}
	nums.insert(nums.end(), zero_cnt, 0);
}

int main()
{
	vector<int> input = { 0, 1, 0, 3, 12 };
	moveZeroes(input);
	getchar();
	return 0;
}