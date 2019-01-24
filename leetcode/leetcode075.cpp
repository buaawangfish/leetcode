#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
	if (nums.empty())
		return;
	auto left_it = nums.begin();
	auto right_it = nums.end() - 1;

	while (left_it < right_it)
	{
		if (*left_it > *right_it)
		{
			swap(*left_it, *right_it);
			left_it++;
			right_it--;
		}
		else if (*left_it == 2 && *right_it==2)
			right_it--;
		else if (*left_it==0 && *right_it==0)
		{
			left_it++;
		}
		else
		{
			left_it++;
			right_it--;
		}
	}
	return;
}

int main()
{
	vector<int> input{ 0, 1, 2, 0, 2, 1, 0, 2, 2 };
	sortColors(input);
	getchar();
	return 0;
}