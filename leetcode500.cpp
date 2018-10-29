#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

vector<string> findWords(vector<string>& words) {
	if (words.empty()) return vector<string>();

	unordered_set<char> set1, set2, set3;
	for (char x : "qwertyuiopQWERTYUIOP")
		set1.insert(x);
	for (char x : "asdfghjklASDFGHJKL")
		set2.insert(x);
	for (char x : "zxcvbnmZXCVBNM")
		set3.insert(x);
	vector<unordered_set<char>> set_all{ set1, set2, set3 };
	vector<string> res;
	for (auto word : words)
	{
		if (word.size() == 1)
		{
			res.push_back(word);
			continue;
		}
		char keychar = word[0];
		int loc;
		for (int i = 0; i < 3; i++)
		{
			if (find(set_all[i].begin(), set_all[i].end(), keychar) != set_all[i].end())
			{
				loc = i;
				break;
			}
		}
		for (int i = 1; i < word.size(); i++)
		{
			if (find(set_all[loc].begin(), set_all[loc].end(), word[i]) == set_all[loc].end())
				break;
			else if (i == word.size() - 1)
				res.push_back(word);
		}
	}

	return res;
}

int main()
{
	vector<string> input{ "Hello", "Alaska", "Dad", "Peace" };
	vector<string> res = findWords(input);
	for (auto a : res)
	{
		cout << a << endl;
	}
	getchar();
	return 0;
}