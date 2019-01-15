#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minFallingPathSum(vector<vector<int>>& A) {
	if (A.size() == 1)
		return *min_element(A[0].begin(), A[0].end());
	for (int i = 1; i < A.size(); i++)
	{
		for (int j = 0; j < A[0].size(); j++)
		{
			if (j == 0)
				A[i][j] += min(A[i - 1][0], A[i - 1][1]);
			else if (j == A[i].size() - 1)
				A[i][j] += min(A[i - 1][j], A[i - 1][j - 1]);
			else
				A[i][j] += min(A[i - 1][j - 1], min(A[i - 1][j], A[i - 1][j + 1]));
		}
	}
	A.back;
	return *min_element(A.back().begin(), A.back().end());
}

int main()
{
	getchar();
	return 0;
}