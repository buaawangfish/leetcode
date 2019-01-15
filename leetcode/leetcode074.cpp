#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0)
		return false;
	int idx = 0;
	int left = 0;
	int n = matrix.size() - 1;
	int right = n;
	if (matrix.size() != 1)
	{
		while (left <= right)
		{
			if (target >= matrix[n][0])
			{
				idx = n;
				break;
			}
			int mid = left + (right - left) / 2;

			if (target >= matrix[mid][0] && target < matrix[mid + 1][0])
			{
				idx = mid;
				break;
			}
			if (target < matrix[mid][0])
			{
				right = mid - 1;
				continue;
			}
			if (target >= matrix[mid + 1][0])
			{
				left = mid + 1;
				continue;
			}
		}
	}
	
	left = 0;
	right = matrix[idx].size() - 1;
	while (left <= right)
	{
		if (target < matrix[idx][left] || target > matrix[idx][right])
			return false;
		int mid = left + (right - left) / 2;
		if (matrix[idx][mid] == target)
			return true;
		else if (matrix[idx][mid] > target)
		{
			right = mid - 1;
			continue;
		}
		else if (matrix[idx][mid] < target)
		{
			left = mid + 1;
			continue;
		}
	}
	return false;
}


int main()
{
	vector< vector<int> > input{
		// { 1, 3, 5, 7 },
		// { 10, 11, 16, 20 },
		// { 23, 30, 34, 50 }
		{ 1 }, { 3 }
};

	searchMatrix(input, 3);
	getchar();
	return 0;
}