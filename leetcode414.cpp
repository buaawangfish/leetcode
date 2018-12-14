#include <iostream>
#include <vector>
#include <numeric>

using namespace std;



int thirdMax(vector<int>& nums) {
	long FIRST = LONG_MIN, SECOND = LONG_MIN, THIRD = LONG_MIN;
	for (auto num : nums)
	{
		if (num > FIRST)
		{
			THIRD = SECOND;
			SECOND = FIRST;
			FIRST = num;
		}
		else if (num > SECOND && num < FIRST)
		{
			THIRD = SECOND;
			SECOND = num;
		}
		else if (num > THIRD && num < SECOND)
		{
			THIRD = num;
		}
	}
	


	if (THIRD != LONG_MIN)
		return THIRD;
//	else if (SECOND != INT_MIN)
//		return SECOND;
	else
		return FIRST;
}

int main()
{
	vector<int> input = { 1,2,2,5,3,5};
	cout << thirdMax(input);
	getchar();
	return 0;
}