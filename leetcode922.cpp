#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
	if (A.empty())
		return A;
	int n = A.size();
	vector<int> result(n);
	for (int i = 0, j = n - 1; i < n - 1, j > 0;)
	{
		if (A[i] % 2 == 1 && A[j] % 2 == 0)
		{
			result[j] = A[i];
			result[i] = A[j];
			// swap(A[i], A[j]);
			i += 2;
			j -= 2;
		}
		else if (A[i] % 2 == 1)
		{
			result[i] = A[i];
			j -= 2;
		}
		else if (A[j] % 2 == 0)
		{
			result[j] = A[j];
			i += 2;
		}
		else
		{
			result[j] = A[j];
			result[i] = A[i];
			i += 2;
			j -= 2;
		}
	}
	return result;
}

int main()
{
	vector<int> input{ 2, 0, 3, 4, 1, 3 };
	vector<int> result = sortArrayByParityII(input);
	getchar();
	return 0;
}