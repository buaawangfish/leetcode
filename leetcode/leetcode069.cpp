#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mySqrt(int x) {
	if (x >= 2152032100)
		return 46340;
	if (x == 0)
		return 0;
	else if (x < 4)
		return 1;
	int left = 0;
	int right = 46340;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (mid*mid <= x && (mid + 1)*(mid + 1) > x)
		{
			return mid;
		}
		else if (mid*mid > x)
		{
			right = mid - 1;
			continue;
		}
		else if ((mid + 1)*(mid + 1) <= x)
		{
			left = mid + 1;
		}
	}
}

int main()
{
	cout << mySqrt(2147395600);
	getchar();
	return 0;
}