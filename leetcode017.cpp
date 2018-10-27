#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
map<string, string> DICT {
	{ "2", "abc" },
	{ "3", "def" },
	{ "4", "ghi" },
	{ "5", "jkl" },
	{ "6", "mno" },
	{ "7", "pqrs" },
	{ "8", "tuv" },
	{ "9", "wxyz" }
};


vector<string> letterCombinations(string digits) {
	
	if (digits.empty()) return vector<string>();

	vector<string> result;
	if (digits.size() == 1) {
		string comb = DICT[string(1, digits[0])];
		for (auto letter: comb)
		{
			result.push_back(string(1, letter));
		}
		return result;
	}
	
	string new_string(digits.begin() + 1, digits.end());
	vector<string> temp = letterCombinations(string(digits.begin() + 1, digits.end()));
	for (auto x : temp)
	{
		for (auto head : DICT[string(1, digits[0])])
		{
			result.push_back(head + x);
		}
	}
	return result;
}

int main(){
	vector<string> haha = letterCombinations("0");
	for (auto x : haha)
	{
		cout << x << endl;
	}
	getchar();
	return 0; 
}
