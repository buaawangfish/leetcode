#include <iostream>
#include <vector>

using namespace std;
/*
int numSquares(int n) {
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (pow(static_cast<int>(sqrt(i)), 2) == i) {
			dp[i] = 1;
			continue;
		}
		else {
			int min_int = INT_MAX;
			for (int j = 1; j <= i/2; j++) {
				min_int = min_int >(dp[j] + dp[i - j]) ? (dp[j] + dp[i - j]) : min_int;
			}
			dp[i] = min_int;
		}
	}
	return *(dp.end() - 1);
}
*/

int numSquares(int n) {
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (pow(static_cast<int>(sqrt(i)), 2) == i) {
			dp[i] = 1;
			continue;
		}
		else {
			int min_int = INT_MAX;
			for (int j = 1; j * j < i; j++) {
				min_int = min_int >(1 + dp[i - j*j]) ? (1 + dp[i - j*j]) : min_int;
			}
			dp[i] = min_int;
		}
	}
	return *(dp.end() - 1);
}


/*
int numSquares(int n) {
	vector<int> dp(n + 1, 0);
	for (int i = 1; i*i < n + 1; i++) dp[i*i] = 1;
	for (int i = 2; i <= n; i++) {
		if (dp[i] == 1) continue;
		else {
			int min_int = INT_MAX;
			for (int j = 1; j <= i/2; j++) {
				min_int = min_int >(dp[j] + dp[i - j]) ? (dp[j] + dp[i - j]) : min_int;
			}
			dp[i] = min_int;
		}
	}
	return *(dp.end() - 1);
}
*/

int main() {
	numSquares(13);
	
	getchar();
	return 0;
}