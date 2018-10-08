#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

bool isValid(string s) {
	if (s.empty()) return true;
	map<char, char> table{
		{ '{', '}' },
		{ '[', ']' },
		{ '(', ')' },
	};
	bool flg = false;
	stack<int> temp;
	for (auto ch : s) {
		auto pos = table.find(ch);
		if (pos != table.end()) {
			temp.push(ch);
		}
		else {
			if (temp.empty()) return false;
			char top = temp.top();
			if (table.find(top)->second == ch) temp.pop();
			else return false;
		}
	}
	if (temp.empty()) return true;
	else return false;
}

int main() {
	string input = "{}}";
	cout << isValid(input);

	getchar();
	return 0;
}