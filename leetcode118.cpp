#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	if (numRows == 0) return vector<vector<int>>();
	vector<vector<int>> result;
//	result.push_back(vector<int>(1, 1));
//	result.push_back(vector<int>(2, 1));
	for (int i = 0; i < numRows; i++) {
		result.push_back(vector<int>(i+1, 1));
		for (int j = 1; j <= i/2; j++)
		{
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			result[i][i - j] = result[i][j];
		}
	}
	return result;
}

int main() {

	getchar();
	return 0;
}