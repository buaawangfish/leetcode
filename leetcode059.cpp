#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	if (n <= 0)
		return vector<vector<int>>();

	vector<vector<int>> result(n, vector<int>(n, 0));
	
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		int size = (n - 2 * i - 1);
		for (int j = 0; j < 4 * size; j++)
		{
			switch (j / size)
			{
			case 0:
				result[i][i + j % size] = 4 * (n - i) * i + 1 + j;
			case 1:
				result[i + j % size][n - i - 1] = 4 * (n - i) * i + 1 + j;
			case 2:
				result[n - i - 1][n - i - 1 - j % size] = 4 * (n - i) * i + 1 + j;
			case 3:
				result[n - i - 1 - j % size][i] = 4 * (n - i) * i + 1 + j;
			default:
				break;
			}
		}
	}
	if (n % 2 == 1)
		result[n / 2][n / 2] = n*n;
	return result;
}

int main()
{
	auto res = generateMatrix(3);
	for (auto y : res)
	{
		for (auto x : y)
		{
			cout << x << ' ';
		}
		cout << endl;
	}
	getchar();
	return 0;
}