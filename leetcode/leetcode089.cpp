#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> grayCode(int n) {
	if (n == 0)
		return vector<int>{0};
	if (n == 1)
		return vector<int>{0, 1};
	else
	{
		vector<int> result;
		vector<int> sub_grayCode = grayCode(n - 1);
		vector<int> new_grayCode(sub_grayCode.begin(), sub_grayCode.end());
		for_each(new_grayCode.begin(), new_grayCode.end(), [n](int &ele){ele += 2 << (n-2); });
		sub_grayCode.insert(sub_grayCode.end(), new_grayCode.rbegin(), new_grayCode.rend());
		return sub_grayCode;
	}
}

int main()
{
	vector<int> result = grayCode(3);
	getchar();
	return 0;
}