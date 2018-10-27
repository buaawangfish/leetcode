#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs);

int main(){
	string raw_input[3] = {"flower", "fly", ""};
	vector<string> input;
	string out = longestCommonPrefix(input);
	cout << out;
	getchar();
	return 0;
}

string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty()) return "";
	int MIN_LEN = INT_MAX;
	for (auto x : strs){
		if (x.size() < MIN_LEN) MIN_LEN = x.size();
	}
	string result = "";

	for (int i = 0; i < MIN_LEN; i++)
	{
		char letter = strs[0][i];
		for (int j = 0; j < strs.size(); j++)
		{
			if (strs[j][i] != letter) return result;
		}
		result = result + letter;
	}
	return result;
}
