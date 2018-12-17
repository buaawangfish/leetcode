#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	if (A.empty()) return A;
	
	for (vector<int> &row : A)
	{
		reverse(row.begin(), row.end());
		for_each(row.begin(), row.end(), [](int& x){x = 1^x; });
	}
	return A;
}

int main()
{
	vector<vector<int>> input{ { 1, 1, 0 }, { 1, 0, 1 }, { 0, 0, 0 } };
	vector<vector<int>> output = flipAndInvertImage(input);
	for (auto row : output)
	{
		for (int col : row)
		{
			cout << col << ' ';
		}
		cout << endl;
	}
	getchar();
	return 0;
}