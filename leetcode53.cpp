#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	vector<int> dp(nums.begin(), nums.end());
	int max = INT_MIN;
	for (int i = 0; i < dp.size(); i++) {
		if (i > 0 && dp[i - 1] > 0) {
			dp[i] = dp[i - 1] + dp[i];
		}
		if (dp[i] > max) max = dp[i];
	}
	return max;
}

int main() {
	vector<int> nums{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << maxSubArray(nums);
	getchar();
	return 0;
}