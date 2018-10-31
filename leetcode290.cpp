#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string str)
{
	if (pattern.empty() || str.empty())
		return false;

	unordered_map<string, string> double_map;
	for (int i = 0; i < pattern.size(); i++)
	{
		int it = str.find(' ');
		if (it == str.npos ^ i == pattern.size() - 1)
			return false;
		string curr_word = (it == str.npos) ? str : string(str.begin(), str.begin() + it);
		string curr_patt = string(pattern.begin() + i, pattern.begin() + i + 1);
		curr_patt[0] -= 32;
		if (double_map.find(curr_patt) == double_map.end())
		{
			if (double_map.find(curr_word) == double_map.end())
			{
				double_map[curr_patt] = curr_word;
				double_map[curr_word] = curr_patt;
			}
			else
				return false;
		}
		else
		{
			if (double_map[curr_patt] != curr_word)
				return false;
		}
		if (it != str.npos)
			str = string(str.begin() + it + 1, str.end());
		else
			return true;
	}
}

int main()
{
	string str("aa aa aa");
	string pattern = "aa";
	cout << wordPattern(pattern, str);
	getchar();
	return 0;
}