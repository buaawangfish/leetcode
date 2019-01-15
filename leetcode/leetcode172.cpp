#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trailingZeroes(int n) {
	int five = 0;
	while (n > 0)
	{
		five += n / 5;
		n = n / 5;
	}
	return five;
}

int main()
{
	cout << trailingZeroes(10);
	getchar();
	return 0;
}