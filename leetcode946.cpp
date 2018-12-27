#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	if (pushed.size() != popped.size())
		return false;
	if (pushed.empty())
		return true;
	if (pushed.size() == 1)
		return pushed[0] == popped[0];
	stack<int> sta;
	sta.push(pushed[0]);
	int pushed_idx = 1, popped_idx = 0;

	while (pushed_idx != pushed.size())
	{
		if (sta.empty())
		{
			sta.push(pushed[pushed_idx]);
			pushed_idx++;
		}
		if (sta.top() == popped[popped_idx])
		{
			sta.pop();
			popped_idx++;
		}
		else
		{
			if (pushed_idx == pushed.size())
				return false;
			else
			{
				sta.push(pushed[pushed_idx]);
				pushed_idx++;
			}
		}
	}
	while (!sta.empty())
	{
		int top = sta.top();
		if (popped_idx == popped.size())
			return false;
		if (top == popped[popped_idx])
		{
			sta.pop();
			popped_idx++;
		}
		else
			return false;
	}
	return popped_idx == popped.size();
}

int main()
{
	vector<int> a{ 1, 2, 3, 4, 5 };
	vector<int> b{ 4, 3, 5, 1, 2 };
	validateStackSequences(a, b);
	getchar();
	return 0;
}