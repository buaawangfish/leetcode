#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
	int n = grid.size();
	vector<int> max_in_row(n, 0), max_in_col(n, 0);
	for (int i = 0; i < n; i++)
	{
		max_in_row[i] = *max_element(grid[i].begin(), grid[i].end());
		for (int j = 0; j < n; j++)
			max_in_col[i] = (grid[j][i] > max_in_col[i]) ? grid[j][i] : max_in_col[i];
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			result += (min(max_in_row[i], max_in_col[j]) - grid[i][j]);
	}
	return result;
}

int main()
{
	vector<vector<int>> input{
	{3, 0, 8, 4},
	{2, 4, 5, 7},
	{9, 2, 6, 3},
	{0, 3, 1, 0}
};
	cout << maxIncreaseKeepingSkyline(input);
	getchar();
	return 0;
}