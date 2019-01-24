#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> helper(int begin, int n, int k)
{
	vector<vector<int>> res;

	if (begin == n)
	{
		if (k != 1)
			return res;
		else
		{
			res.push_back(vector<int>{begin});
			return res;
		}
	}
	else if (begin > n)
		return res;


	if (k == 1)
	{
		for (int i = begin; i <= n; i++)
		{
			res.push_back(vector<int>{i});
		}
		return res;
	}

	if (k > 1)
	{
		for (int i = begin; i < n; i++)
		{
			vector<vector<int>> sub_combine = helper(i + 1, n, k - 1);
			for_each(sub_combine.begin(), sub_combine.end(), [i](vector<int> &curr)
			{
				curr.insert(curr.begin(), i);
			});
			res.insert(res.end(), sub_combine.begin(), sub_combine.end());
		}
		return res;
	}

}

vector<vector<int>> combine(int n, int k) {
	return helper(1, n, k);
}



int main()
{
	auto result = combine(4, 2);
	for (auto each : result)
	{
		for (auto x : each)
			cout << x << ' ';
		cout << endl;
	}
	getchar();
	return 0;
}