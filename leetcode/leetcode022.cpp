#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isStrValid(const string pre_str, const int n)
{
	int len = pre_str.size();
	if (len > n * 2)
		return false;
	int left_cnt = 0;
	int right_cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (pre_str[i] == '(')
			left_cnt++;
		else if (pre_str[i] == ')')
			right_cnt++;
		if (right_cnt > left_cnt || left_cnt > n)
			return false;
	}
	return true;
}

void helper(int n, string pre_str, vector<string> &res)
{
	if (!isStrValid(pre_str, n))
		return;
	if (pre_str.size() == n * 2)
		res.push_back(pre_str);
	helper(n, pre_str + '(', res);
	helper(n, pre_str + ')', res);
	return;
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	helper(n, "", res);
	return res;
}

int main()
{
	vector<string> res = generateParenthesis(3);
	getchar();
	return 0;
}