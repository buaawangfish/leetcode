#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int integerBreak(int n) {
	vector<int> dp(59, 0);
	dp[2] = 1;
	dp[1] = 1;
	for (int i = 3; i <= n; i++) {
		vector<int> temp;
		for (int j = 1; j < i; j++) {
			temp.push_back(max(j * dp[i - j], j * (i-j)));
		}
		dp[i] = *max_element(temp.begin(), temp.end());
	}
	return dp[n];
}

// another solution

/*
int integerBreak(int n) {
	vector<int> result = { 0, 1, 1, 2, 4, 6, 9, 12, 18, 27, 36, 54, 81, 108, 162, 243, 324, 486, 729, 972, 1458, 2187, 2916, 4374, 6561, 8748, 13122, 19683, 26244, 39366, 59049, 78732, 118098, 177147, 236196, 354294, 531441, 708588, 1062882, 1594323, 2125764, 3188646, 4782969, 6377292, 9565938, 14348907, 19131876, 28697814, 43046721, 57395628, 86093442, 129140163, 172186884, 258280326, 387420489, 516560652, 774840978, 1162261467, 1549681956 };
	return result[n];
}
*/

int main() {
	cout << integerBreak(58);
	getchar();
	return 0;
}