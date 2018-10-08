#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
	if (matrix.empty()) return;
	int n = matrix.size();
	int temp;
	int layers = n / 2;
	for (int layer = 0; layer < layers; layer++)
	{
		for (int i = 0; i < n - 1 - layer * 2; i++) // n = 8
		{
			temp = matrix[layer][layer + i];
			matrix[layer][layer + i] = matrix[n - 1 - i - layer][layer];
			matrix[n - 1 - i - layer][layer] = matrix[n - 1 - layer][n - 1 - i - layer];
			matrix[n - 1 - layer][n - i - 1 - layer] = matrix[layer + i][n - 1 - layer];
			matrix[layer + i][n - 1 - layer] = temp;
		}
	}
	return;
}

int main() {
	vector<vector<int>> matrix = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};
	rotate(matrix);
	for (auto x : matrix) {
		for (auto y : x) {
			cout << y << ' ';
		}
		cout << endl;
	}
	getchar();
	return 0;
}