#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
	int n = matrix.size();
	vector<int> idx(n * 2 - 1);
	for (size_t i = 0; i < idx.size(); i++)
	{
		if (i < n)
			idx[i] = i + 1;
		else
			idx[i] = n - i % n - 1;
	}
	int size = 1;
	int local = 0;
	for (size_t i = 1; i < idx.size(); i++)
	{
		idx[i] += idx[i - 1];
		if (idx[i] >= k && idx[i - 1] < k)
		{
			size = idx[i] - idx[i - 1];
			local = i;
		}
	}
	vector<int> to_sort(size);
	for (size_t i = 0; i < size; i++)
	{
		if (local > (n-1))
			to_sort[i] = matrix[local - (n-1) + i][n-1 - i];
		else
			to_sort[i] = matrix[i][local - i];
	}
	sort(to_sort.begin(), to_sort.end());
	if (local == 0)
		return to_sort[k - 1];
	else
		return to_sort[k-1-idx[local-1]];
}

int main()
{
	vector<vector<int>> input{
	{1, 2},
	{1, 3}
};
	cout << kthSmallest(input, 2);
	getchar();
	return 0;
}