#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& A) {
	if (A.empty()) return A;

	int row = A[0].size();
	int col = A.size();
	vector<vector<int>> res(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			res[i][j] = A[j][i];
	}
	return res;
}

int main()
{
	return 0;
}