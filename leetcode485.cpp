#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
	int idx = -1;
	int result = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			result = (i - idx - 1 > result) ? i - idx - 1 : result;
			idx = i;
		}
	}
	return (nums.size() - idx - 1 > result) ? nums.size() - idx - 1 : result;
}

int main()
{
	vector<int> input = { 1,1,1,1,1,1};
	cout << findMaxConsecutiveOnes(input);
	getchar();
	return 0;
}