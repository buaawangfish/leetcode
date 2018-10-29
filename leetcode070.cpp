#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
	vector<int> dp(n + 1, 0);
	for (int i = 0; i <= n; i++)
	{
		if (i == 0) dp[i] = 1;
		else if (i == 1) dp[i] = 1;
		else {
			dp[i] = dp[i - 2] + dp[i - 1];
		}
	}
	return dp[n];
}

int main() {
	cout << climbStairs(3);

	getchar();
	return 0;
}
