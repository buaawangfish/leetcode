#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
	if (nums.empty() || (nums.size()*nums[0].size() != r * c)) return nums;
	vector<vector<int>> res(r, vector<int>(c, 0));
	int row = nums.size();
	int col = nums[0].size();
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			res[i][j] = nums[(i*c + j) / col][(i*c + j) % col];
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> input = {
		{1,2},
		{3,4}
	};
	vector<vector<int>> output = matrixReshape(input, 1, 4);
	for (auto x : output)
	{
		for (auto y : x)
		{
			cout << y << ' ';
		}
		cout << endl;
	}
	getchar();
	return 0;
}