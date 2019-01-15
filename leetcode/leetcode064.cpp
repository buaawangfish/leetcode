#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	if (grid.empty())
		return 0;
	int h = grid.size();
	int w = grid[0].size();
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (i == 0)
				grid[i][j] += grid[i][j - 1];
			else if (j == 0)
				grid[i][j] += grid[i - 1][j];
			else
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
		}
	}
	return grid[h - 1][w - 1];
}

int main()
{
	getchar();
	return 0;
}