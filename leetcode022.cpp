#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;



vector<string> helper(int n) {
	if (n == 0) return vector<string>();

	vector<string> result;
	vector<string> sub_result = helper(n - 1);
	for (int i = 0; i < sub_result.size(); i++)
	{
		for (int j = 0; j < sub_result[i].size() - 1; j++)
		{
			string sub_sample = sub_result[i];
			string sub_string(sub_result[i].begin() + j, sub_result[i].begin() + j + 2);
			if (sub_string == "()")
			{
				sub_sample.insert(j + 1, "()");
				result.push_back(sub_sample);
			}
		}
	}
	string temp;
	for (int i = 0; i < n; i++)
	{
		temp += "()";
	}
	result.push_back(temp);
	temp = "(";
	for (int i = 0; i < n - 1; i++)
	{
		temp += "()";
	}
	temp += ")";
	result.push_back(temp);
	return result;
}

vector<string> generateParenthesis(int n) {
	vector<string> result = helper(n);
	unordered_set<string> table(result.begin(), result.end());
	return vector<string>(table.begin(), table.end());
}

int main()
{
	vector<string> result = generateParenthesis(3);
	for (auto i : result)
	{
		cout << i << endl;
	}
	getchar();
	return 0;
}