#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
	if (p.empty()) return s.empty();
	if (p.size() == 1) {
		if (s.size() == 1 && (p[0] == '.' || p[0] == s[0])) return true;
		else return false;
	}
	else if (p[1] == '*') {
		while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2))) return true;
			else s = s.substr(1);
		}
		return isMatch(s, p.substr(2));
	}
	else return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	 // else return (s.empty() == p.empty() || (s.empty() && p[0] == '.')) && isMatch(s.substr(1), p.substr(1));
}

int main() {
	string s = "a";
	string p = ".*..a*";
	p[0] = 'd';
	cout << p;
	getchar();
	return 0;
}