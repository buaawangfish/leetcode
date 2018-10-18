#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePaths(int m, int n) {
	vector< vector<int> > grid(m, vector<int>(n, 1));
	if (m <= 0 || n <= 0) return 0;
	else if (m == 1 || n == 1) return 1;
	else {
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
			}
		}
	}
	for (auto x : grid) {
		for (auto y : x) {
			cout << y << ' ';
		}
		cout << endl;
	}

	return grid[m - 1][n - 1];
}

/*
int uniquePaths(int m, int n) {
	int M = min(m, n) - 1;
	int N = m + n - 2;
	long long int temp = 1;
	long long int num = 1, den = 1;
	for (int i = 1; i <= N; i++)
	{
		temp *= i;
		cout << "i: " << i << " temp: " << temp << endl;
		if (i == N) num *= temp;
		if (i == (N - M) || i == M) den *= temp;
	}
	return num / den;
}
*/
int main() {
	cout << uniquePaths(36 , 7);
	getchar();
	return 0;
}