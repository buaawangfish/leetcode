#include <iostream>
#include <string>
#include <vector>

using namespace std;

int titleToNumber(string s) {
	int n = s.size();
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += (result * 25 + int(s[i] - 'A' + 1));
	}
	return result;
}

int main()
{
	cout << titleToNumber("ZY");
	getchar();
	return 0;
}