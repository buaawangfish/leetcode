#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int minAddToMakeValid(string S) {
	if (S.empty())
		return 0;
	stack<char> stack_s;
	for (char c : S)
	{
		if (stack_s.empty())
		{
			stack_s.push(c);
			continue;
		}
		char top = stack_s.top();
		if (top == '(' && c == ')')
		{
			stack_s.pop();
			continue;
		}
		stack_s.push(c);
	}
	return stack_s.size();
}

int main()
{
	cout << minAddToMakeValid("()))((");
	getchar();
	return 0;
}