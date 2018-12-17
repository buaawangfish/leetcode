#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& A) {
	if (A.size() < 3)
		return -1;
	if (A.size() == 3)
		return 1;
	auto left_it = A.begin();
	auto right_it = A.end() - 1;
	while (left_it <= right_it)
	{
		auto mid_it = left_it + (right_it - left_it) / 2;
		int mid = mid_it - A.begin();
		int left = left_it - A.begin();
		int right = right_it - A.begin();
		if ((*mid_it > *(mid_it - 1)) && (*mid_it > *(mid_it + 1)))
			return mid_it - A.begin();
		else if (*mid_it > *(mid_it - 1))
			left_it = mid_it + 1;
		else if (*mid_it > *(mid_it + 1))
			right_it = mid_it - 1;
	}
}

int main()
{
	vector<int> input{ 0, 1, 2, 3, 4, 5, 6, 7, 6 };
	cout << peakIndexInMountainArray(input);
	getchar();
	return 0;
}