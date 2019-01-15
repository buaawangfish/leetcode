#include <iostream>
#include <vector>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
	if (A.size() < 3)
		return 0;

	int cnt = 0;
	int result = 0;
	int s = A[1] - A[0];
	for (int i = 2; i < A.size(); i++)
	{
		if (A[i] - A[i - 1] == s)
		{
			cnt++;
			result += cnt;
		}
		else
		{
			cnt = 0;
			s = A[i] - A[i - 1];
		}
	}
	return result;
}

int main()
{
	getchar();
	return 0;
}